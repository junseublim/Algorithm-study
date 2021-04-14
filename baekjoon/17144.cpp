#include <bits/stdc++.h>

using namespace std;
int r,c,t;
typedef pair<int,int> pii;
int room[50][50];
int temp[50][50];
vector<int> vacumm;

int addDust(int i,int j, int dust) {
    if (i <0 || i>=r || j<0 || j>=c) return 0;
    if (room[i][j] == -1) return 0;
    temp[i][j] += dust;
    return 1;
}

void spread() {
    memset(temp, 0, sizeof(temp));
    for (int i =0; i<r; i++) {
        for (int j=0; j<c;j++) {
            if (room[i][j] > 0) {
                int cnt = 0;
                cnt += addDust(i-1,j, room[i][j]/5);
                cnt += addDust(i+1,j, room[i][j]/5);
                cnt += addDust(i,j-1, room[i][j]/5);
                cnt += addDust(i,j+1, room[i][j]/5);
                room[i][j] = room[i][j] - cnt*(room[i][j]/5);
            }
        }
    }
    for (int i =0; i<r; i++) {
        for (int j=0; j<c;j++) {
            room[i][j] += temp[i][j];
        }
    }
}

void clean() {
    int y1 = vacumm[0];
    int temp = 0;
    for (int i =1; i<c; i++) {
        int temp2 = room[y1][i];
        room[y1][i] = temp;
        temp = temp2;
    }
    for (int i =y1-1; i>=0; i--) {
        int temp2 = room[i][c-1];
        room[i][c-1] = temp;
        temp = temp2;
    }
    for (int i =c-2; i>=0; i--) {
        int temp2 = room[0][i];
        room[0][i] = temp;
        temp = temp2;
    }
    for (int i =1; i<y1; i++) {
        int temp2 = room[i][0];
        room[i][0] = temp;
        temp = temp2;
    }
    int y2 = vacumm[1];
    temp = 0;
    for (int i =1; i<c; i++) {
        int temp2 = room[y2][i];
        room[y2][i] = temp;
        temp = temp2;
    }
    for (int i =y2+1; i<r; i++) {
        int temp2 = room[i][c-1];
        room[i][c-1] = temp;
        temp = temp2;
    }
    for (int i =c-2; i>=0; i--) {
        int temp2 = room[r-1][i];
        room[r-1][i] = temp;
        temp = temp2;
    }
    for (int i =r-2; i>y2; i--) {
        int temp2 = room[i][0];
        room[i][0] = temp;
        temp = temp2;
    }
}

int main() {
    cin>>r>>c>>t;
    for (int i =0; i<r; i++) {
        for (int j=0; j<c;j++) {
            cin>>room[i][j];
            if (room[i][j] == -1) {
                vacumm.push_back(i);
            }
        }
    }
    for (int i =0; i<t; i++) {
        spread();
        clean();
    }
    int dust =0;
    for (int i =0; i<r; i++) {
        for (int j=0; j<c;j++) {
            if (room[i][j] == -1) continue;
            dust += room[i][j];
        }
    }
    cout<<dust<<endl;
}