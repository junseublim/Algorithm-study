#include <bits/stdc++.h>

using namespace std;
int cnt = 0;
int n;
int dp[12];
void go(int x) {
    if (x > 11) {
        return;
    }
    dp[x]++;
    for (int i = 1; i<=3; i++) {
        go(x+i);
    }
}

int main() {
    int t;
    cin>>t;
    memset(dp, 0, sizeof(dp));
    go(0);
    while(t--) {
        cnt = 0;
        cin>>n;
        cout<<dp[n]<<endl;

    }
}