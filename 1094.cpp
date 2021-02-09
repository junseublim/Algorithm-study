#include <bits/stdc++.h>

using namespace std;

int main () {
    int n; cin>>n;
    int cnt = 0;
    for (int i=1; i<=64; i*=2) {
        if (i&n) cnt++;
    }
    cout<<cnt<<endl;
}