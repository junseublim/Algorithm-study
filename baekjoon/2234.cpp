#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
int n,m;
int castle[50][50];
int rooms[2500];
int visited[50][50];


void bfs(int y,int x, int room) {
    queue<pii> q;
    q.push(make_pair(y,x));
    int cnt = 0;
    while(!q.empty()) {
        pii next = q.front();
        q.pop();
        int yy = next.first;
        int xx = next.second;
        if (yy<0 || xx<0 || yy>= m || xx>= n) continue;
        if (visited[yy][xx] != -1) continue;
        visited[yy][xx] = room;
        cnt++;
        if ( (castle[yy][xx] & 1) == 0) {
            q.push(make_pair(yy,xx-1));
        }   
        if ( (castle[yy][xx] & 4) == 0) {
            q.push(make_pair(yy,xx+1));
        }   
        if ( (castle[yy][xx] & 2) == 0) {
            q.push(make_pair(yy-1,xx));
        }   
        if ( (castle[yy][xx] & 8) == 0) {
            q.push(make_pair(yy+1,xx));
        }   
    }
    rooms[room] = cnt;
}

int getPoss(int y, int x) {
    int mx = 0;
    if ( (castle[y][x] & 1) != 0 && x-1 >=0 ) {
        if (visited[y][x] != visited[y][x-1]) {
        mx = max(mx, rooms[visited[y][x]] + rooms[visited[y][x-1]]);
        }
    }   
    if ( (castle[y][x] & 4) != 0 && x+1 <n) {
        if (visited[y][x] != visited[y][x+1]) {
            mx = max(mx, rooms[visited[y][x]] + rooms[visited[y][x+1]]);
        }
    }   
    if ( (castle[y][x] & 2) != 0 && y-1 >=0 ) {
        if (visited[y][x] != visited[y-1][x]) {
            mx = max(mx, rooms[visited[y][x]] + rooms[visited[y-1][x]]);
        }
    }   
    if ( (castle[y][x] & 8) != 0 && y+1 <m) {
        if (visited[y][x] != visited[y+1][x]) {
            mx = max(mx, rooms[visited[y][x]] + rooms[visited[y+1][x]]);
        }
    }   
    return mx;
}


int main() {
    cin>>n>>m;
    for (int i=0; i<m; i++) {
        for (int j =0; j<n;j++) {
            cin>>castle[i][j];
        }
    }
    int room = 0;
    int biggest = 0;
    memset(visited, -1, sizeof(visited));
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (visited[i][j] != -1)continue;
            bfs(i,j, room);
            biggest = max(biggest, rooms[room]);
            room++;
            
        }
    }
    int possBig = 0;
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            possBig = max(possBig, getPoss(i,j));
        }
    }
    cout<<room<<endl;
    cout<<biggest<<endl;
    cout<<possBig<<endl;


}