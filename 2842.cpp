#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> allHeights;
vector<string> s;
vector<vector<int> > height;
vector<vector<int> > visited;
set<int> h;
int PY, PX;
int houseCount = 0;
int mY[] = {0,0,-1,-1,-1,1,1,1};
int mX[] = {-1,1,-1,0,1,-1,0,1};
int minDiff = 1000001;
int minHeight = 1000001;
int maxHeight = 0;
int smaller(int y, int x, int limit) {
    if (height[y][x] > limit) return 0;
    if (visited[y][x]) return 0;
    visited[y][x] = 1;
    int cnt = 0;
    if (s[y][x] == 'K') {
        cnt++;
    }
    for (int i = 0; i<8; i++) {
        if (y+mY[i] >=0 && y+mY[i] <n && x+mX[i]>=0 && x+mX[i] < n) {
            cnt += smaller(y+mY[i], x+mX[i], limit);
        }
    }
    return cnt;

}
int bigger(int y, int x, int limit) {
    if (height[y][x] < limit ) return 0;
    if (visited[y][x]) return 0;
    visited[y][x] = 1;
    int cnt = 0;
    if (s[y][x] == 'K') {
        cnt++;
    }
    for (int i = 0; i<8; i++) {
        if (y+mY[i] >=0 && y+mY[i] <n && x+mX[i]>=0 && x+mX[i] < n) {
            cnt += bigger(y+mY[i], x+mX[i], limit);
        }
    }
    return cnt;
}

int dfs( int y, int x, int sl, int bl) {
    if (height[y][x] < sl || height[y][x] > bl) return 0;
    if (visited[y][x]) return 0;
    visited[y][x] = 1;
    int cnt = 0;
    if (s[y][x] == 'K') {
        cnt++;
    }
    for (int i = 0; i<8; i++) {
        if (y+mY[i] >=0 && y+mY[i] <n && x+mX[i]>=0 && x+mX[i] < n) {
            cnt += dfs(y+mY[i], x+mX[i], sl,bl);
        }
    }
    return cnt;
}

bool cmp(pair<int, int> a, pair<int ,int> b) {
    if (a.second-a.first < b.second-b.first){
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    height.assign(n, vector<int>(n,0));
    visited.assign(n,vector<int>(n,0));
    for (int i=0; i<n; i++) {
        string temp;
        cin>>temp;
        for (int j=0; j<temp.size(); j++) {
            if (temp[j] == 'P' ) {
                PY=i;PX=j;
            }
            if (temp[j] == 'K') {
                houseCount++;
            }
        }
        s.push_back(temp);
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin>>height[i][j];
            allHeights.push_back(height[i][j]);
        }
    }
    sort(allHeights.begin(), allHeights.end());

    int a = 0;
    int b = allHeights.size()-1;
    int maxAv = 0;
    while(a<=b) {
        int middle = (a+b) /2;
        visited.assign(n,vector<int>(n,0));
        int ans = smaller(PY,PX, allHeights[middle]);
        if (ans == houseCount) {
            maxAv = middle;
            b = middle - 1;
        }
        else {
            a = middle + 1 ;
        }
    }
    int diff = -1;
    for (int i = maxAv; i<allHeights.size();i++) {
        int c;
        if (diff == -1) c= 0;
        else c = allHeights[i] - diff;
        int d = allHeights[i];
        while (c<=d) {
            //cout<<"inner while c: "<<c<<", d: "<<d<<endl;
            int middle2 = (c+d)/2;
            visited.assign(n,vector<int>(n,0));
            int ans2 = dfs(PY,PX, middle2, allHeights[i]);
            if (ans2 == houseCount) {
                diff = allHeights[i]-middle2;
                c= middle2+1;
            }
            else {
                d= middle2-1;
            }
        }
    }
    
    // cout<<allHeights[maximum]<<endl;
    // cout<<allHeights[minimum]<<endl;
    cout<<diff<<endl;
    return 0;
}