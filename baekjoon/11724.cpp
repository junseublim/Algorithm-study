#include <bits/stdc++.h>

using namespace std;
int n,m;
vector<int> adj[1001];
int visited[1001];

void dfs(int node) {
    if(visited[node]) return;
    visited[node] = 1;
    for (int i =0; i<adj[node].size(); i++) {
        dfs(adj[node][i]);
    }
}

int main() {
    cin>>n>>m;
    for(int i =0; i<m; i++) {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int cnt = 0;
    for (int i = 1; i<=n; i++) {
        if (!visited[i]) {
            cnt++;
            dfs(i);
        }
    }
    cout<<cnt<<endl;
}