#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX = 4000;
ll arr[4][4000];
vector<ll> first, second;
int n;

int main() {
    cin>>n;
    for (int i =0; i<n; i++) {
        cin>>arr[0][i];
        cin>>arr[1][i];
        cin>>arr[2][i];
        cin>>arr[3][i];
    }
    for (int i =0; i<n; i++) {
        for (int j =0; j<n; j++) {
            second.push_back(arr[2][i] + arr[3][j]);
        }
    }
    sort(second.begin(), second.end());
    ll count = 0;
    for (int i =0; i<n; i++) {
        for (int j=0; j<n; j++) {
            ll half = arr[0][i] + arr[1][j];
            auto ub = upper_bound(second.begin(), second.end(), -half) - second.begin();
            auto lb = lower_bound(second.begin(), second.end(), -half)- second.begin();
            if (second[lb] == -half) {
                count += ub-lb;
            }
        }
    }
    cout<<count<<endl;
}