#include <bits/stdc++.h>

using namespace std;
int n, d, p, t;
vector<int> adj[50];
double cache[101][51];

double numbers(int days, int city) {
    //cout<<"days : "<<days<<" city : "<<city<<endl;
    if (days == 0) {
        if (city == p)  {
            return 1;
        }
        return 0;
    }
    double &ret = cache[days][city];
    if (ret > -1) return ret;
    ret = 0;
    for (int i =0; i<adj[city].size(); i++) {
        ret += numbers(days-1, adj[city][i])/adj[adj[city][i]].size();
    }
    //cout<<"cache["<<days<<"]["<<city<<"] = "<<ret<<endl;
    return ret;
}

int main() {
    int C;
    cin>>C;
    while(C--) {
        for (int i =0; i<101; i++) {
            for (int j = 0; j<51; j++) {
                cache[i][j] = -1;
            }
        }
        for (int i =0; i<50; i++) {
            adj[i].clear();
        }
        cin>>n>>d>>p;
        for (int i =0; i<n; i++) {
            for (int j=0; j<n; j++) {
                int temp;
                cin>>temp;
                if (temp != 0) {
                    adj[i].push_back(j);
                }
            }
        }
        cin>>t;
        for (int i =0; i<t; i++) {
            int q;
            cin>>q;
            printf("%0.8f ", numbers(d,q));
            
        }
        printf("\n");
    }
}