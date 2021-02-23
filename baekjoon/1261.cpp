#include <bits/stdc++.h>

using namespace std;
int n, m;
int maze[101][101];
vector<vector<int> > dist;
int mY[] = {0,0,-1,1};
int mX[] = {-1,1,0,0};
queue<pair<int, int> > q;
int main() {
    dist.assign(101, vector<int>(101, 10001));
    cin>>n>>m;
    for(int i =0; i<m; i++) {
        string temp;
        cin>>temp;
        for (int j=0;j<temp.size();j++) {
            maze[i+1][j+1] = temp[j]-'0';
        }
    }
    dist[1][1] = 0;
    q.push(make_pair(1,1));
    while(!q.empty()) {
        pair<int,int> pii = q.front();
        q.pop();
        int y = pii.first;
        int x = pii.second;
        for (int i=0; i<4; i++) {
            int nY = y+ mY[i];
            int nX = x+ mX[i];
            if (nY> 0 && nY <=m && nX>0 && nX <=n) {
                if (dist[nY][nX] > dist[y][x] + maze[nY][nX]) {
                    dist[nY][nX] = dist[y][x] + maze[nY][nX];
                    q.push(make_pair(nY,nX));
                }
            }
        }
    }
    cout<<dist[m][n]<<endl;

}