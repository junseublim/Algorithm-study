#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> D;

const int MAX = 1000000000;
int main() {
    int N,M,K;
    cin>>N>>M>>K;
    D.assign(N+M+1, vector<int>(N+M+1, 0));
    for (int i =0; i<=N+M; i++) {
        for (int j =0; j<=i; j++) {
            if (j ==0 || j==i) {
                D[i][j] = 1;
            }
            else {
                D[i][j] = D[i-1][j] + D[i-1][j-1];
                if (D[i][j] > MAX) {
                    D[i][j] = MAX;
                }
            }
        }
    }
    string s = "";
    int n = N+M;
    int k = M;
    if (D[n][k] < K) {
        cout<<-1<<endl;
        return 0;
    }
    for (; n>0; n--) {
        if (D[n-1][k] >=  K) {
            s.push_back('a');
        }
        else {
            
            s.push_back('z');
            K -= D[n-1][k];
            k--;
        }

    }
    cout<<s<<endl;

}