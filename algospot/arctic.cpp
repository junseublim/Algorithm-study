#include <bits/stdc++.h>

using namespace std;
int m;
typedef pair<double, double> pdd;
vector<pdd> v;
double dist[100][100];
int parent[100];


void getDist() {
    for (int i =0; i<m; i++) {
        for (int j=0; j<m; j++) {
            dist[i][j] = sqrt(pow(v[i].first - v[j].first,2) + pow(v[i].second - v[j].second,2));
        }
    }
    // cout<<"dist"<<endl;
    // for (int i =0; i<m; i++) {
    //     for (int j=0; j<m; j++) {
    //        cout<<dist[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}


bool decision(double mid) {
    vector<bool> visited(m ,false);
    queue<int> q;
    q.push(0);
    int seen = 0;
    while(!q.empty()) {
        int idx = q.front();
        q.pop();
        if (visited[idx]) continue;
        visited[idx] = true;
        seen++;
        for (int j= 0; j<m; j++) {
            if (dist[idx][j] <= mid) {
                q.push(j);
            }
        }
    }
    return (seen == m);
}

int main() {
    int T;
    cin>>T;
    while(T--) {       
        cin>>m;
        v.clear();
        for (int i =0; i<m; i++) {
            double y, x;
            cin>>y>>x;
            v.push_back(make_pair(y,x));
        }
        getDist();
        double lo = 0, hi = 1416.00;
        for (int  i =0; i<100; i++) {
            double mid = (lo+hi)/2.00;
            if (decision(mid)) {
                hi = mid;
            }
            else lo = mid;
        }
        printf("%.2f\n", hi);
    }
}