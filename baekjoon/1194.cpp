#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int n, m;

char board[50][50];
int my[] = {0,0,-1,1};
int mx[] = {-1,1,0,0};
typedef struct Move {
    int y;
    int x;
    int cnt;
    int keys;
} Move;
int visited[64][50][50] = {0};

int bfs(int yy, int xx) {
    queue<Move> q;
    Move mv = Move();
    mv.y=yy;
    mv.x=xx;
    mv.cnt=0;
    mv.keys=0;
    q.push(mv);
    while(!q.empty()) {
        Move move1 = q.front();
        q.pop();
        int y = move1.y;
        int x = move1.x;
        if (board[y][x] == '#') continue;
        if (board[y][x] == '1') return move1.cnt;
        if (board[y][x] >= 'A' && board[y][x] <= 'F') {
            if (!(1<<(board[y][x] - 'A') & move1.keys)) {
                continue;
            }
        }
        if (board[y][x] >= 'a' && board[y][x] <= 'f') {
            if (!(move1.keys & 1<<(board[y][x]-'a'))) {
                move1.keys |= 1<<(board[y][x]-'a');
            }
        }
        if (visited[move1.keys][y][x]) continue;
        visited[move1.keys][y][x] = 1;
        for (int i =0; i<4; i++) {
            if (y+my[i] >=0 && y+my[i] <n && x+mx[i] >=0 && x+mx[i]<m) {
                Move next = Move();
                next.y = y+my[i];
                next.x = x+mx[i];
                next.cnt = move1.cnt+1;
                next.keys = move1.keys;
                q.push(next);
            }   
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    int y,x;
    for (int i =0; i<n; i++) {
        for (int j =0; j<m; j++) {
            cin>>board[i][j];
            if (board[i][j] == '0') {
                y= i;
                x = j;
            }
        }
    }
    int ret = bfs(y,x);
    cout<<ret<<"\n";    
}