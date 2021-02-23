#include <bits/stdc++.h>

using namespace std;
int houses[15][15];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i =1; i<15; i++) {
        houses[0][i] = i;
    }
    for (int i = 1; i<15; i++) {
        for (int j= 1; j<15; j++) {
            houses[i][j] += houses[i][j-1] + houses[i-1][j];
        }
    }


    int T;
    cin>>T;
    for (int t =0; t< T; t++) {
        int k,n;
        cin>>k>>n;
        cout<<houses[k][n]<<"\n";
    }
    
}