#include <bits/stdc++.h>

using namespace std;
int graph[100][100];
int visited[100][100];
int cnt; 
int maxCnt = 0;
int n;
int my[] = {0,0,-1,1};
int mx[] = {-1,1,0,0};


void dfs(int y, int x, int r) {
    if (visited[y][x]) return;
    visited[y][x] = 1;
    for (int i =0; i<4; i++) {
        if (y+my[i] >= 0 && y+my[i] <n && x+mx[i] >=0 && x+mx[i] < n) {
            if (graph[y+my[i]][x+mx[i]] < r) continue;
            dfs(y+my[i], x+mx[i], r);
        }
    }

}

int main() {

    cin>>n;
    for (int i =0; i<n; i++) {
        for (int j=0; j<n;j++) {
            cin>>graph[i][j];
        }
    }
    for (int i=1; i<=100; i++) {
        memset(visited, 0, sizeof(visited));
        cnt = 0;
        for (int j =0; j< n; j++) {
            for (int k =0; k<n; k++) {
                if (!visited[j][k] && graph[j][k] >= i){
                    cnt++;
                    dfs(j,k,i);
                }
            }
        }
        maxCnt = max(cnt, maxCnt);
    }
    cout<<maxCnt<<endl;
}