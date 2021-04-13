#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
int items[101];
vector<pii> adj[101];
int n,m,r;
int dist[101];
typedef struct Node {
    int s;
    int d;
    int t;
    Node (int ss, int dd,int tt){
        s=ss;
        d=dd;
        t=tt;
    }
} Node;

struct cmp {
    bool operator()(pii a, pii b) {
        if (a.second > b.second) return true;
        return false;
    }
};

int dijkstra(int x) {
    
    for (int i =0; i<101; i++) {
        dist[i] = 987654321;
    }
    dist[x] = 0;
    priority_queue<pii, vector<pii>, cmp> pq;
    for (int i =0; i<adj[x].size(); i++) {
        dist[adj[x][i].first] = dist[x] + adj[x][i].second;
        pq.push(make_pair(adj[x][i].first, dist[adj[x][i].first]));
    }
    int selected[101];
    memset(selected, 0 , sizeof(selected));
    while(!pq.empty()) {
        pii nxt = pq.top();
        pq.pop();
        if (selected[nxt.first]) continue;
        selected[nxt.first] = 1;
        for (int i =0; i<adj[nxt.first].size(); i++) {
            dist[adj[nxt.first][i].first] = min(dist[adj[nxt.first][i].first], nxt.second + adj[nxt.first][i].second);
            pq.push(make_pair(adj[nxt.first][i].first, dist[adj[nxt.first][i].first]));
        }
    }
    int c = 0;
    for (int i =1; i<=n; i++) {
        if ( dist[i] <= m) {
            c+= items[i];
        }
    }
    return c;
}

int main() {
    
    cin>>n>>m>>r;
    for (int i =1; i<=n; i++) {
        cin>>items[i];
    }
    for (int i =0; i<r; i++) {
        int s,d,t;
        cin>>s>>d>>t;
        adj[s].push_back(make_pair(d,t));
        adj[d].push_back(make_pair(s,t));
    }
    int collect = 0;
    for (int i =1; i<=n; i++) {
        collect = max(collect, dijkstra(i));
    }
    cout<<collect<<endl;
}