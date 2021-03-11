#include<bits/stdc++.h>

using namespace std;
long long cache[101][10];
long long ans = 0;
int n;
int main() {
    cin>>n;
    for (int i = 1; i<10;i++) {
        cache[1][i] = 1;
    }
    for (int i = 2; i<=100;i++) {
        for (int j=0; j<10; j++) {
            if (j == 0) {
                cache[i][j] = cache[i-1][1];    
            }
            else if (j ==9 ) {
                cache[i][j] = cache[i-1][8];
            }
            else {
                cache[i][j] += cache[i-1][j-1];
                cache[i][j] %= 1000000000;
                cache[i][j] += cache[i-1][j+1];
                cache[i][j] %= 1000000000;
            }
        }
    }
    for (int i = 0; i<10; i++) {
        ans += cache[n][i];
        ans %= 1000000000;
    }
    cout<<ans<<endl;
}