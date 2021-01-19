#include <bits/stdc++.h>

using namespace std;
int v,e;
vector<int> adj[100001];
bool visited[100001];
int visited_num[100001];
vector<pair<int,int>> ans;
int num = 1;

int dfs(int parent, int cur, bool isRoot) {
    if (visited[cur]) {
        return 0;
    }
    visited[cur] = true;
    int min_visited = num;
    visited_num[cur] = num++;
    int smaller_num = 1;
    for (int i=0; i<adj[cur].size(); i++) {
        //이미 visited이면 num값 비교 후 min 세팅
        if (adj[cur][i] == parent) continue;
        if (visited[adj[cur][i]]) {
            if (visited_num[adj[cur][i]] < visited_num[cur])
               smaller_num++;
            min_visited = min(min_visited, visited_num[adj[cur][i]]);
        }
        else{
            int temp = dfs(cur, adj[cur][i], false);
            min_visited = min(min_visited, temp);
        }
    }
    //cout<<"current : "<<cur<<" min visited : "<<min_visited<< " visited_num[parent] : "<<visited_num[parent]<<endl;
    if (!isRoot && min_visited > visited_num[parent]) {
        //단절점 발견9
        if (smaller_num == 1) {
            if (parent > cur ){
                ans.push_back({cur, parent});
            }
            else{
                ans.push_back({parent,cur});
            }
            
        }
    }
    return min(min_visited,visited_num[cur]);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>v>>e;
    for (int i =0; i<e; i++) {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i= 1; i<=v; i++) {
        if (!visited[i]){
            dfs(0, i, true);
        }   
    }
    sort(ans.begin(), ans.end());
    cout<<ans.size()<<"\n";
    for (auto x: ans) {
        cout<<x.first<< " "<<x.second<<"\n";
    }
    

}