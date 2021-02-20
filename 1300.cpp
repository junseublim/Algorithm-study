#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n;
ll k;

ll getOrder(ll num) {
    ll cnt = 0;
    for (ll i = 1; i<=n; i++) {
        cnt += min(n, num/i);
    }
    return cnt;
}

int main() {
    cin>>n>>k;
    ll a = 1, b = n*n; 
    ll ans;
    while (a <= b) {
        ll mid = (a+b)/2;
        //cout<<"mid: "<<mid<<endl;
        ll order = getOrder(mid);
        //cout<<"order: "<<order<<endl;
        if (order >= k) {
            b = mid-1;
            ans = mid;
        }
        else {
            a = mid+ 1;
        }
    }
    cout<<ans<<endl;
}