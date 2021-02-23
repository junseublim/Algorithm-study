#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<int> a;
vector<int> b;
vector<ll> x;
vector<ll> y;

int main() {
    ll t;
    int n,m;
    cin>>t;
    cin>>n; 
    a.assign(n,0);
    for (int i =0;  i<n ;i++) {
        cin>>a[i];
    }
    cin>>m;
    b.assign(m,0);
    for (int i=0; i<m; i++) {
        cin>>b[i];
    }
    for (int i =0;  i<n ;i++) {
        ll sum = a[i];
        x.push_back(sum);
        for (int j= i+1; j<n; j++) {
            sum+= a[j];
            x.push_back(sum);
        }
    }
    for (int i =0;  i<m ;i++) {
        ll sum = b[i];
        y.push_back(sum);
        for (int j= i+1; j<m; j++) {
            sum+= b[j];
             y.push_back(sum);
        }
    }
    sort(y.begin(), y.end());
    ll ans = 0;
    for (auto sum: x) {
        ll diff = t- sum;
        auto ub = upper_bound(y.begin(), y.end(), diff);
        auto lb = lower_bound(y.begin(), y.end(), diff);
        ans += (ub-lb);
    }
    cout<<ans<<endl;
}