#include <bits/stdc++.h>

using namespace std;
int n;
int steps[301];
int sum1[301];
int sum2[301];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1; i<=n; i++) {
        cin>>steps[i];
    }
    for (int i = 1; i<=n; i++) {
        if (i >2){
            sum1[i] = max(sum1[i], sum1[i-2] + steps[i]);
            sum1[i] = max(sum1[i], sum2[i-2] + steps[i]);
        }
        else {
            sum1[i] = steps[i];
        }
        sum2[i] = max(sum2[i], sum1[i-1] + steps[i]);
        //sum2[i] = max(sum2[i], sum2[i-1] + steps[i]);
    }
    // for (auto x: sum1){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    // for (auto x: sum2){
    //     cout<<x<<" ";
    // }
    cout<<max(sum2[n], sum1[n])<<"\n";
}