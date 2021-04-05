#include<bits/stdc++.h>

using namespace std;
map<string, int> msi;
vector<string> vs;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    vs.push_back("");
    for (int i=1; i<=n; i++) {
        string a;
        cin>>a;
        msi.insert(make_pair(a, i));
        vs.push_back(a);
    }
    for (int j =0; j<m; j++) {
        int idx;
        string name;
        cin>>name;
        if (name[0]-'0' < 10) {
            idx = stoi(name);
            cout<<vs[idx]<<"\n";
        }
        else {
            cout<<msi.find(name)->second<<"\n";
        }
    }

}