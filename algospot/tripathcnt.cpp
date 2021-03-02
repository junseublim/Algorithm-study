#include <bits/stdc++.h>
using namespace std;
int n;
int tri[101][101];
int cache[101][101];
int pathCnt[101][101];
int main() {
    int C;
    cin>>C;
    while(C--) {
        cin>>n;
        for (int i =0; i<101; i++){
            memset(cache, -1, sizeof(cache));
            memset(pathCnt, 0, sizeof(pathCnt));
        }
        for (int i =0; i<n; i++) {
            for (int j =0; j<=i; j++) {
                cin>>tri[i][j];
            }
        }
        pathCnt[0][0] = 1;
        int maxV = 0;
        int cnt = 0;
        for (int i =0; i<n; i++) {
            if (i == n-1) {
                for (int j = 0; j<=i; j++) {
                    if (cache[i][j] > maxV) {
                        maxV = cache[i][j];
                        cnt = pathCnt[i][j];
                    }
                    else if (cache[i][j] == maxV) {
                        cnt += pathCnt[i][j];
                    }
                }
                continue;
            }
            for (int j = 0; j<=i; j++) {
                if (cache[i+1][j] < cache[i][j] + tri[i+1][j]){
                    cache[i+1][j] = cache[i][j] + tri[i+1][j];
                    pathCnt[i+1][j] = pathCnt[i][j];
                }
                else if (cache[i+1][j] == cache[i][j] + tri[i+1][j]) {
                    pathCnt[i+1][j] += pathCnt[i][j];
                }
                if (cache[i+1][j+1] < cache[i][j] + tri[i+1][j+1]){
                    cache[i+1][j+1] = cache[i][j] + tri[i+1][j+1];
                    pathCnt[i+1][j+1] = pathCnt[i][j];
                }
                else if (cache[i+1][j+1] == cache[i][j] + tri[i+1][j+1]) {
                    pathCnt[i+1][j+1] += pathCnt[i][j];
                }
            }
        }
        cout<<cnt<<"\n";

    }
}