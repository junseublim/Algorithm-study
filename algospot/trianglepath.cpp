#include <bits/stdc++.h>

using namespace std;
int tri[100][100];
int ans[100][100];
int c;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c;
    int n;
    for (int i =0; i<c; i++) {
        cin>>n;
        int maxi = 0;
        for (int i =0; i<100; i++) {
            memset(ans[i], 0, sizeof(ans[i]));
        }
        for (int i=0;i<n;i++) {
            for (int j=0; j<=i; j++) {
                cin>>tri[i][j];
            }
        }
        ans[0][0] = tri[0][0];
        for (int i=0;i<n;i++) {
            for (int j=0; j<=i; j++) {
                if (i == n-1) {
                    maxi = max(maxi, ans[i][j]);
                    continue;
                }
                if (ans[i][j] + tri[i+1][j] > ans[i+1][j]) ans[i+1][j] = ans[i][j] + tri[i+1][j];
                if (ans[i][j] + tri[i+1][j+1] > ans[i+1][j+1]) ans[i+1][j+1] = ans[i][j] + tri[i+1][j+1];
                
            }
        }
        cout<<maxi<<"\n";
    }
}