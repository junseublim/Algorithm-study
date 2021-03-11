#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
int n;
vector<pii > v;
int dp[100];
int main() {
    cin>>n;
    for (int i =0; i<n; i++) {
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(), v.end());
    int maxLength = 0;
    for (int i =0; i<n; i++) {
        if (dp[maxLength] < v[i].second) {
            maxLength+=1;
            dp[maxLength] = v[i].second;
        }
        else {
            int l = maxLength-1;
            while(dp[l] > v[i].second){
                l--;
            }
            dp[l+1] = v[i].second;
        }   
    }
    for (int i =0; i<n; i++) {
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    cout<<n-maxLength<<endl;
}
