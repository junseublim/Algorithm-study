#include <bits/stdc++.h>

using namespace std;
map<string, int> msi;
vector<string> vs;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i =0; i<n; i++) {
        string s;
        cin>>s;
        msi.insert(make_pair(s, i));
    }
    for(int i =0; i<m; i++) {
        string s;
        cin>>s;
        if (msi.count(s)) {
            vs.push_back(msi.find(s)->first);
        }
    }
    sort(vs.begin(), vs.end());
    cout<<vs.size()<<"\n";
    for(auto x: vs) {
        cout<<x<<"\n";
    }
}