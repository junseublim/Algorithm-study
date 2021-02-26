#include<bits/stdc++.h>
using namespace std;
int n,m;
int r,c;
int d;
int room[51][51];
int cleaned = 0;
int main() {
    cin>>n>>m;
    cin>>r>>c>>d;
    for (int i =0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin>>room[i][j];
        }
    }
    int cnt = 0;
    while(true) {
        if (room[r][c] == 0 ) {
            room[r][c] = 2;
            cnt = 0;
            cleaned++;
        }
        if (cnt == 4) {
            if (d == 0) {
                if (room[r+1][c] == 2) r+=1;
                else break;
            }
            if (d == 1) {
                if (room[r][c-1] == 2) c-=1;
                else break;
            }
            if (d == 2) {
                if (room[r-1][c] == 2) r-=1;
                else break;
            }
            if (d == 3) {
                if (room[r][c+1] == 2) c+=1;
                else break;
            }
            cnt = 0;

        }
        if (d == 0 ){
            if (c-1 > 0 && room[r][c-1] == 0) {
                c -=1;
                d = 3;
            }
            else {
                d = 3;
                cnt++;
            }
        }
        else if ( d == 2) {
            if (c+1 < m-1 && room[r][c+1] == 0) {
                c +=1;
                d = 1;
            }
            else {
                d = 1;
                cnt++;
            }
        }
        else if ( d == 1) {
            if (r-1 > 0 && room[r-1][c] == 0) {
                r -=1;
                d = 0;
            }
            else {
                d = 0;
                cnt++;
            }
        }
        else {
            if (r+1 < n-1 && room[r+1][c] == 0) {
                r +=1;
                d = 2;
            }
            else {
                d = 2;
                cnt++;
            }
        }
    }
    cout<<cleaned<<endl;

}