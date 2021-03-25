#include <bits/stdc++.h>

using namespace std;
const int INF = 987654321;
int n,m,k;
typedef pair<int,int> pii;

vector<pii> adj [1001];

int dijkstra(int s, int d) {
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(make_pair(s,0));
    vector<int> minDist(n+1, INF);
    minDist[s] = 0;
    while(!pq.empty()) {
        pii curr = pq.top();
        pq.pop();
        if (minDist[curr.first] < curr.second) continue;
        minDist[curr.first] = curr.second;
        for(int j =0; j<adj[curr.first].size(); j++) {
            if (adj[curr.first][j].second + minDist[curr.first] < minDist[adj[curr.first][j].first] ) {
                pq.push(make_pair(adj[curr.first][j].first, adj[curr.first][j].second + minDist[curr.first]));
            }
        }
    }
    return minDist[d];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for (int i=0;i<m;i++) {
        int s,d,w;
        cin>>s>>d>>w;
        adj[s].push_back(make_pair(d,w));
    }
    int mx = 0;
    for (int i=1; i<=n;i++) {
        mx = max(dijkstra(i,k) + dijkstra(k,1), mx);
    }
    cout<<mx<<"\n";

}