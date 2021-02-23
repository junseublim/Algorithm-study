#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> D;
int main() {
    int n, k;
    cin>>n>>k;
    D.assign(n+1, vector<int>(n+1,0));
    //D[n][k] = D[n-1][k-1] + D[n-1][k]
    for (int i =0; i<=n; i++) {
        for (int j =0; j<=i; j++) {
            if (j ==0 || j==i) {
                D[i][j] = 1;
            }
            else {
                D[i][j] = D[i-1][j] + D[i-1][j-1];
            }
        }
    }
    cout<<D[n][k]<<endl;
}