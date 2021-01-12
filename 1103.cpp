#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> visited;
vector<string> board;
queue<tuple<int,int,int>> q;
int n, m;
int maxCount = 0;
void bfs() {
    while(!q.empty()) {
        tuple<int,int, int> next = q.front();
        q.pop();
        int y = get<0>(next);
        int x = get<1>(next);
        int count = get<2>(next);
        if (count > n*m) {
            maxCount = -1;
            break;
        }
        if (count <= visited[y][x]) continue;
        //cout<<"vist"<<y<<x<<endl;
        //cout<<count<<endl;
        char number = board[y][x];
        if (number == 'H') continue;
        visited[y][x] = count;
        int jumps = number - '0';
        if (y-jumps >= 0) q.push({y-jumps, x, count+1});
        if (y+jumps < n) q.push({y+jumps, x, count+1});
        if (x-jumps >= 0) q.push({y, x-jumps, count+1});
        if (x+jumps < m) q.push({y, x+jumps, count+1});
    }
    
}

int main() {
    cin>>n>>m;
    visited.assign(n, vector<int>(m, 0));
    q.push({0,0, 1});
    for (int i=0; i<n; i++) {
        string s;
        cin>>s;
        board.push_back(s);
    }
    bfs();
    if (maxCount != -1) {
        for (auto x: visited){
            for (auto z: x) {
                maxCount = max(z, maxCount);
            }
        }
    }
    cout<<maxCount<<endl;

}