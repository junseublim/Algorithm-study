#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> tri[500];
vector<int> ans[500];
int mx = 0;
void dfs(int level) {
    if (level == n-1) {
        for (auto x: ans[level]){
            mx = max(mx, x);
        }
        
        return;
    }
    for (int i =0; i<ans[level].size(); i++) {
        ans[level+1][i] = max(ans[level+1][i], ans[level][i] + tri[level+1][i]);
        ans[level+1][i+1] = max(ans[level+1][i+1], ans[level][i] + tri[level+1][i+1]);
    }
    dfs(level+1);

}

int main() {
    cin>>n;

    for (int i =0; i<n; i++) {
        for (int j=0; j<i+1; j++) {
            int temp;
            cin>>temp;
            tri[i].push_back(temp);
            ans[i].push_back(0);
        }
    }
    ans[0][0] = tri[0][0];
    dfs(0);
    cout<<mx<<endl;
}