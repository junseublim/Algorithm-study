#include <bits/stdc++.h>

using namespace std;
long long dp[5001];

long long get(int n) {
    if (n == 0) return 1;
    if (dp[n] >= 0) return dp[n];
    dp[n] = 0;
    for (int i =2; i<=n; i+=2) {
        dp[n] += get(i-2) * get(n-i);
        dp[n] %= 1000000007;
    }
    return dp[n];
}

int main() {
    int T;
    cin>>T;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dp, -1, sizeof(dp));
    for (int t= 0; t<T;t++) {
        
        int n;
        cin>>n;
        if (n%2 == 1){
            cout<<0<<"\n";
            continue;
        }

        cout<<get(n)<<"\n";
    }
}