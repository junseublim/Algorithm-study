#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(true) {
        long long n, k;
        cin>>n>>k;
        if (n == 0 && k ==0) break;
        if (n-k < k) k= n-k;
        long long result = 1;
        for (long long i =1; i<=k; i++) {
            result *= n;
            result /= i;
            n--;
        }
        cout<<result<<"\n";
    }
}