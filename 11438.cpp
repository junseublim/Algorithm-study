#include <bits/stdc++.h>

using namespace std;

int n,m,    depth[100001], an[100001][18]; // 2^0 ... 2^17번째 조상을 담음
vector<int> adj[100001];
bool visited[100001];

void dfs(int parent, int cur, int param_depth) {
    if (visited[cur]) return;
    visited[cur] = true;
    depth[cur] = param_depth;
    an[cur][0] = parent;
    for (int i =0; i<adj[cur].size(); i++) {
        dfs(cur, adj[cur][i], param_depth + 1);
    }
}

int lca(int a, int b) {
    //a의 깊이가 무조건 b보다 깊게 만들어서 처리 쉽게
    if (depth[a] < depth[b]) {
        int temp = a;
        a =b;
        b= temp;
    }
    if (depth[a] != depth[b]) {
        int diff = depth[a] - depth[b];
        for (int i = 0, j =1; i<=17; i++, j*=2) {
            if (diff & j) {
                a = an[a][i];
            }
        }
    }
    if (a == b) return a;

    for (int i =17 ; i>=0; i--) {
        if (an[a][i] != an[b][i]) {
            a= an[a][i];
            b= an[b][i];
        }
    }
    //LCA의 바로 밑에 까지
    return an[a][0];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=0; i<n-1; i++) {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    //LCA를 위한 자료 수집: 깊이, 1/2/4/..... 조상
    //dfs 사용
    dfs(1, 1, 1);
    //2^1, 2^2,2^3... 조상 구하기
    for (int i = 1; i<=17; i++) {
        for (int j = 1; j<=n; j++) {
            int temp = an[j][i-1];
            an[j][i] = an[temp][i-1]; //sparse table   
        }
    }
    
    cout<<endl;
    cin>>m;
    for (int i =0; i<m; i++) {
        int a,b;
        cin>>a>>b;
        int ans = lca(a,b);
        cout<<ans<<"\n";
    }

}