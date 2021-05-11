#include <bits/stdc++.h>

using namespace std;
int n,m;
int world[300][300];
int rm[300][300];
int visited[300][300];
int dy[] = {0,0,-1,1};
int dx[] = {-1,1,0,0};
void melt() {
    memset(rm, 0, sizeof(rm));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m;j++) {
            int cnt = 0;
            for (int k=0; k<4; k++) {
                if (dy[k]+i >= n || dy[k]+i <0 || dx[k]+j >=m || dx[k]+j < 0) continue;
                if (world[dy[k]+i][dx[k]+j] != 0) continue;
                cnt++;
            }
            rm[i][j] = cnt;
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m;j++) {
            world[i][j] -= rm[i][j];
            if (world[i][j] < 0) world[i][j] = 0;
        }
    }
}

void dfs(int y, int x) {
    if (visited[y][x]) return;
    visited[y][x] = 1;
    for (int i =0; i<4; i++) {
        if (dy[i]+y <0 || dy[i]+y >=n || dx[i]+x <0 || dx[i]+x >= m) continue;
        if (world[dy[i]+y][dx[i]+x] != 0) dfs(dy[i]+y, dx[i]+x);
    }
    return;
}

int check() {
    int cnt = 0;
    memset(visited,0, sizeof(visited));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m;j++) {
            if (world[i][j] != 0 && visited[i][j] == 0) {
                cnt++;
                dfs(i,j);
            }
        }
    }
    return cnt;
}
int main() {
    cin>>n>>m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m;j++) {
            cin>>world[i][j];
        }
    }
    int year = 0;
    while(true) {
        int checked = check();
        //cout<<year<<" "<<checked<<endl;
        if (checked >= 2) {
            break;
        }
        else if (checked == 0) {
            year = 0;
            break;
        }
        melt();
        year++;
    }
    cout<<year<<endl;
}