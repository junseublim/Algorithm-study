#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a%b);
}

int main() {
    int n,m ;
    cin>>n>>m;
    if (n<m) {
        int temp = m;
        m=n;
        n=temp;
    }
    cout<<gcd(n,m)<<endl;
    int n2 = n;
    while(true) {
        if (n2%m == 0) {
            cout<<n2<<endl;
            break;
        }
        n2+= n;
    }
}