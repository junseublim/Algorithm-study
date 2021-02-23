#include <bits/stdc++.h>

using namespace std;
int n,m;
vector<vector<int> > v;

typedef struct Tomato{
    int y,x,cnt;
    Tomato(int yy,int xx, int ccnt) {
        y=yy;
        x=xx;
        cnt=ccnt;
    }
} Tomato;
int moveY[] = {-1,0,1,0};
int moveX[] = {0,1,0,-1};

queue<Tomato> q;
int visited[1001][1001];



int main() {
    cin>>m>>n;
    int neg = 0;
    v.assign(n, vector<int>(m));
    for (int i =0; i<n; i++) {
        for (int j =0; j<m; j++) {
            cin>>v[i][j];
            if (v[i][j] == 1) {
                q.push(Tomato(i,j,0));
            }
            else if (v[i][j] == -1) {
                neg++;
            }
        }
    }
    int visitcnt = 0;
    int maxcnt = 0;
    while(!q.empty()) {
        Tomato curr = q.front();
        q.pop();
        int y = curr.y;
        int x = curr.x;
        if (v[y][x] == -1 || visited[y][x]) continue;
        visitcnt++;
        visited[y][x] = 1;
        v[y][x] = curr.cnt;
        maxcnt = max(maxcnt, v[y][x]);
        for (int i = 0; i<4; i++) {
            if (y+moveY[i] >= 0 && y + moveY[i] <n && x+ moveX[i] >= 0 && x+moveX[i] <m) {
                q.push(Tomato(y+moveY[i], x+moveX[i], curr.cnt+1));
            }
        }
    }
    if (visitcnt != n*m-neg) {
        cout<<-1<<endl;
    }
    else {
        cout<<maxcnt<<endl;
    }
}