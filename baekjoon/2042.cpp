#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,M,K;
vector<ll> arr;
vector<ll> tree;


ll sum(int a, int k) {
    if (a != 1) {
        return sum(1,k) - sum(1,a-1);
    }
    ll s =0;
    while (k>=1) {
        s += tree[k];
        k-= k&-k;
    }
    return s;
}
void replace (int k, ll x, ll original) {
    while (k <= n) {
        tree[k] += x-original;
        k+= k&-k;
    }
}
void add (ll k, ll x) {
    while (k <= n) {
        tree[k] +=x;
        k+= k&-k;
    }
}


int main() {
    cin>>n>>M>>K;
    arr.assign(n+1, 0LL);
    tree.assign(n+1, 0LL);
    for (int i=1; i<=n; i++) {
        scanf("%lld", &arr[i]);
    }
    for (int i=1; i<=n; i++) {
        add(i, arr[i]);
    }
    ll a;
    ll b;
    ll c;
    for (int i = 0; i<M+K; i++) {
        cin>>a>>b>>c;
        if (a == 1) {
            replace(b,c, arr[b]);
            arr[b] = c;
        }
        else {
            printf("%lld\n", sum(b,c));
        }
    }

}