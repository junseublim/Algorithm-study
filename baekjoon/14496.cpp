#include <bits/stdc++.h>

using namespace std;


int n,m;
int a,b;
int visited[1001];
vector<int> adj[1001];
typedef pair<int,int> pii;
queue<pii> q;
int main() {
    cin>>a>>b;
    cin>>n>>m;
    
    for (int i =0; i<m; i++) {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    q.push(make_pair(a,0));
    while(!q.empty()) {
        pii nxt = q.front();
        q.pop();
        if (nxt.first == b) {
            cout<<nxt.second<<endl;
            return 0;
        }
        if (visited[nxt.first]) continue;
        visited[nxt.first] = 1;
        for (int i =0; i<adj[nxt.first].size(); i++) {
            q.push(make_pair(adj[nxt.first][i], nxt.second+1));
        }
    }
    cout<<-1<<endl;


}