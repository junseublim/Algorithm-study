#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
vector<pii> vp;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        int a,b;
        cin>>a>>b;
        vp.push_back(make_pair(b,a));
    }
    sort(vp.begin(), vp.end());
    int end = -1;
    int cnt = 0;
    for (int i=0; i<n; i++) {
        if (vp[i].second < end) continue;
        end = vp[i].first;
        cnt++;
    }
    cout<<cnt<<"\n";
}
