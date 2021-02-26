#include<bits/stdc++.h>

using namespace std;
int dp[101][101];
int comb(int c,int r) {
    if (dp[c][r] != 0) return dp[c][r];
}

int main() {
    dp[1][1] = 1;
    dp[1][0] = 1;

    int n;
    cin>>n;
    for (int i=2; i<=n; i++) {
        for (int j=0; j<=n; j++) {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    cout<<dp[n][4]<<endl;

}