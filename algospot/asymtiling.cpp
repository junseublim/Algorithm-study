#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,C;
ll cache[101];
const int MOD = 1000000007;

ll tiling(int index) {
    if (index == n) {
        return 1;
    }
    else if (index > n) return 0;
    ll &ret = cache[index];
    if (ret != -1) return ret;
    ret = 0;
    ret += tiling(index+2);
    ret %= MOD;
    ret += tiling(index+1);
    ret %= MOD;
    return ret;
}
ll asym() {
    ll total = tiling(0);
    ll asymTile;
    if (n%2 == 0) {
        total  = (total - tiling(n/2) + MOD) % MOD;
        total  = (total - tiling(n/2+1) + MOD) % MOD;
    }
    else {
        total = (total-tiling(n/2+1)+MOD) % MOD;
    }
    
    return total;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>C;
    while (C--)
    {
        memset(cache, -1, sizeof(cache));
        cin>>n;
        cout<<asym()<<"\n";
    }
    

}