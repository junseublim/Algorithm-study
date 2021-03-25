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
        int dest = curr.first;
        int weight = curr.second;
        pq.pop();
        if (minDist[dest] < weight) continue;
        for(int j =0; j<adj[dest].size(); j++) {
            int neighbor = adj[dest][j].first;
            int neighborDist = weight + adj[dest][j].second;
            if (minDist[neighbor] > neighborDist) {
                minDist[neighbor] = neighborDist;
                pq.push(make_pair(neighbor,neighborDist));
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
    vector<int> kminDist (n+1, INF);
    for (int i=0;i<m;i++) {
        int s,d,w;
        cin>>s>>d>>w;
        adj[s].push_back(make_pair(d,w));
    }
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(make_pair(k,0));
    kminDist[k] = 0;
    while(!pq.empty()) {
        pii curr = pq.top();
        int dest = curr.first;
        int weight = curr.second;
        pq.pop();
        if (kminDist[dest] < weight) continue;
        kminDist[dest] = weight;
        for(int j =0; j<adj[dest].size(); j++) {
            if (adj[dest][j].second + kminDist[dest] < kminDist[adj[dest][j].first] ) {
                pq.push(make_pair(adj[dest][j].first, adj[dest][j].second + kminDist[dest]));
            }
        }
    }
    int mx = 0;
    for (int i=1; i<=n;i++) {
        mx = max(dijkstra(i,k) + kminDist[i], mx);
    }
    cout<<mx<<"\n";

}