#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<int> adj[32001];
int indegree[32001];
queue<int> q;

int main() {
    cin>>n>>m;

    for (int i =0; i<m; i++) {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    for (int i =1; i<= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        cout<<cur<<" ";
        for (auto x: adj[cur]){
            indegree[x]--;
            if (indegree[x] == 0) {
                q.push(x);
            }
        }
    }
}