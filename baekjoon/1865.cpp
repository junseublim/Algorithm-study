#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
vector<pii> edges[501];
vector<pii> hole[501];
vector<pii> hse;
int holeTime[200];

int go(int s, int e) {
    queue<pii> q;
    q.push(make_pair(s,0));
    int visited[501];
    for (int i =0; i<501; i++ ) {
        visited[i] = 987654321;
    }
    while(!q.empty()) {
        pii nxt = q.front();
        q.pop();
        if (visited[nxt.first] <= nxt.second) continue;
        visited[nxt.first] = nxt.second;
        for (int i =0; i<edges[nxt.first].size(); i++) {
            q.push(make_pair(edges[nxt.first][i].first , nxt.second + edges[nxt.first][i].second ));
        }
        for (int i =0; i<hole[nxt.first].size(); i++) {
            q.push(make_pair(edges[nxt.first][i].first , nxt.second - edges[nxt.first][i].second ));
        }
    }
    return visited[e];
}


int main() {
    int T;
    cin>>T;
    while(T--) {
        int n,m,w;
        cin>>n>>m>>w;
        for (int i =0; i<501; i++) {
            edges[i].clear();
            hole[i].clear();
        }
        hse.clear();
        for (int i =0; i<m; i++) {
            int s,e,t;
            cin>>s>>e>>t;
            edges[s].push_back(make_pair(e,t));
            edges[e].push_back(make_pair(s,t));
        }
        for (int i =0; i<w; i++) {
            int s,e,t;
            cin>>s>>e>>t;
            hole[s].push_back(make_pair(e,t));
            hse.push_back(make_pair(s,e));
            holeTime[i] = t;
        }
        int found = 0;
        for (int i =0; i<hse.size(); i++) {
            int dist = go(hse[i].second, hse[i].first);
            if (dist < holeTime[i]) found = 1;
        }
        if (found) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
}