#include <bits/stdc++.h>

using namespace std;
vector<int> adj[101];
int visited[101];
int main() {
    int n,e;
    cin>>n>>e;
    for (int i= 0; i<e; i++) {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> q;
    
    q.push(1);
    int cnt = -1;
    while(!q.empty()) {
        int curr=  q.front();
        q.pop();
        if (visited[curr]) continue;
        cnt++;
        visited[curr] = 1;
        for (int i =0; i<adj[curr].size(); i++) {
            q.push(adj[curr][i]);
        }
    }
    cout<<cnt<<endl;
}