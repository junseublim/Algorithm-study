#include <bits/stdc++.h>

using namespace std;

int visited[100001];
int n, k;
queue<pair<int,int> > q;
int main() {
    cin>>n>>k;
    q.push(make_pair(n,0));
    while(!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        if (visited[curr.first]) continue;
        if (curr.first == k) {
            cout<<curr.second<<endl;
            return 0;
        }
        visited[curr.first] = 1;
        if (curr.first -1 >=0) q.push(make_pair(curr.first-1, curr.second+1));
        if (curr.first +1 <100001)q.push(make_pair(curr.first+1, curr.second+1));
        if (curr.first*2 <100001)q.push(make_pair(curr.first*2, curr.second+1));
    }   

}