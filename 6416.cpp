#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
set<int> nodes;
int main() {
    ll u,v;
    ll k = 0;
    while (true) {
        k++;
        ll lineCount = 0;
        nodes.clear();
        cin>>u>>v;
        while(u > 0 && v >0) {
            nodes.insert(u);
            nodes.insert(v);
            lineCount++;
            cin>>u>>v;
        }
        if (u == -1) {
            break;
        }
        if (lineCount + 1 == nodes.size() || nodes.size() == 0) {
            cout<<"Case "<<k<<" is a tree.\n";
        }
        else {
            cout<<"Case "<<k<<" is not a tree.\n";
        }
    }
}