#include <bits/stdc++.h>
using namespace std;
int n,m;
char board[20][20];
int my[] = {0,0,-1,1};
int mx[] = {-1,1,0,0,};
int maximum = 0;
int alphabet[26];
void backtrack(int y, int x, int cnt) {
    if (y>= 0 && y<n && x >=0 && x<m) {
        char curr = board[y][x];
        if (!alphabet[curr-'A']) {
            alphabet[curr-'A'] = 1;
            maximum = max(maximum, cnt+1);
            for (int i =0; i<4; i++ ){
                backtrack(y+my[i], x+mx[i], cnt+1);
            }
            alphabet[curr-'A'] = 0;
        }
    }
    
}

int main() {
    cin>>n>>m;
    for (int i =0; i<n; i++) {
        for (int j= 0; j<m; j++) {
            cin>>board[i][j];
        }
    }
    backtrack(0,0, 0);
    cout<<maximum<<endl;
}