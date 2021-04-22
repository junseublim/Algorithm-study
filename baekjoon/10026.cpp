#include <bits/stdc++.h>

using namespace std;
int n;
int visited[100][100];
vector<string> vs;
int my[4] = {0,0,1,-1};
int mx[4] = {-1,1,0,0};
void go(int y, int x, int isColorblind, char color) {
    queue<pair<int, int> > q;
    q.push(make_pair(y,x));
    while(!q.empty()) {
        pair<int, int> nxt = q.front();
        q.pop();
        int ny = nxt.first;
        int nx = nxt.second;
        if (visited[ny][nx]) continue;
        if (isColorblind) {
            if (color == 'R' || color == 'G') {
                if (vs[ny][nx] != 'R' && vs[ny][nx] != 'G') {
                    continue;
                }
            }
            else {
                if (vs[ny][nx] != 'B')continue;
            }
        }
        else {
            if (color != vs[ny][nx]) {
                continue;
            }
        }
        visited[ny][nx] = 1;
        for (int i =0; i<4; i++) {
            if (ny+my[i] >= 0 && ny+my[i] < n && nx+mx[i]>=0 && nx+mx[i] < n) {
                q.push(make_pair(ny+my[i], nx+mx[i]));
            }
        }
    }

}

int getCnt(int isColorBlind) {
    memset(visited, 0, sizeof(visited));
    int cnt = 0;
    for (int i =0; i<n; i++) {
        for (int j =0; j<n; j++) {
            if (visited[i][j] == 0 ) {
                go(i,j,isColorBlind, vs[i][j]);
                cnt++;
            }
        }
    }
    return cnt;
}


int main() {
    cin>>n;
    vs.assign(n, "");
    for (int i =0; i<n; i++) {
        cin>>vs[i];
    }
    int gn = getCnt(0);
    int rg = getCnt(1);
    cout<<gn<<" "<<rg<<endl;

}