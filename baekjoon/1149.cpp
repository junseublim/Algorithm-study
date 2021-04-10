#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
int price[1000][3];
int dp[1000][3];
int colored[1000];
int n;
int color(int i) {
    if (i == n) {
        return 0;
    }
    int &ret = dp[i][colored[i-1]];
    if (ret != -1) return ret;
    ret = 987654321;
    for (int j =0; j<3; j++) {
        if (colored[i-1] != j) {
            colored[i] = j;
            ret = min(price[i][j] + color(i+1), ret);
        }
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    memset(colored, -1, sizeof(colored));
    memset(dp, -1, sizeof(dp));
    for (int i =0; i<n; i++) {
        int r,g,b;
        cin>>r>>g>>b;
        price[i][0] = r;
        price[i][1] = g;
        price[i][2] = b;
    }
    int ret = 987654321;
    for (int j =0; j<3; j++) {
        colored[0] = j;
        ret = min(ret,price[0][j] + color(1));
    }
    cout<<ret<<"\n";
}