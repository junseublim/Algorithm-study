#include <bits/stdc++.h>
using namespace std;
vector<int> parent(100001, 0);
vector<int> adj[100001];
vector<int> visited(100001, 0);

void dfs(int node) {
    if (visited[node]) return;
    visited[node] = 1;
    for (int i = 0; i<adj[node].size(); i++) {
        if (parent[adj[node][i]]) continue;
        parent[adj[node][i]] = node;
        dfs(adj[node][i]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;

    cin>>n;
    for (int i=0; i<n-1; i++) {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    for (int i =2; i<=n; i++) {
        cout<<parent[i]<<"\n";
    }
}