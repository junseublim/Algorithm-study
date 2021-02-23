#include <bits/stdc++.h>

using namespace std;
int n, m;
int p[1001];

typedef struct {
    int s;
    int d;
    int v;
} Link;

vector<Link> v;

bool cmp(Link a, Link b) {
    return a.v < b.v;
}
int findf(int a) {
    if (a==p[a]) return a;
    p[a] = findf(p[a]);
    return p[a];
}

void unionf (int a, int b) {
    a = findf(a);
    b = findf(b);
    p[a] = b;
}

int main() {
    cin>>n>>m;
    for (int i =0; i<=n; i++) {
        p[i]= i;
    }
    for (int i=0; i<m;i++) {
        int a,b,c;
        cin>>a>>b>>c;
        Link l = {a,b,c};
        v.push_back(l);
    }
    sort(v.begin(), v.end(), cmp);
    int total = 0;
    for (auto edge : v) {
        if (findf(edge.s) != findf(edge.d)){
            unionf(edge.s, edge.d);
            total += edge.v;
        }
        
    }
    cout<<total<<endl;
}