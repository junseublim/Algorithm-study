#include <bits/stdc++.h>

using namespace std;

int main() {
    int a,b,c;
    cin>>a>>b>>c;
    long long t = 1;
    for (int i =0; i<b; i++) {
        t *= a; 
        t %= c;
    }
    cout<<t<<endl;
}