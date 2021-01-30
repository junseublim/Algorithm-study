#include <bits/stdc++.h>

using namespace std;
int n,m;
int lab[8][8];
int labTest[8][8];
typedef pair<int,int> pii;
vector<pii> virus;
int maximum = 0;
int my[] = {0,0,-1,1};
int mx[] = {-1,1,0,0};
int maxCnt = 0;

void bfs() {
    queue<pii> q;
    for (auto x: virus) q.push(x);
    int visited[8][8] = {0};

    while(!q.empty()) {
        pii curr = q.front();
        q.pop();
        int y= curr.first;
        int x= curr.second;
        if (visited[y][x]) continue;
        visited[y][x] = 1;
        labTest[y][x] = 2;
        for (int i =0; i<4; i++) {
            if (y+my[i] >=0 && y+my[i] <n && x+mx[i] >= 0 && x+mx[i] < m) {
                if (labTest[y+my[i]][x+mx[i]] != 0) continue;
                q.push(make_pair(y+my[i],x+mx[i]));
            }
        }
    }
}
void getMax() {
    int cnt = 0;
    for (int i = 0; i<n; i++) {
        for (int j =0; j<m; j++) {
            if (labTest[i][j] == 0) {
                cnt++;
            }
        }
    }
    maxCnt = max(cnt, maxCnt);
}


void solve(int y, int x, int cnt) {
    lab[y][x] = 1;
    if (cnt == 3) {
        memcpy(labTest, lab, sizeof(lab));
        bfs();
        getMax();
        lab[y][x] = 0;
        return;
    }
    for (int i = y; i<n; i++) {
        if (i == y) {
            for (int j = x+1; j<m; j++) {
                if (lab[i][j] == 0) {
                    solve(i,j, cnt+1);
                }
            }
        }
        else {
            for (int j = 0; j<m; j++) {
                if (lab[i][j] == 0) {
                    solve(i,j, cnt+1);
                }
            }
        }
        
    }
    lab[y][x] = 0;
}

int main() {
    
    cin>>n>>m;
    for (int i =0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin>>lab[i][j];
            if (lab[i][j] == 2) {
                virus.push_back(make_pair(i,j));
            }
        }
    }
    for (int i =0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (lab[i][j] == 0) {
                solve(i,j, 1);
            }
        }
    }
    cout<<maxCnt<<endl;
}