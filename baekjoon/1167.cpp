#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
int n;
vector<pii> v[100001];
int visited[100001];
int furthest;
int dist = 0;
void dfs(int node, int d) {
    if (visited[node] != 0) return;
    visited[node] = 1;
    if (d > dist) {
        furthest = node;
        dist = d;
    }
    for (int i=0; i<v[node].size(); i++) {
        dfs(v[node][i].first, d+v[node][i].second);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++) {
        int s,temp;
        cin>>s;
        cin>>temp;
        int k =0;
        while(temp != -1) {
            int w; 
            cin>>w;
            v[s].push_back(make_pair(temp,w));
            cin>>temp;
        }
    }
    memset(visited, 0, sizeof(visited));
    dfs(1,0);
    memset(visited, 0, sizeof(visited));
    dist = 0;
    dfs(furthest, 0);
    cout<<dist<<"\n";
}