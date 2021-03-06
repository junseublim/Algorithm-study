#include <bits/stdc++.h>

using namespace std;


vector<string> vs;
char cache[1<<25];
vector<int> moves;

inline int cell(int y, int x) {return 1<<(y*5+x);}

void precalc() {
    for (int i=0; i<4; i++) {
        for (int j = 0; j<4; j++) {
            moves.push_back(cell(i,j) + cell(i,j+1) + cell(i+1,j));
            moves.push_back(cell(i,j) + cell(i+1,j) + cell(i+1,j+1));
            moves.push_back(cell(i,j) + cell(i+1,j+1) + cell(i,j+1));
            moves.push_back(cell(i,j+1) + cell(i+1,j+1) + cell(i+1,j));
        }
    }
    for (int i =0; i<5; i++) {
        for (int j =0; j<4; j++) {
            moves.push_back(cell(i,j)+ cell(i,j+1));
            moves.push_back(cell(j,i)+ cell(j+1,i));
        }
    }
}

char blockgame(int board) {
    //cout<<"blockgame: "<<board<<endl;
    char &ret = cache[board];
    if (ret != -1) {
        return ret;
    }
    ret = 0;
    for (int i=0; i<moves.size(); i++) {
        if (!(moves[i] & board)) {
            if (!(blockgame(board | moves[i]))) {
                ret = 1;
                break;
            }
        }
    }
    return ret;
}



int main() {
    int C;
    cin>>C;
    precalc();
    while(C--) {
        for (int i =0; i < (1<<25); i++) {
            cache[i] = -1;
        }
        vs.clear();
        for (int i=0; i<5; i++) {
            string temp;
            cin>>temp;
            vs.push_back(temp);
        }
        int board = 0;
        for (int i =0; i<5; i++) {
            for (int j=0; j<5;j++) {
                if (vs[i][j] == '#')
                    board |= cell(i,j);
            }
        }
        char win = blockgame(board);
        if (win == 1){
            cout<<"WINNING"<<endl;
        }
        else {
            cout<<"LOSING"<<endl;
        }
    }
}