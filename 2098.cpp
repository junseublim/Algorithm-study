#include <bits/stdc++.h>

using namespace std; 

const int MAX = 16;
const int INF = 987654321;
int N;
int W[MAX][MAX];
int cache[MAX][1 << MAX];

int dp(int here, int visited) {
    if(visited == (1<<N)-1) {
        //모두 방문함
        if (W[here][0] != 0) {
            return W[here][0];
        }
        return INF;
    }
    if (cache[here][visited] != -1) {
        return cache[here][visited];
    }
    int result = INF;
    for (int i =1; i< N; i++) {
        if (visited & (1<<i) || W[here][i] == 0) {
            continue;
        }
        int cand = dp(i, visited + (1<<i)) + W[here][i];
        if (cand < result) result = cand;
    }
    cache[here][visited] = result;
    return cache[here][visited];


}

int main() {
    cin>>N;
    for (int i =0; i<N; i++) {
        for (int j =0; j<N; j++) {
            cin>>W[i][j];
        }
    }
    memset(cache, -1, sizeof(cache));
    cout<<dp(0,1)<<endl;

}