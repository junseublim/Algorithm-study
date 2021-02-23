#include <iostream>
#include <vector>

using namespace std;

int n;
int total = 0;
vector<vector<int>> board;

void setVertical(int x, int value) {
    for (int i=0; i<n; i++) {
        board[i][x] += value;
    }
}

void setDiagonal(int y,int x, int value) {
    int offset = 1;
    for (int i = y+1; i <n; i++) {
        if (x+offset < n) {
            board[i][x+offset] += value;
        }
        if (x-offset >= 0) {
            board[i][x-offset] += value;
        }
        offset++;
    }
}

void dfs (int y) {
    if (y == n) {
        total++;
        return;
    }
    for (int x=0; x<n; x++) {
        if (board[y][x] == 0) {
            setVertical(x, 1);
            setDiagonal(y,x, 1);
            dfs(y+1);
            setVertical(x, -1);
            setDiagonal(y,x, -1);
        } 

    }
}


int main() {
    cin>>n;
    board.assign(n, vector<int>(n, 0));
    dfs(0);
    cout<<total<<endl;



}