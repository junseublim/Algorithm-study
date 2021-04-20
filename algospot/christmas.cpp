#include <bits/stdc++.h>
using namespace std;
int n,k;
int psum[100001];
const int MOD = 20091101;

long long wayToBuy () {
    vector<long long> cnt(k,0);
    long long ret = 0;
    for (int i=0; i<=n; i++) {
        cnt[psum[i]]++;
    }
    for (int i=0; i<k; i++) {
        if (cnt[i]>= 2) {
            ret += (cnt[i] * cnt[i]-1)/2 % MOD;
        }
    }
    return ret;
}

int maxBuys() {
    vector<int> ret (n+1, 0);

    //prev[s] = psum[] 이 s였던 마지막 위치
    vector<int> prev(k,-1);
    for (int i =0; i<=n; i++) {
        if (i >0)
            ret[i] = ret[i-1];
        else
            ret[i] = 0;
        int loc = prev[psum[i]];
        if (loc != -1) ret[i] = max(ret[i], ret[loc]+1);
        prev[psum[i]] = i;
    }
    return ret.back();

}

int main() {
    int T;
    cin>>T;
    while(T--) {
        cin>>n>>k;
        psum[0] = 0;
        for (int i =1; i<=n; i++) {
            cin>>psum[i];
            psum[i] += psum[i-1];
            psum[i] %= k;
        }
        cout<<wayToBuy()<<maxBuys()<<endl;

    }
}