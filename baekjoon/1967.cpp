#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
vector<pii> edges[10001];
int visited[10001];
int furthest;
int dist = -1;

void dfs(int x, int d) {
    if (visited[x] != -1) return;
    visited[x] = 1;
    if (d > dist) {
        furthest = x;
        dist = d;
    }
    for (int i =0; i<edges[x].size(); i++) {
        dfs(edges[x][i].first, d + edges[x][i].second);
    }
}

int main() {
    int n;
    cin>>n;
    for (int i =0; i<n-1; i++) {
        int s,d,w;
        cin>>s>>d>>w;
        edges[s].push_back(make_pair(d,w));
        edges[d].push_back(make_pair(s,w));
    }
    memset(visited, -1, sizeof(visited));
    dfs(1,0);
    dist = 0;
    memset(visited, -1, sizeof(visited));
    dfs(furthest,0);
    cout<<dist<<endl;
}