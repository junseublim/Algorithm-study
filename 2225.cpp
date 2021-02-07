#include <bits/stdc++.h>

using namespace std;
long long dp[201][201];
int main() {
    for (int i = 0; i<=200;i++) {
        dp[1][i]= 1;
    }
    int a,b;
    cin>>a>>b;
    for (int i=2; i<=b; i++) {
        for (int j= 0; j<=a; j++) {
            if (j == 0) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
                dp[i][j] %= 1000000000;
            }
        }
    }

    cout<<dp[b][a]<<endl;
}