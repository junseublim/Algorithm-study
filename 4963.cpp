#include <bits/stdc++.h>

using namespace std;
vector<vector<int> > world;
vector<vector<int> > visited;
int my[] = {0,0,-1,-1,-1,1,1,1};
int mx[] = {-1,1,-1,0,1,-1,0,1};
int cnt;
int w,h;
void dfs(int y,int x) {
    if (visited[y][x] ) return;
    visited[y][x] = true;
    for (int i=0; i<8; i++) {
        if (y+my[i] >= 0 && y+my[i] <h && x+mx[i] >= 0 && x+mx[i] < w) {
            if (world[y+my[i]][x+mx[i]] == 0) continue;
            dfs(y+my[i], x+mx[i]);
        }
    }
} 

int main() {
    while(true) {
        cin>>w>>h;
        if (w == 0) break;
        world.assign(h, vector<int>(w,0));
        visited.assign(h, vector<int>(w,0));
        cnt = 0;
        for (int i =0; i<h; i++) {
            for (int j = 0; j< w; j++) {
                cin>>world[i][j];
            }
        }
        for (int i =0; i<h; i++) {
            for (int j = 0; j< w; j++) {
                if (!visited[i][j] && world[i][j]) {
                    cnt++;
                    dfs(i,j);
                }
            }
        }
        cout<<cnt<<endl;
    }
}