#include<bits/stdc++.h>

using namespace std;
int n;
int cache[101][101][101];
const int MOD = 10000000;

int poly(int level, int blocks, int left) {
    if (level == 0) {
        if (blocks != 0) {
            return 0;
        }
        return 1;
    }
    if (left == 0) {
        return 1;
    }
    int& ret = cache[level][blocks][left];
    if(ret != -1) return ret;
    ret = 0;
    for (int i = 1; i<=left; i++) {
        ret +=(blocks+i-1)* poly(level-1, i, left-i);
        ret %= MOD;
    }
    return ret;
}


int main(){
    int C;
    cin>>C;
    while(C--) {
        cin>>n;
        for (int i =0; i<101; i++) {
            for (int j =0; j<101; j++) {
                memset(cache[i][j], -1, sizeof(cache[i][j]));
            }
        }
        int total = 0;
        for (int i =1; i<= n; i++) {
            total += poly(n,i, n-i);
            total %= MOD;
        }
        cout<<total<<"\n";
    }
}