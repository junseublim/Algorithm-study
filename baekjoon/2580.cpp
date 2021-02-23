#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<vector<int>> sudoku (9, vector<int>(9,0));
vector<pair<int,int>> emptyPos;
vector<vector<int>> available;
bool isDone = false;
void dfs(int index) {
    if (index == emptyPos.size()) {
        for (int i=0; i< 9; i++) {
            for (int j=0; j<9; j++) {
                cout<<sudoku[i][j]<<" ";
            }
        cout<<endl;
        }
        isDone = true;
        return;
    }
    int y = emptyPos[index].first;
    int x = emptyPos[index].second;

    for (int i =1; i<=9; i++) {
        int able = 1;
        for (int j = 0; j<9; j++) {
            if (sudoku[y][j] == i){
                able= 0;
            }
            if (sudoku[j][x] == i){
                able= 0;
            }
        }
        int baseY = y/3;
        int baseX = x/3;
        for (int j =0; j<3; j++) {
            for (int k =0; k<3; k++) {
                if (sudoku[3*baseY + j][3*baseX + k] == i) {
                    able= 0;
                }
            }
        }
        if (able) {

            sudoku[y][x] = i;
            dfs(index+1);
            if (isDone) return;
            sudoku[y][x] = 0;
        }

     }
}

int main() {
    for (int i=0; i< 9; i++) {
        for (int j=0; j<9; j++) {
            cin>>sudoku[i][j];
            if (sudoku[i][j] == 0) {
                emptyPos.push_back({i,j});
            }
        }
    }
    dfs(0);
    

    
}