#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> trees;

ll getWoods(ll middle) {
    ll woods = 0;
    for (auto x: trees) {
        if (x-middle > 0) {
            woods += x-middle;
        }
    }
    return woods;
}

int main() {
    ll n,m;
    cin>>n>>m;
    trees.assign(n, 0);
    for (ll i =0; i<n; i++) {
        cin>>trees[i];
    }
    ll start = 0;
    ll end = *max_element(trees.begin(), trees.end());
    ll middle;
    ll woods;
    ll maxHeight = 0;
    while (start <= end) {
        middle = (start+end)/2;
        woods = getWoods(middle);
        if (woods >= m) { 
            maxHeight = max(middle, maxHeight);
            start = middle + 1;
        }
        else if (woods < m) {
            end = middle - 1;
        }
    }
    cout<<maxHeight<<endl;
}