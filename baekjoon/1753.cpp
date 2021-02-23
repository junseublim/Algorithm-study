#include <bits/stdc++.h>

using namespace std;
int v,e;
int start;
const int INF = 200001;
typedef struct {
    int s;
    int d;
    int w;
} Edge;

struct cmp{
    bool operator()(Edge a, Edge b){
        return a.w < b.w;
    }
};
typedef pair<int, int> pii; 
vector<pii> adj[20001];
priority_queue<pii, vector<pii>, greater<pii>> pq;
int dest[20001];
int done[20001];
int cnt = 1;
int main() {
    cin>>v>>e>>start;
    for (int i = 0; i<e; i++) {
        int x,y,z;
        cin>>x>>y>>z;
        adj[x].push_back({y,z});
    }
    for (int i =1; i<= v; i++) {
        dest[i] = INF;
    }
    dest[start] = 0;
    pq.push({0,start});
    done[start] = 1;
    while(!pq.empty()) {
        pii du = pq.top();
        int d = du.first;
        int u = du.second;
        pq.pop();
        done[u] = 1;
        for (auto x: adj[u]) {
            if (done[x.first]) continue;
            if (dest[x.first] > x.second + dest[u]){
                dest[x.first] = x.second + dest[u];
                pq.push({dest[x.first], x.first});
            }
        }
    }
    for (int i = 1; i<=v; i++) {
        if (dest[i] == INF) {
            cout<<"INF\n";
        }
        else {
            cout<<dest[i]<<"\n";
        }
    }


}