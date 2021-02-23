#include <bits/stdc++.h>

using namespace std;
int n,m, answer = 0, visited_cnt, visited_rev_cnt;
vector<int> adj[501], rev[501];
bool visited[501], visited_rev[501];
void dfs(int cur) {
    if (visited[cur]) return;
    visited[cur] = true;
    visited_cnt++;
    for (int i=0; i < adj[cur].size(); i++) {
        dfs(adj[cur][i]);
    } 
}
void dfs_rev(int cur) {
    if (visited_rev[cur]) return;
    visited_rev[cur] = true;
    visited_rev_cnt++;
    for (int i=0; i < rev[cur].size(); i++) {
        dfs_rev(rev[cur][i]);
    } 
}


int main() {
    cin>>n>>m;

    while(m-- >0){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        rev[b].push_back(a);
    }
    //나보다 큰애들, 작은 애들 셈
    //합이 N-1이면 성공

    //나보다 큰 학생수를 셈 ==> visited_cnt
    for (int i=1; i<=n; i++)
    {
        visited_cnt = 0;
        memset(visited, 0x00, sizeof(visited));
        dfs(i);  
        visited_rev_cnt = 0;
        memset(visited_rev, 0x00, sizeof(visited_rev));
        dfs_rev(i);
        //cout<<visited_cnt<<" "<< visited_rev_cnt<<endl;
        if (visited_rev_cnt + visited_cnt == n+1) {
            answer++;
        }
    }
    cout<<answer<<endl;
}