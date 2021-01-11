#include <vector>
#include <iostream>
#include <queue>


using namespace std;
typedef struct
{
        int y, x;
} Dir;

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int r,c;
int destY, destX;
int time = 0, finalTime= -1;
vector<vector<char>>forest (0, vector<char>(0));
queue<pair<int,int>> river;
queue<pair<int,int>> mole;

void moveRiver() {
    if (!river.size()) return;
    int currSize = river.size();
    for (int i = 0; i<currSize; i ++) {
        int y,x;
        y = river.front().first;
        x= river.front().second;
        river.pop();
        if (y + moveDir[0].y < r) {
            int newY= y + moveDir[0].y;
            if (forest[newY][x] != 'X'  && forest[newY][x] != 'D'  && forest[newY][x] != '*') {
                forest[newY][x] = '*';
                river.push({newY, x});
            }
        }
        if (y + moveDir[1].y >= 0) {
            int newY= y + moveDir[1].y;
            if (forest[newY][x] != 'X'  && forest[newY][x] != 'D' && forest[newY][x] != '*') {
                forest[newY][x] = '*';
                river.push({newY, x});
            }
        }
        if (x + moveDir[2].x < c) {
            int newX= x + moveDir[2].x;
            if (forest[y][newX] != 'X'  && forest[y][newX] != 'D' && forest[y][newX] != '*') {
                forest[y][newX] = '*';
                river.push({y, newX});
            }
        }
        if (x + moveDir[3].x >= 0) {
            int newX= x + moveDir[3].x;
            if (forest[y][newX] != 'X'  && forest[y][newX] != 'D'&& forest[y][newX] != '*' ) {
                forest[y][newX] = '*';
                river.push({y, newX});
            }
        }
    }

}
void moveMole() {
    int y,x;
    int currSize = mole.size();
    for (int i =0; i<currSize; i++) {
        y = mole.front().first;
        x= mole.front().second;
        mole.pop();
        if (y == destY && x == destX) {
            finalTime = time;
            return;
        }
        if (y + moveDir[0].y < r) {
            int newY= y + moveDir[0].y;
            if (forest[newY][x] != 'X'  && forest[newY][x] != '*'&& forest[newY][x] != 'S' ) {
                forest[newY][x] = 'S';
                mole.push({newY, x});
            }
        }
        if (y + moveDir[1].y >= 0) {
            int newY= y + moveDir[1].y;
            if (forest[newY][x] != 'X'  && forest[newY][x] != '*'&& forest[newY][x] != 'S' ) {
                forest[newY][x] = 'S';
                mole.push({newY, x});
            }
        }
        if (x + moveDir[2].x < c) {
            int newX= x + moveDir[2].x;
            if (forest[y][newX] != 'X'  && forest[y][newX] != '*'&& forest[y][newX] != 'S' ) {
                forest[y][newX] = 'S';
                mole.push({y, newX});
            }
        }
        if (x + moveDir[3].x >= 0) {
            int newX= x + moveDir[3].x;
            if (forest[y][newX] != 'X'  && forest[y][newX] != '*' && forest[y][newX] != 'S' ) {
                forest[y][newX] = 'S';
                mole.push({y, newX});
            }
        }
    }
}

int main() {
    
    cin>>r>>c;
    forest.assign(r, vector<char>(c));
    

    for (int i =0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cin>>forest[i][j];
            if (forest[i][j] == 'S')
                mole.push({i,j});
            if (forest[i][j] =='*')
                river.push({i,j});
            if (forest[i][j] == 'D'){
                destY = i;
                destX = j;
            }
                
        }
    }
    
    while (mole.size() && finalTime == -1) {
        moveRiver();
        moveMole();
        time++;
    }
    if (finalTime != -1) {
        cout<<finalTime<<endl;
    }
    else {
        cout<<"KAKTUS"<<endl;
    }
    
}