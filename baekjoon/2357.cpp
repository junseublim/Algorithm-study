#include <bits/stdc++.h>

using namespace std;
const int MAX = 1000000000;
int n,m;
vector<int> tree1, tree2;
int sz;
int getMinTree(int location) {
    if (location >= tree1.size()) return MAX;
    if (tree1[location] == MAX) {
        tree1[location] = min(getMinTree(location*2), getMinTree(location*2+1));
        return tree1[location];
    }
    else return tree1[location];
}
int getMaxTree(int location) {
    if (location >= tree2.size()) return 0;
    if (tree2[location] == 0) {
        tree2[location] = max(getMaxTree(location*2), getMaxTree(location*2+1));
        return tree2[location];
    }
    else return tree2[location];
}

int getMin(int a,int b) {
    a += sz;
    b += sz;
    int minimum = MAX;
    while( a<= b) {
        if (a % 2 == 1) minimum = min(minimum, tree1[a++]);
        if (b % 2 == 0) minimum = min(minimum, tree1[b--]);
        b/=2;
        a/=2;
    }
    return minimum;

}

int getMax(int a,int b) {
    a += sz;
    b += sz;
    int maximum = 0;
    while( a<= b) {
        if (a % 2 == 1) maximum = max(maximum, tree2[a++]);
        if (b % 2 == 0) maximum = max(maximum, tree2[b--]);
        b/=2;
        a/=2;
    }
    return maximum;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    sz = pow(2, ceil(log2(n)));
    tree1.assign(sz*2, MAX);
    tree2.assign(sz*2, 0);
    for (int i=0; i<n; i++) {
        cin>>tree1[sz+i];
        tree2[sz+i] = tree1[sz+i];
    }
    getMinTree(1);
    getMaxTree(1);
    for (int i =0; i<m; i++) {
        int a,b;
        cin>>a>>b;
        cout<<getMin(--a,--b)<<" "<<getMax(a,b)<<"\n";
    }
}