#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;
short n,m;
vector<vector<short>> town;
vector<pair<short,short>> chicken;
vector<pair<short,short>> house;
int totalDist = 987654321;
const int INF = 987654321;


void getChickenDist() {
    int accumDist = 0;
    for (auto h : house) {
        int dist = INF;
        for (auto c: chicken) {
            if (town[c.first][c.second]) {
                dist = min(dist, abs(h.first-c.first) + abs(h.second - c.second));
            }
        }
        accumDist += dist;
    }
    totalDist = min(accumDist, totalDist);
}


void dfs(short pos, short count) {
    if (count == m) {
        getChickenDist();
        return;
    }
    if (pos == chicken.size())
        return;

    town[chicken[pos].first][chicken[pos].second] = 2;
    dfs(pos+1, count+1);
    town[chicken[pos].first][chicken[pos].second] = 0;
    dfs(pos+1, count);
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    town.assign(n, vector<short>(n));
    for (short i=0; i<n; i++) {
        for (short j= 0; j<n; j++) {
            cin>>town[i][j];
            if (town[i][j] == 1) {
                house.push_back({i,j});
            }
            else if (town[i][j] == 2) {
                chicken.push_back({i,j});
                town[i][j] = 0;
            }
        }
    }
    dfs(0, 0);
    cout<<totalDist<<endl;  

}