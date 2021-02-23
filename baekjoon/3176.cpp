#include <bits/stdc++.h>

using namespace std;

const int INF = 1000000;
vector<pair<int,int>> adj[100001];
int maxMat[100001][18];
int minMat[100001][18];
int p[100001][18];
int n, k;
int depth[100001] = {0};
bool visited[100001] = {0};


void dfs(int parent, int cur,int w, int param_depth) {
    if (visited[cur]) return;
    visited[cur] = true;
    depth[cur] = param_depth;
    p[cur][0] = parent;
    if (cur == parent) {
        minMat[cur][0] = INF;
        maxMat[cur][0] = 0;
    }
    else {
        minMat[cur][0] = w;
        maxMat[cur][0] = w;    
    }
    for (int i =0; i<adj[cur].size(); i++) {
        dfs(cur, adj[cur][i].first, adj[cur][i].second, param_depth + 1);
    }
}

void lca(int a, int b) {
    //a의 깊이가 무조건 b보다 깊게 만들어서 처리 쉽게
    if (depth[a] < depth[b]) {
        int temp = a;
        a =b;
        b= temp;
    }
    int minimum = INF;
    int maximum = 0;
    

    if (depth[a] != depth[b]) {
        minimum = min(minMat[a][0], minimum);
        maximum = max(maxMat[a][0], maximum);
        int diff = depth[a] - depth[b];
        // cout<<"diff "<<diff<<endl;
        for (int i = 0, j =1; i<=17; i++, j*=2) {
            if (diff & j) {
                // cout<<"i: "<<i<<" j : "<<j<<endl;
                // cout<<"parent "<<p[a][i]<<" "<< minMat[p[a][i]][i]<<endl;
                // minimum = min(minimum, minMat[a][i]);
                // maximum = max(maximum, maxMat[a][i]);
                a = p[a][i];
            }
        }
    }
    else {
        minimum = min(minMat[a][0], minMat[b][0]);
        maximum = max(maxMat[a][0], maxMat[b][0]);
    }
    for (int i =17 ; i>=0; i--) {
        if (p[a][i] != p[b][i]) {
            cout<<"parent of a : "<<p[a][i]<<" not equal to "<<p[b][i]<<endl;
            cout<<"minMat[a][i] : "<<minMat[p[a][i]][i]<<endl;
            cout<<"maxMat[a][i] : "<<maxMat[p[a][i]][i]<<endl;
            cout<<"minMat[b][i] : "<<minMat[p[b][i]][i]<<endl;
            cout<<"maxMat[b][i] : "<<maxMat[p[b][i]][i]<<endl;
            minimum = min(minimum, minMat[p[a][i]][i]);
            maximum = max(maximum, maxMat[p[a][i]][i]);
            minimum = min(minimum, minMat[p[b][i]][i]);
            maximum = max(maximum, maxMat[p[b][i]][i]);
            a= p[a][i];
            b= p[b][i];
        }
    }
    //LCA의 바로 밑에 까지

    cout<<minimum<<" "<<maximum<<"\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=0; i<n-1; i++) {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    memset(minMat, INF, sizeof(minMat));
    memset(maxMat, 0, sizeof(maxMat));
    dfs(1, 1, 1, 1);
    for (int i = 1; i<=17; i++) {
        for (int j = 1; j<=n; j++) {
            int temp = p[j][i-1];
            p[j][i] = p[temp][i-1]; //sparse table   
            minMat[j][i] = min(minMat[temp][i-1], minMat[j][i-1]);
            maxMat[j][i] = max(maxMat[temp][i-1], maxMat[j][i-1]);
        }
    }
    for (int i =1; i<n+1; i++){
        for(int j = 0; j<4; j++) {
            cout<<minMat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for (int i =1; i<n+1; i++){
        for(int j = 0; j<4; j++) {
            cout<<maxMat[i][j]<<" ";
        }
        cout<<endl;
    }
    cin>>k;
    for (int i =0; i<k;i++) {
        int a,b;
        cin>>a>>b;
        lca(a,b);   
    }
}