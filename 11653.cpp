#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    if (n==1) return 0;
    vector<bool> numbers(n+1, false);
    vector<int> primes;
    for (int i =2; i<=n; i++) {
        if (numbers[i] == false) {
            primes.push_back(i);
            for (int j= i*2; j<=n; j+=i) {
                numbers[j] = true;
            }
        }
    }
    int p =0;
    while(true) {
        while(n%primes[p] == 0) {
            cout<<primes[p]<<"\n";
            n/=primes[p];
        }
        p++;
        if (n == 1) break;
    }
}