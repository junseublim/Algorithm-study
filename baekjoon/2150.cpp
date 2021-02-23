#include <bits/stdc++.h>

using namespace std;

int v,e;

vector<int> firstE[10001];
vector<int> secondE[10001];
int visited[10001];
stack<int> s;
vector<int> temp;
vector< vector<int> > ans;

bool cmp(vector<int> a, vector<int> b) {
    return a[0] < b[0];
}

void dfs1(int ind) {
    if (visited[ind] == 1) {
        return;
    }
    visited[ind] = 1;
    for (int i =0; i<firstE[ind].size(); i++) {
        dfs1(firstE[ind][i]);
    }
    s.push(ind);
}
void dfs2(int ind) {
    if (visited[ind] == 1) {
        return;
    }
    visited[ind] = 1;
    temp.push_back(ind);
    for (int i =0; i<secondE[ind].size(); i++) {
        dfs2(secondE[ind][i]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>v>>e;
    for (int i=0; i<e; i++) {
        int a,b;
        cin>>a>>b;
        firstE[a].push_back(b);
        secondE[b].push_back(a);
    }
    for (int i=1; i<=v; i++) {
        dfs1(i);
    }
    memset(visited, 0, sizeof(visited));
    while(s.size()) {
        temp.assign(0,0);
        int next = s.top();
        s.pop();
        dfs2(next);
        if (temp.size()){
            sort(temp.begin(), temp.end());
            ans.push_back(temp);
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    cout<<ans.size()<<"\n";
    for (int i =0; i<ans.size(); i++) {
        for (int j=0; j<ans[i].size(); j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<"-1"<<"\n";
    }
}