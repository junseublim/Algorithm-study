#include <bits/stdc++.h>

using namespace std;
int farm[50][50];
int cnt = 0;
int n,m,k;
int my[] = {0,0,1,-1};
int mx[] = {1,-1,0,0};
int visited[50][50];
void dfs(int y, int x) {
    if (visited[y][x]) return;
    visited[y][x] = 1;
    for (int i =0; i<4; i++) {
        if (y+my[i] >=0 && y+ my[i] <n&& x+mx[i]<m && x+mx[i] >=0) {
            if (farm[y+my[i]][x+mx[i]] == 0) continue;
            dfs(y+my[i], x+mx[i]);
        }
    }
}

int main() {
    int T;
    cin>>T;
    for (int t =0; t< T; t++) {
        memset(farm, 0, sizeof(farm));
        memset(visited, 0, sizeof(visited));
        cin>>n>>m>>k;
        for (int i = 0; i<k;i ++) {
            int a,b;
            cin>>a>>b;
            farm[a][b] = 1;
        }
        for (int i =0; i<n; i++ ) {
            for (int j =0; j<m; j++) {
                if (farm[i][j] == 1 && !visited[i][j]) {
                    cnt++;
                    dfs(i,j);
                }
            }
        }
        cout<<cnt<<endl;
        cnt = 0;
        
    }
}