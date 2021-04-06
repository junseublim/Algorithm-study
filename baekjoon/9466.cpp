#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100001];
int found[100001];
int hasPartner[100001];

void dfs(int x) {
    if (found[x] == 2) {
        return;
    }
    else if (found[x] == 1)  {
        hasPartner[x] = 1;
        found[x] = 2;
    }
    else {
        found[x] = 1;
    }
    bool partner = false;
    for (int i =0; i<adj[x].size(); i++) {
        dfs(adj[x][i]);
    }
    found[x] = 2;


}

int main() {
    int T;
    cin>>T;
    while(T--) {
        for (int i =0; i<100001; i++) {
            adj[i].clear();
            found[i] = 0;
            hasPartner[i] = 0;
        }
        int n; cin>>n;
        for(int i =1; i<=n; i++) {
            int a; cin>>a;
            adj[i].push_back(a);
        }
        int cnt = 0;
        for(int i =1; i<=n; i++) {
            dfs(i); 
        }
        for(int i =1; i<=n; i++) {
            cnt += hasPartner[i];
        }
        cout<<n-cnt<<endl;
    }
}