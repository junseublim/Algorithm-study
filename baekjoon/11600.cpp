#include <bits/stdc++.h>

using namespace std;
int n,m;
int grid[1025][1025];
int ans[1025][1025];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;

    for (int i =1; i<=n; i++) {
        for (int j =1; j<=n; j++) {
            cin>>grid[i][j];
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            ans[i][j] = ans[i-1][j] + ans[i][j-1] +grid[i][j] - ans[i-1][j-1];
        }
    }
    for (int i =0; i<m; i++) {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int temp = ans[x2][y2];
        temp -= ans[x1-1][y2];
        temp -= ans[x2][y1-1];
        temp += ans[x1-1][y1-1];
        cout<<temp<<"\n";
    }
}