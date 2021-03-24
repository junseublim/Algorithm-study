#include <bits/stdc++.h>

using namespace std;
vector<long long> segTree;
int n,m;

long long getSum(int s, int e, int left, int right, int idx) {
    if (left > e || right < s) return 0;

    if (left >= s && e >= right) {
        return segTree[idx];
    }
    int mid = (left + right)/2;
    return getSum(s,e,left,mid, idx*2) + getSum(s,e,mid+1, right, idx*2+1);
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;    
    int x = ceil(log2(n));
    int pow2x = pow(2,x);
    segTree.assign(pow2x*2, 0);
    for (int i = 0; i<m; i++) {
        int a,b,c;
        cin>>a>>b>>c;
        if (a == 0){
            if (b>c) {
                swap(b,c);
            }
            cout<<getSum(b,c,1,pow2x, 1)<<"\n";
        }
        else {
            int idx = pow2x+b-1;
            long long diff = c-segTree[idx];
            segTree[idx] = c;
            idx /=2;
            while (idx >=1) {
                segTree[idx] += diff;
                idx /=2;
            }
        }
    }
}