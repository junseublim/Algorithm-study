#include <bits/stdc++.h>

using namespace std;

int n, m;
int nm [1001][1001];
int ans [1001][1001];
int maximum = 0;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i = 1; i<=n; i++) {
        for (int j=1; j<=m;j++) {
            char c;
            cin>>c;
            nm[i][j] = (c-'0');
        }
    }
    for (int i = 1; i<=n; i++) {
        for (int j=1; j<=m;j++) {
            if (nm[i][j] == 0) {
                ans[i][j] = 0;
            }else {
                ans[i][j] = min(ans[i][j-1], ans[i-1][j]);
                ans[i][j] = min(ans[i][j], ans[i-1][j-1]) +1;
            if (ans[i][j] > maximum) maximum = ans[i][j];
            }
           
        }
    }
    // for (int i = 1; i<=n; i++) {
    //     for (int j=1; j<=m;j++) {
    //        cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout<<maximum*maximum<<"\n";
}