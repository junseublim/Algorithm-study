#include <bits/stdc++.h>

using namespace std;
int n;
typedef pair<int,int> pii;
vector<pii> v;
const int INF = 987654321; 
int m[500][500];
int main() {
    cin>>n;
    for ( int i=0; i<n; i++) {
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    for (int i = 0; i<n; i++) {
        for (int j= 0; j<n; j ++) {
            m[i][j] = INF;
        }
    }
    for (int i =0; i<n; i++) m[i][i] = 0;
    for (int j =0; j<n; j++) {
        for (int i = 0; i+j<n; i++) {
            for (int k = i; k <i+j; k++) {
                // if (i==0 && j == 2){
                //     cout<<"k : "<<k<<endl;
                //     cout<<"m[i][k] : "<<m[i][k]<<endl;
                //     cout<<"m[k+1][j] : "<<m[k+1][j]<<endl;
                //     cout<<"test "<<m[i][k] + m[k+1][j] + v[i].first* v[k].second * v[j].second<<endl;
                // }
                m[i][j+i] = min(m[i][j+i],m[i][k] + m[k+1][j+i] + v[i].first* v[k].second * v[j+i].second);
            }
        }
    }
    // for (int i = 0; i<n; i++) {
    //     for (int j= 0; j<n; j ++) {
    //         cout<<m[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<m[0][n-1]<<"\n";
}