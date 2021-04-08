#include <bits/stdc++.h>
using namespace std;
int n;
int dy[] = {-1,0,0,1};
int dx[] = {0,-1,1,0};
typedef pair<int,int> pii;

typedef struct Tiii {
    int y,x,t;
    Tiii(int yy, int xx, int tt){
        y=yy;t=tt;x=xx;
    }
} Tiii;
int area[20][20];
int shark = 2;

Tiii bfs(int sy,int sx) {
    queue<Tiii> q;
    q.push(Tiii(sy,sx, 0));
    int visited[20][20];
    memset(visited, 0, sizeof(visited));
    int found = 0;
    int ay,ax,at;
    while(!q.empty()) {
        Tiii next = q.front();
        q.pop();
        int y = next.y, x= next.x;
        if (visited[y][x]) continue;
        visited[y][x] = 1;
        if (found && at < next.t) {
            return Tiii(ay,ax,at);
        }
        if (area[y][x] != 0 && area[y][x] < shark) { 
            if (!found) {
                ay = y; 
                ax = x;
                at = next.t;
                found = 1;
            }
            else {
                if (y < ay) {
                    ay = y; 
                    ax = x;
                }
                else if (y == ay && x < ax) {
                    ay = y; 
                    ax = x;
                }
            }

        }
        if (area[y][x] > shark) continue;
        for (int i =0; i<4; i++) {
            int ny = y+ dy[i];
            int nx = x + dx[i];
            if (ny >= 0 && ny < n && nx >= 0 && nx <n) {
                q.push(Tiii(ny,nx, next.t+1));
            } 
        }
    }
    if (found) return Tiii(ay,ax,at);
    return (Tiii(-1,-1,-1));
}

int main() {
    
    
    int sy,sx;
    cin>>n;
    for (int i =0; i<n;i++) {
        for (int j = 0; j<n; j++) {
            cin>>area[i][j];
            if  (area[i][j] == 9) {
                sy=i;sx=j;
                area[i][j] = 0;
            }
        }
    }
    int time = 0;
    int eaten = 0;
    while(true) {
        Tiii next = bfs(sy,sx);
        int first = next.y;
        int second = next.x;
        if (first == -1) break;
        eaten++;
        if (eaten == shark) {
            eaten = 0;
            shark++;
        }
        area[first][second] = 0;
        time += next.t;
        sy = first;
        sx = second;

    };
    cout<<time<<endl;
}