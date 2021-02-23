#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<pair<int, int> > dist[1001];
queue<int> q;
vector<int> dijk;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    dijk.assign(n+1, 100000*1001);
    for (int i =0; i<m; i++) {
        int a,b,c;
        cin>>a>>b>>c;
        dist[a].push_back(make_pair(b, c));
    }
    int s, d;
    cin>>s>>d;
    dijk[s] = 0;
    q.push(s);
    while(!q.empty()) {
        int next = q.front();
        q.pop();
        for (int i =0; i<dist[next].size(); i++) {
            int dest = dist[next][i].first;
            if (dijk[dest] > dist[next][i].second + dijk[next]) {
                dijk[dest] = dist[next][i].second + dijk[next];
                q.push(dest);
            }
        }
    }
    cout<<dijk[d]<<endl;

}