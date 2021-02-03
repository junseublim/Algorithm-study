#include <bits/stdc++.h>

using namespace std;
int primes[1000000];
int main() {
    primes[1] = 1;
    for (int i = 2; i<1000000; i++) {
        if (primes[i] == 0) {
            int j = 2;
            while(i*j <=1000000) {
                primes[i*j] = 1;
                j++;
            }
        }
    }
    int a,b;
    cin>>a>>b;
    for (int i=a; i<=b; i++) {
        if (primes[i] == 0) {
            cout<<i<<endl;
        }
    }
}