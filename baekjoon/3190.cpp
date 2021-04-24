#include<bits/stdc++.h>

using namespace std;
int board[101][101];
int main() {
    int n, k;
    cin>>n>>k;
    memset(board, 0, sizeof(board));
    for (int i =0; i<k; i++) {
        int y,x;
        cin>>y>>x;
        board[y][x] = 2;
    }
    int l;
    cin>>l;
    map<int, char> m;
    for (int i =0; i<l; i++) {
        int t; char direction;
        cin>>t>>direction;
        m[t] = direction;
    }
    int y = 1; int x= 1;
    int i =1;
    char dir = 'R';
    queue<pair<int, int> > q;
    q.push(make_pair(y, x));
    x++;
    for (; i< 10000; i++) {
        if (y == 0 || x ==0 || x> n || y>n) break;
        if (board[y][x] == 2) {
            board[y][x] = 1;
            q.push(make_pair(y,x));
        }
        else if (board[y][x] == 1) break;
        else {
            pair<int, int> tail = q.front();
            q.pop();
            board[tail.first][tail.second] = 0;
            board[y][x] = 1;
            q.push(make_pair(y,x));
        }
        if (m.count(i) && m.find(i)->second == 'L') {
            if (dir == 'R') dir = 'U';
            else if (dir == 'U') dir = 'L';
            else if (dir == 'L') dir = 'D';
            else  dir = 'R';
        }
        else if (m.count(i) && m.find(i)->second == 'D')  {
            if (dir == 'R') dir = 'D';
            else if (dir == 'U') dir = 'R';
            else if (dir == 'L') dir = 'U';
            else dir = 'L';
        }
        if (dir == 'R') x++;
        else if (dir == 'D') y++;
        else if (dir == 'U') y--;
        else x--;
    }
    cout<<i<<endl;
    
}