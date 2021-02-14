#include <bits/stdc++.h>

using namespace std;
const int MAX = 1000000000;
int n,m;
vector<int> tree;
int sz;
int get(int location) {
    if (location >= tree.size()) return MAX;
    if (tree[location] == MAX) {
        tree[location] = min(get(location*2), get(location*2+1));
        return tree[location];
    }
    else return tree[location];
}

int getMin(int a,int b) {
    a += sz;
    b += sz;
    int minimum = MAX;
    while( a<= b) {
        if (a % 2 == 1) minimum = min(minimum, tree[a++]);
        if (b % 2 == 0) minimum = min(minimum, tree[b--]);
        b/=2;
        a/=2;
    }
    return minimum;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    sz = pow(2, ceil(log2(n)));
    tree.assign(sz*2, MAX);
    for (int i=0; i<n; i++) {
        cin>>tree[sz+i];
    }
    get(1);
    for (int i =0; i<m; i++) {
        int a,b;
        cin>>a>>b;
        cout<<getMin(--a,--b)<<"\n";
    }
}