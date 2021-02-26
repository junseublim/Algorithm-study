#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
ll n;
ll cache[1000001];

ll go(ll num) {
    if (cache[num] != -1) {return cache[num];}
    ll temp = go(num-1) + go(num-2);
    temp %= 1000000000;
    temp *= (num-1);
    temp %= 1000000000;
    cache[num] = temp;
    return cache[num];
}

int main() {
    cin>>n;
    memset(cache, -1ll, sizeof(cache));
    cache[0] = 1;
    cache[1] = 0;
    for (int i =2; i<n; i++) {
        go(i);
    }
    
    cout<<go(n)<<endl;
}