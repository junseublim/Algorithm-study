#include <bits/stdc++.h>

using namespace std;

int T,people,candies;
typedef long long ll;
int gcd(int a,int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

tuple<ll, ll, ll> egcd(int a, int b) {
    ll s0 =1, t0 =0, r0 =a;
    ll s1 = 0, t1 =1, r1 =b;

    ll temp;
    while (r1 != 0) {
        int q = r0/r1;
        temp = r0 -q*r1;
        r0 = r1;
        r1 = temp;

        temp = s0-q*s1;
        s0 = s1;
        s1 = temp;

        temp = t0-q*t1;
        t0 = t1;
        t1 = temp;
    }
    tuple<ll, ll, ll> ret = {s0,t0,r0};
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    for (int t=0; t< T; t++) {
        cin>>people>>candies;
        if  (gcd(people,candies) != 1) {
            cout<<"IMPOSSIBLE"<<"\n";
            continue;
        }
        if (candies == 1) {
            ll ans = people + 1;
            if (ans > 1e9) {
                cout<<"IMPOSSIBLE"<<"\n";
            }
            else cout<<ans<<"\n";
            continue;
        }
        tuple<ll, ll, ll> ret = egcd(people,candies);
        ll x0 = get<0>(ret);
        ll y0 = get<1>(ret);
        ll C = get<2>(ret);
        ll k = floor(float(y0*C)/float(people));
        k = min(k, ll(floor(float(-1*x0*C)/float(candies))));
        ll ans = y0 - (people/C)*k;
        if (ans > 1e9) {
            cout<<"IMPOSSIBLE"<<"\n";
            continue;
        }
        cout<<ans<<"\n";

    }
}