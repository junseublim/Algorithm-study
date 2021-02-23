#include <bits/stdc++.h>

using namespace std;

int n,m;
typedef long long ll;
const ll INF = 987654321;
typedef struct Edge{
    int s;
    int d;
    int w;
    Edge(int ss,int dd,int ww) {
        s= ss;
        d= dd;
        w =ww;
    }
} Edge;


ll dest[501];
vector<Edge> v;

int main() {
    cin>>n>>m;
    for (int i =1; i<=n; i++) {
        dest[i] = INF;
    }
    dest[1] = 0;
    for(int i = 0; i< m; i++) {
        int a,b,c;
        cin>>a>>b>>c;
        Edge e = Edge(a,b,c);
        v.push_back(e);
    }
    for (int i =0; i<n-1; i++) {
        for (auto x: v) {
            if (dest[x.s] == INF) continue; 
            if (dest[x.d] > dest[x.s] + x.w) {
                dest[x.d] = dest[x.s] + x.w;
            }
        }
    }
    for (auto x: v) {
        if (dest[x.s] == INF) continue; 
        if (dest[x.d] > dest[x.s] + x.w) {
            cout<<-1<<endl;
            return 0;
        }
    }
    for (int i = 2; i <=n; i++) {
        if (dest[i] == INF)  {
            cout<<-1<<endl;
        }
        else cout<<dest[i]<<endl;
    }


}