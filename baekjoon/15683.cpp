#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
int n, m;
char room[8][8];
int watchig[8][8];
vector<pii> cctvs;
int my[] = {0,0,-1,1};
int mx[] = {-1,1,0,0};
int cnt = 97654321;

void watch(int y, int x, int idx) {
    int r = my[idx];
    int c = mx[idx];
    int t = 1;
    while (true) {
        if (y+t*r <0 || y+t*r >= n) break;
        if (x+t*c <0 || x+t*c >= m) break;
        if (room[y+t*r][x+t*c] == '6') {
            break;
        } 
        watchig[y+t*r][x+t*c]++;
        t++;
    }
}
void unwatch(int y, int x, int idx) {
    int r = my[idx];
    int c = mx[idx];
    int t = 1;
    while (true) {
        if (y+t*r <0 || y+t*r >= n) break;
        if (x+t*c <0 || x+t*c >= m) break;
        if (room[y+t*r][x+t*c] == '6') {
            break;
        } 
        watchig[y+t*r][x+t*c]--;
        t++;
    }
}


int cntUnwatch() {
    int cnt = 0;
    for (int i =0; i<n; i++) {
        for (int j =0; j<m; j++) {
            if (room[i][j] == '0' && watchig[i][j] == 0) {
                cnt++;
            }
        }
    }
    return cnt;
}

void go(int c) {
    if (c == cctvs.size() ) {
        cnt = min(cntUnwatch(),cnt);
        return;
    }
    pii cctv = cctvs[c];
    if (room[cctv.first][cctv.second] == '1') {
        watch(cctv.first, cctv.second, 0);
        go(c+1);
        unwatch(cctv.first, cctv.second, 0);
        watch(cctv.first, cctv.second, 1);
        go(c+1);
        unwatch(cctv.first, cctv.second, 1);
        watch(cctv.first, cctv.second, 2);
        go(c+1);
        unwatch(cctv.first, cctv.second, 2);
        watch(cctv.first, cctv.second, 3);
        go(c+1);
        unwatch(cctv.first, cctv.second, 3);
    }
    else if (room[cctv.first][cctv.second] == '2') {
        watch(cctv.first, cctv.second, 0);
        watch(cctv.first, cctv.second, 1);
        go(c+1);
        unwatch(cctv.first, cctv.second, 0);
        unwatch(cctv.first, cctv.second, 1);
        watch(cctv.first, cctv.second, 2);
        watch(cctv.first, cctv.second, 3);
        go(c+1);
        unwatch(cctv.first, cctv.second, 2);
        unwatch(cctv.first, cctv.second, 3);        
    }
    else if (room[cctv.first][cctv.second] == '3') {
        watch(cctv.first, cctv.second, 0);
        watch(cctv.first, cctv.second, 2);
        go(c+1);
        unwatch(cctv.first, cctv.second, 0);
        unwatch(cctv.first, cctv.second, 2);
        watch(cctv.first, cctv.second, 0);
        watch(cctv.first, cctv.second, 3);
        go(c+1);
        unwatch(cctv.first, cctv.second, 0);
        unwatch(cctv.first, cctv.second, 3);        
        watch(cctv.first, cctv.second, 1);
        watch(cctv.first, cctv.second, 2);
        go(c+1);
        unwatch(cctv.first, cctv.second, 1);
        unwatch(cctv.first, cctv.second, 2);
        watch(cctv.first, cctv.second, 1);
        watch(cctv.first, cctv.second, 3);
        go(c+1);
        unwatch(cctv.first, cctv.second, 1);
        unwatch(cctv.first, cctv.second, 3);   
    }
    else if (room[cctv.first][cctv.second] == '4') {
        watch(cctv.first, cctv.second, 0);
        watch(cctv.first, cctv.second, 1);
        watch(cctv.first, cctv.second, 2);
        go(c+1);
        unwatch(cctv.first, cctv.second, 0);
        unwatch(cctv.first, cctv.second, 1);
        unwatch(cctv.first, cctv.second, 2);
        watch(cctv.first, cctv.second, 0);
        watch(cctv.first, cctv.second, 1);
        watch(cctv.first, cctv.second, 3);
        go(c+1);
        unwatch(cctv.first, cctv.second, 0);
        unwatch(cctv.first, cctv.second, 1);
        unwatch(cctv.first, cctv.second, 3);        
        watch(cctv.first, cctv.second, 1);
        watch(cctv.first, cctv.second, 2);
        watch(cctv.first, cctv.second, 3);
        go(c+1);
        unwatch(cctv.first, cctv.second, 1);
        unwatch(cctv.first, cctv.second, 2);
        unwatch(cctv.first, cctv.second, 3);
        watch(cctv.first, cctv.second, 0);
        watch(cctv.first, cctv.second, 2);
        watch(cctv.first, cctv.second, 3);
        go(c+1);
        unwatch(cctv.first, cctv.second, 0);
        unwatch(cctv.first, cctv.second, 2);   
        unwatch(cctv.first, cctv.second, 3);   
    }
    else {
        watch(cctv.first, cctv.second, 0);
        watch(cctv.first, cctv.second, 1);
        watch(cctv.first, cctv.second, 2);
        watch(cctv.first, cctv.second, 3);
        go(c+1);
        unwatch(cctv.first, cctv.second, 0);
        unwatch(cctv.first, cctv.second, 1);
        unwatch(cctv.first, cctv.second, 2);   
        unwatch(cctv.first, cctv.second, 3);  
    }
    
}


int main() {    
    cin>>n>>m;
    memset(watchig, 0,sizeof(watchig));
    for (int i =0; i<n; i++) {
        for (int j =0; j<m; j++) {
            cin>>room[i][j];
            if (room[i][j] >= '1' && room[i][j] <= '5') {
                cctvs.push_back(make_pair(i,j));
            }
        }
    }
    go(0);
    cout<<cnt<<endl;
}