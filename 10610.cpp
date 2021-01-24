#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    string nstr;
    cin>>nstr;
    bool hasZero = 0;
    ll total = 0;
    for (int i =0; i<nstr.size(); i++) {
        if (nstr[i] == '0') {
            hasZero = true;
        }
        total += (nstr[i]-'0');
    }
    
    if (total%3 != 0 || !hasZero) {
        cout<<-1<<endl;
        return 0;
    }
    sort(nstr.rbegin(), nstr.rend());
    cout<<nstr<<endl;

}