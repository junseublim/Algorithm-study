#include <bits/stdc++.h>

using namespace std;
int n;
const int INF  = 987654321;
int cave[125][125];
int dijk[125][125];
int my[4] = {0,0,-1,1};
int mx[4] = {-1,1,0,0};
int main() {
    int problem = 0;
    cin>>n;
    while(n!= 0) {
        problem++;
        for (int i =0; i<n; i++) {
            for (int j =0; j<n; j++) {
                cin>>cave[i][j];
                dijk[i][j] = INF;
            }
        }
        dijk[0][0] = cave[0][0];
        set<int> s;
        priority_queue<pair<int,int> , vector<pair<int,int> >, greater<pair<int, int> > > pq;
        for (int i =0; i<n; i++) {
            for (int j =0; j<n; j++) {
                pq.push(make_pair(dijk[i][j], i*n+j));
            }
        }
        while(s.size() < (n*n)) {   
            pair<int,int> nxt = pq.top();
            pq.pop();
            if (s.count(nxt.second) > 0) continue;
            s.insert(nxt.second);
            int curr = nxt.first;
            int y = nxt.second / n;
            int x = nxt.second % n;

            for (int i =0; i<4; i++) {
                if (y+my[i] >=0 && y+my[i] < n && x+mx[i] >= 0 && x+mx[i] < n) {
                    if (dijk[y+my[i]][x+mx[i]] > dijk[y][x] + cave[y+my[i]][x+mx[i]]) {
                        dijk[y+my[i]][x+mx[i]] = dijk[y][x] + cave[y+my[i]][x+mx[i]];
                        pq.push(make_pair(dijk[y+my[i]][x+mx[i]], (y+my[i])*n+(x+mx[i])));
                    }
                }
            }
        }
        cout<<"Problem "<<problem<<": "<<dijk[n-1][n-1]<<endl;
        cin>>n;
        
    }
}