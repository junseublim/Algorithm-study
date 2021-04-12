#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
vector<pii> edges[501];
int dist[501];


int main() {
    int T;
    cin>>T;
    while(T--) {
        int n,m,w;
        cin>>n>>m>>w;
        for (int i =0; i<501; i++) {
            edges[i].clear();
            dist[i] = 987654321;
        }
        for (int i =0; i<m; i++) {
            int s,e,t;
            cin>>s>>e>>t;
            edges[s].push_back(make_pair(e,t));
            edges[e].push_back(make_pair(s,t));
        }
        for (int i =0; i<w; i++) {
            int s,e,t;
            cin>>s>>e>>t;
            edges[s].push_back(make_pair(e,-1*t));
        }
        int found = 0;
        for (int l = 1; l <= n; l++) {
            if (dist[l] == 987654321) dist[l] = 0;
            else continue;
            for (int i = 1; i<=n; i++) {
                for (int j =1; j<=n; j++) {
                    for (int k =0; k<edges[j].size(); k++) {
                        int d = edges[j][k].first;
                        int cost = edges[j][k].second;
                        dist[d] = min(dist[d], dist[j]+cost);
                    }
                }
            }
        }
        for (int i =1; i<=n; i++) {
            for (int j = 0; j<edges[i].size(); j++) {
                int d = edges[i][j].first;
                int cost = edges[i][j].second;
                if (dist[d] > cost + dist[i]) {
                    found = 1;
                    break;
                }
            }
            if (found)break;
        }
        if (found) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
}