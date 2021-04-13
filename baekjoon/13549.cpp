#include <bits/stdc++.h>

using namespace std;
int n,k;
int dp[100001];
typedef pair<int,int> pii;
void go (int x) {
    queue<pii> q;
    q.push(make_pair(n, 0));
    while(!q.empty()) {
        pii nxt = q.front();
        q.pop();
        if (nxt.first < 0 || nxt.first > 100000) continue;
        if (dp[nxt.first] != -1 && dp[nxt.first] <= nxt.second) continue;
        dp[nxt.first] = nxt.second;

        q.push(make_pair(nxt.first-1, nxt.second+1));
        q.push(make_pair(nxt.first+1, nxt.second+1));
        q.push(make_pair(nxt.first*2, nxt.second));
    }
    return;
}


int main() {
    memset(dp, -1, sizeof(dp));
    cin>>n>>k;
    go(n);
    cout<<dp[k]<<endl;
}