#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
int n,m;
int table[500][500];
int visited[500][500];
int moveY[] = {0,0,-1,1};
int moveX[] = {-1,1,0,0};
int maxScore = 0;

pii blocks[19][4] = {
    {make_pair(0,0),make_pair(0,1),make_pair(0,2),make_pair(0,3)},
    {make_pair(0,0),make_pair(1,0),make_pair(2,0),make_pair(3,0)},
    {make_pair(0,0),make_pair(0,1),make_pair(1,0),make_pair(1,1)},
    {make_pair(0,0),make_pair(0,1),make_pair(0,2),make_pair(1,0)},
    {make_pair(0,0),make_pair(0,1),make_pair(0,2),make_pair(1,2)},
    {make_pair(0,0),make_pair(1,0),make_pair(1,1),make_pair(1,2)},
    {make_pair(0,0),make_pair(0,1),make_pair(0,2),make_pair(-1,2)},
    {make_pair(0,0),make_pair(0,1),make_pair(1,0),make_pair(2,0)},
    {make_pair(0,0),make_pair(0,1),make_pair(1,1),make_pair(2,1)},
    {make_pair(0,0),make_pair(1,0),make_pair(2,0),make_pair(2,1)},
    {make_pair(0,0),make_pair(0,1),make_pair(-1,1),make_pair(-2,1)},
    {make_pair(0,0),make_pair(1,0),make_pair(1,1),make_pair(2,1)},
    {make_pair(0,0),make_pair(0,1),make_pair(-1,1),make_pair(-1,2)},
    {make_pair(0,0),make_pair(0,1),make_pair(1,1),make_pair(1,2)},
    {make_pair(0,0),make_pair(-1,0),make_pair(-1,1),make_pair(-2,1)},
    {make_pair(0,0),make_pair(0,1),make_pair(-1,1),make_pair(0,2)},
    {make_pair(0,0),make_pair(0,1),make_pair(1,1),make_pair(0,2)},
    {make_pair(0,0),make_pair(1,0),make_pair(1,1),make_pair(2,0)},
    {make_pair(0,0),make_pair(0,1),make_pair(-1,1),make_pair(1,1)}
};


void take(int y, int x) {
    
    for (int i = 0; i<19; i++) {
        int score = 0;
        bool possible = true;
        for (int j=0; j<4; j++) {
            if (y+blocks[i][j].first <0 || y+blocks[i][j].first >= n || x+blocks[i][j].second >= m) {
                possible = false;
                break;
            }
            score += table[y+blocks[i][j].first][x+blocks[i][j].second];
        }
        if (possible) {
            maxScore = max(maxScore,score);
        }
    }
}

int main() {
    cin>>n>>m;
    for(int i =0; i<n; i++) {
        for (int j=0;j<m; j++) {
            cin>>table[i][j];
        }
    }
    for(int i =0; i<n; i++) {
        for (int j=0;j<m; j++) {
            take(i,j);
        }
    }
    cout<<maxScore<<endl;

}