#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin>>n;
    vector<long long> fibo(91);
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i =2; i<=n; i++) {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    cout<<fibo[n]<<endl;
}