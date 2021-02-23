#include <bits/stdc++.h>

using namespace std;
int T,N,M;
vector<vector<int>> D;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    D.assign(31, vector<int>(31, 0));
    for (int i =0; i<=30; i++) {
        for (int j =0; j<=i; j++) {
            if (j ==0 || j==i) {
                D[i][j] = 1;
            }
            else {
                D[i][j] = D[i-1][j] + D[i-1][j-1];
            }
        }
    }
    cin>>T;
    for (int t= 0; t<T; t++) {
        cin>>N>>M;
        cout<<D[M][N]<<"\n";

    }
}