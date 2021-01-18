#include <bits/stdc++.h>

using namespace std;

const int INF = 1000000;
vector<int> adj[100001];
int maxMat[100001][18] = {0};
int minMat[100001][18] = {INF};
int p[100001][18];
int w[10][10];
int n, k;
int depth[100001] = {0};
int visited[100001] = {0};


void dfs(int parent, int cur, int param_depth) {
    if (visited[cur]) return;
    visited[cur] = true;
    depth[cur] = param_depth;
    p[cur][0] = parent;
    if (cur == parent) {
        minMat[cur][0] = INF;
        maxMat[cur][0] = 0;
    }
    else {
        minMat[cur][0] = w[parent][cur];
        maxMat[cur][0] = w[parent][cur];    
    }
    for (int i =0; i<adj[cur].size(); i++) {
        dfs(cur, adj[cur][i], param_depth + 1);
    }
}

// int lca(int a, int b) {
//     //a의 깊이가 무조건 b보다 깊게 만들어서 처리 쉽게
//     if (depth[a] < depth[b]) {
//         int temp = a;
//         a =b;
//         b= temp;
//     }
//     if (depth[a] != depth[b]) {
//         int diff = depth[a] - depth[b];
//         for (int i = 0, j =1; i<=17; i++, j*=2) {
//             if (diff & j) {
//                 a = p[a][i];
//             }
//         }
//     }
//     if (a == b) return a;

//     for (int i =17 ; i>=0; i--) {
//         if (an[a][i] != an[b][i]) {
//             a= an[a][i];
//             b= an[b][i];
//         }
//     }
//     //LCA의 바로 밑에 까지
//     return an[a][0];
// }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=0; i<n-1; i++) {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back(b);
        adj[b].push_back(a);
        w[a][b] = c;
        w[b][a] = c;
    }
    for (int j = 0; j <18; j++) {
        p[1][j] = 1;
    }
    dfs(1, 1, 1);
    for (int i = 1; i<=17; i++) {
        for (int j = 1; j<=n; j++) {
            int temp = p[j][i-1];
            p[j][i] = p[temp][i-1]; //sparse table   
            minMat[j][i] = min(minMat[temp][i-1], minMat[j][i]);
            maxMat[j][i] = max(maxMat[temp][i-1], maxMat[j][i]);
        }
    }
    for (int i =1; i<=n; i++) {
        for (int j= 0; j<4; j++) {
            cout<<minMat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for (int i =1; i<=n; i++) {
        for (int j= 0; j<4; j++) {
            cout<<maxMat[i][j]<<" ";
        }
        cout<<endl;
    }
    // cin>>k;
    // for (int i =0; i<k;i++) {
    //     int a,b;
    //     cin>>a>>b;
    //     int ans = lca(a,b);
    //     cout<<ans<<"\n";
    // }
}