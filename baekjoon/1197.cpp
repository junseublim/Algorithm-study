#include <bits/stdc++.h>

using namespace std;
int v,e;
typedef pair<int,int> pii;
typedef struct Adj {
    int s;
    int d;
    int w;
    Adj(int ss,int dd, int ww){
        s=ss;
        d=dd;
        w=ww;
    }
} Adj;

struct cmp {
    bool operator()(Adj a, Adj b) {
        return a.w > b.w;
    }
};

priority_queue<Adj, vector<Adj>, cmp> pq;

int parent[10001];

int Find(int a) {
    if (parent[a] == a) return a;
    else {
        parent[a] = Find(parent[a]);
        return parent[a];
    }
}
void Union(int a, int b) {
    int pa = Find(a);
    int pb = Find(b);
    if (pa == pb) return;
    else {
        if (pa < pb) parent[pb]= pa;
        else parent[pa] = pb;
    }
}

int minV = 0;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>v>>e;
    for (int i = 1; i<=v; i++) {
        parent[i]= i;
    }
    for (int i =0; i<e; i++) {
        int a,b,c;
        cin>>a>>b>>c;
        pq.push(Adj(a,b,c));
    }
    while(pq.size()) {
        Adj next = pq.top();
        pq.pop();
        if (Find(next.s) == Find(next.d)) continue;
        else {
            Union(next.s,next.d);
            minV += next.w;
        }
        
    }
    cout<<minV<<"\n";
}