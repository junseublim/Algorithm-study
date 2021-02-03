#include <bits/stdc++.h>

using namespace std;
int primes[1000];
int main() {
    primes[1] = 1;
    for (int i =2; i<=1000;i++) {
        if (primes[i] == 0) {
            int j = 2;
            while(j*i <=1000) {
                primes[i*j] = 1;
                j++;
            }
        }
    }
    int n;
    cin>>n;
    int cnt = 0;
    for (int i =0; i<n; i++) {
        int temp;
        cin>>temp;
        if (primes[temp] == 0) cnt++;
    }
    cout<<cnt<<endl;
    
}