#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
    vector<int> W(n+1, 0);
    vector<int> V(n+1, 0);
    vector<vector<int> > dp(n+1, vector<int>(k+1));
    for (int i=1; i<=n;i++) {
        int w, v;
        cin>>w>>v;
        W[i] = w;
        V[i] = v;
    }
    for (int i=1; i<=n;i++) {
        for (int j=1; j<=k;j++) {
            if (W[i] <= j) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-W[i]]+V[i]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    // for (int i=1; i<=n;i++) {
    //     for (int j=1; j<=k; j++) {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dp[n][k]<<endl;
}