#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<int>nums;
vector<int> visited;
vector<int> seq;
set<string> s;
vector<string> ans;
void dfs(int cnt) {
    if (cnt == m) {
        string temp = "";
        for (int i =0; i<seq.size(); i++) {
            temp.append(to_string(seq[i]));
            if (i == seq.size()-1) continue;
            temp.append(" ");
        }
        if (s.count(temp)) return;
        s.insert(temp);
        ans.push_back(temp);
        return;
    }
    for (int i=0; i<n; i++) {
        if (!visited[i]){
            visited[i] = true;
            seq.push_back(nums[i]);
            dfs(cnt+1);
            seq.pop_back();
            visited[i] = false;
        }
        
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    nums.assign(n, 0);
    visited.assign(n, 0);
    for (int i =0; i<n; i++) {
        cin>>nums[i];
    }
    sort(nums.begin(), nums.end());

    // for (auto x: nums) {
    //     cout<<x<<"\n";
    // }
    for (int i=0; i<n; i++) {
        visited[i] = true;
        seq.push_back(nums[i]);
        dfs(1);
        seq.pop_back();
        visited[i] = false;
    }
    for (auto x: ans) {
        cout<<x<<"\n";
    }
}