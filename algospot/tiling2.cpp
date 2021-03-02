#include <bits/stdc++.h>
using namespace std;
int n;
int cache[101];
int tiling(int index) {
    if (index == n) return 1;
    else if (index > n) return 0;
    int &ret = cache[index];
    if (ret != -1) return ret;
    ret = 0;
    ret = tiling(index+2) + tiling(index+1);
    ret = ret % 1000000007;
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int C;
    cin>>C;
    while(C--) {
        memset(cache, -1, sizeof(cache));
        cin>>n;
        cout<<tiling(0)<<"\n";
    }
}