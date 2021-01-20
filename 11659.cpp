#include <bits/stdc++.h>

using namespace std;
int n,m;
int nums[100001];
int ans[100001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    nums[0] = 0;
    ans[0] = 0;
    for (int i=1; i<=n; i++) {
        cin>>nums[i];
    }
    for (int i=1; i<=n; i++) {
        ans[i] = ans[i-1] + nums[i]; 
    }

    for (int i =0; i<m; i++) {
        int a,b;
        
        cin>>a>>b;
        cout<<ans[b]-ans[a-1]<<"\n";
    }
}