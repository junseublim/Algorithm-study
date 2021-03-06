#include <bits/stdc++.h>

using namespace std;

vector<string> vs;
int cache[19683];

int calc(const vector<string>& curr) {
    int ans = 0;
    for (int i = 0; i<3; i++) {
        for (int j = 0; j<3; j++) {
            ans *= 3;
            if (curr[i][j] == 'o') {
                ans +=1;
            }
            else if (curr[i][j] == 'x') {
                ans +=2;
            }
        }
    }
    return ans;
}


bool isFinished(const vector<string>& vvs, char turn) {
    for (int i =0; i<3; i++) {
        int win = true;
        for (int j =0; j<3; j++) {
            if (vvs[i][j] != turn) win = false;
        }
        if (win) return true;
    }
    for (int i =0; i<3; i++) {
        int win = true;
        for (int j =0; j<3; j++) {
            if (vvs[j][i] != turn) win = false;
        }
        if (win) return true;
    }
    int win = true;
    for (int i =0; i<3; i++) {
        if (vvs[i][i] != turn) win = false;
    }
    if (win) return true;
    win = true;
    for (int i =0; i<3; i++) {
        if (vvs[i][3-1-i] != turn) win = false;
    }
    if (win) return true;
    return false;
    
}

int tictactoe(vector<string>& vvs, char turn) {
    if (isFinished(vvs, 'o'+'x'-turn)) {
        return -1;
    }
    int index = calc(vvs);
    int &ret = cache[index];
    if (ret != -2) return ret;
    int oponent = 2;
    for (int i =0; i<3; i++) {
        for (int j = 0; j<3; j++) {
            if (vvs[i][j] == '.') {
                vvs[i][j] = turn;
                oponent = min(tictactoe(vvs, 'o'+'x'-turn), oponent);
                vvs[i][j] = '.';
            }
        }
    }
    if (oponent == 1) return ret = -1;
    else if (oponent == 0 || oponent == 2) return ret = 0;
    else return ret = 1;
}

int main() {
    int C;
    cin>>C;
    while(C--) {
        vs.clear();
        for (int i =0; i<19683; i++){
            cache[i] = -2;
        }
        char turn = 'x';
        int cnt = 0;
        for (int i =0; i<3; i++) {
            string temp;
            cin>>temp;
            vs.push_back(temp);
            for (int j = 0; j<3; j++) {
                if (temp[j] != '.') {
                    cnt++;
                }
            }
        }
        if (cnt%2 == 1) turn = 'o';
        int win = tictactoe(vs, turn);
        if (win==1) cout<<turn<<endl;
        else if (win == 0) cout<<"TIE"<<endl;
        else cout<<char('o'+'x'-turn)<<endl;
    }
}