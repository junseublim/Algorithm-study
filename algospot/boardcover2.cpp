#include <bits/stdc++.h>

using namespace std;

int h,w,r,c;
typedef pair<int, int> pii;
vector<string> board;
vector<string> block;
vector<vector<pii> > rotations;
int blockSize;
int cover[10][10];
int best;
vector<string> rotate(const vector<string>& arr) {
    vector<string> ret(arr[0].size(), string(arr.size(), ' '));
    for (int i=0;i<arr.size();i++) {
        for (int j=0; j<arr[0].size(); j++) {
            ret[j][arr.size()-i-1] = arr[i][j];
        }
    }
    return ret;
}

bool setB(int y, int x, const vector< pii >& block, int delta) {
    if (delta == 1) {
        bool ret = true;
        for (int i =0; i<block.size(); i++) {
            if (y+block[i].first >=h || x+block[i].second >= w || y+block[i].first < 0 || x+block[i].second <0) {
                return false;
            }
            if (cover[y+block[i].first][x+block[i].second] == 1) {
                ret =false;
            }
            cover[y+block[i].first][x+block[i].second] += 1;
        }
        return ret;
    }
    else {
        for (int i =0; i<block.size(); i++) {
            if (y+block[i].first >=h || x+block[i].second >= w || y+block[i].first < 0 || x+block[i].second <0) {
                return false;
            }
            cover[y+block[i].first][x+block[i].second] -= 1;
        }
    }
    return false;
}


void generateRotations(vector<string> block) {
    rotations.clear();
    rotations.resize(4);
    for (int rot = 0; rot<4; rot++) {
        int originY = -1, originX= -1;
        for (int i=0; i<block.size(); i++) {
            for (int j=0; j<block[i].size(); j++) {
                if (block[i][j] == '#') {
                    if (originY == -1) {
                        originY = i;
                        originX = j;
                    }
                rotations[rot].push_back(make_pair(i-originY, j-originX));
                }
            }
        }
        block = rotate(block);
    }
    sort(rotations.begin(), rotations.end());
    rotations.erase(unique(rotations.begin(), rotations.end()), rotations.end());
    blockSize = rotations[0].size();

}


void search(int placed) {
    int cnt = 0;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cnt += !(cover[i][j]) ? 1 : 0;
    if ((cnt / blockSize) + placed <= best) return;
    int y=-1, x=-1;
    for (int i=0; i<h; i++) {
        for (int j =0; j<w; j++) {
            if (cover[i][j] ==0) {
                y=i;x=j;
                break;
            }
        }
        if (y!= -1) break;
    }
    if (y==-1) {
        best = max(best, placed);
        return;
    }
    for (int i =0; i<rotations.size(); i++) {
        if (setB(y,x, rotations[i], 1)) {
            search(placed+1);
        }
        setB(y,x, rotations[i], -1);
    }
    cover[y][x] = 1;
    search(placed);
    cover[y][x] = 0;
}

int solve() {
    best = 0;
    for (int i=0; i<h; i++) {
        for (int j =0; j<w; j++) {
            cover[i][j] = (board[i][j] == '#' ? 1: 0);
        }
    }
    search(0);
    return best;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int C;
    cin>>C;
    while(C--) {
        cin>>h>>w>>r>>c;
        board.clear();
        block.clear();
        for (int i =0; i<h; i++) {
            string t;
            cin>>t;
            board.push_back(t);
        }
        for (int i=0; i<r; i++) {
            string t;
            cin>>t;
            block.push_back(t);
        }
        generateRotations(block);
        cout<<solve()<<"\n";
    }
    
}