#include <bits/stdc++.h>

using namespace std;
string village[25];
int visited[25][25];
vector<int> cnt;
int totalVillages =0;
int n;
int moveY[] = {0,0,-1,1};
int moveX[] = {1,-1,0,0};


void bfs(int y,int x) {
    if (visited[y][x] || village[y][x] == '0') {
        return;
    }
    queue<pair<int,int> > q;
    q.push(make_pair(y,x));
    int currcnt = 0;
    while(!q.empty()) {
        pair<int,int> curr = q.front();
        q.pop();
        if (visited[curr.first][curr.second]) continue;
        currcnt++;
        visited[curr.first][curr.second] = 1;
        for (int i = 0; i<4; i++) {
            int ny = curr.first + moveY[i];
            int nx = curr.second + moveX[i];
            if (ny>=0 && ny<n && nx>=0 && nx < n) {
                if (village[ny][nx] == '0') continue;
                q.push(make_pair(ny,nx));
            }
        }
    }
    cnt.push_back(currcnt);
    totalVillages++;
}


int main() {
    
    cin>>n;

    for (int i=0; i<n; i++) {
        cin>>village[i];
    }

    for (int i =0; i<n; i++) {
        for (int j =0; j<n;j++) {
            bfs(i,j);
        }
    }
    cout<<totalVillages<<endl;
    sort(cnt.begin(), cnt.end());
    for (auto x: cnt) {
        cout<<x<<endl;
    }

}