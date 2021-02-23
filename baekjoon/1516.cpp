#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> adj[501];
vector<int> initialTime(501,0);
vector<int> timeTaken(501,0);
vector<int> inDegree(501,0);
queue<int> q;
int main() {
    cin>>n;
    timeTaken.resize(n+1);
    for (int i =1; i<=n; i++) {
        int a,b;
        cin>>a;
        initialTime[i] = a;
        timeTaken[i] = a;
        while(true) {
            cin>>b;
            if (b == -1) break;
            adj[b].push_back(i);
            inDegree[i]++;
        }
    }
    for (int i =1; i<=n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
            //cout<<"pushed "<<i<<endl;
        }
    }
    int prev = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i =0; i< adj[cur].size(); i++) {
            timeTaken[adj[cur][i]] = max(timeTaken[adj[cur][i]], initialTime[adj[cur][i]] + timeTaken[cur]);
            inDegree[adj[cur][i]]--;
            if (inDegree[adj[cur][i]] == 0) {
                q.push(adj[cur][i]);
                //cout<<"pushed "<<adj[cur][i]<<endl;
            }
        }
    }
    for (int i =1; i<=n; i++) {
        cout<<timeTaken[i]<<endl;
    }

}