#include <bits/stdc++.h>
using namespace std;
int zero[41];
int one[41];
void fibonacci(int n) {
    if (one[n] != -1) {
        return;
    }
    if (n == 0) {
        zero[0] =1;
        one[0] = 0;
    } else if (n == 1) {
        one[1] = 1;
        zero[1] = 0;
    } else {
        fibonacci(n-1);
        fibonacci(n-2);
        one[n] = one[n-1] + one[n-2];
        zero[n] = zero[n-1] + zero[n-2];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    memset(one, -1, sizeof(one));
    memset(zero, -1, sizeof(zero));
    fibonacci(40);
    while(t--) {
        int n;
        cin>>n;
        cout<<zero[n]<<" "<<one[n]<<"\n";


    }
}