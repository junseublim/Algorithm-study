#include <bits/stdc++.h>

using namespace std;

int incoming[1001];
int build[1001];
int total[1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--) {
        int n,k;
        cin>>n>>k;
        vector<int> outgoing[1001];
        memset(incoming, 0, sizeof(incoming));
        memset(total, 0, sizeof(total));
        for (int i =1; i<=n; i++) {
            cin>>build[i];
        }
        for (int i=0; i<k; i++) {
            int s,d;
            cin>>s>>d;
            incoming[d]++;
            outgoing[s].push_back(d);
        }
        int w;
        cin>>w;
        queue<int> q;
        for (int i=1; i<=n; i++) {
            if (incoming[i] == 0) {
                total[i] = build[i];
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            int s= q.front();
            q.pop();
            if (s == w) {
                break;
            }
            for (int i =0; i<outgoing[s].size(); i++) {
                int d = outgoing[s][i];
                total[d] = max(total[d], total[s] + build[d]);
                incoming[d]--;
                if (incoming[d] == 0) {
                    q.push(d);
                }
            }
        }
        cout<<total[w]<<"\n";




    }

}