#include<bits/stdc++.h>

using namespace std;
int numbers[10000001];
int cache[10000001];
int minFactor[10000001];
int minFactorCnt[10000001];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int C;
    cin>>C; 
    cache[1] = 1;
    for (int i =2; i<10000001; i++) {
        if (numbers[i] == 1) {
            continue;
        }
        cache[i] = 2;
        int cnt = 1;
        minFactorCnt[i] = 1;
        numbers[i] = 1;
        minFactor[i] = i;
        for (int j = i+i; j<10000001; j+=i) {
            numbers[j] = 1;
            minFactor[j] = i;
        }
    }
    for (int i=4; i<10000001; i++) {
        if (cache[i] != 0) continue;
        int m = i/minFactor[i];
        if (minFactor[i] == minFactor[m]) {
            minFactorCnt[i] = minFactorCnt[m]+1;
        }
        else{
            minFactorCnt[i] = 1;
        }
        cache[i] = cache[m]/ (minFactorCnt[i]) * (minFactorCnt[i]+1);
        
    }
    while(C--) {
        int n, lo, hi;
        cin>>n>>lo>>hi;
        int cnt = 0;
        for (int i =lo; i<=hi; i++) {
            if (cache[i]==n) {
                cnt++;
            }
        }
        cout<<cnt<<"\n";
    }
}
