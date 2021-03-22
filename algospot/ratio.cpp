#include <bits/stdc++.h>

using namespace std;


int n, m;
long long L = 2000000000;
int win(long long b, long long a) {
    return (a*100)/b;
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        cin>>n>>m;
        if (win(n, m) == win(n+L, m +L)) {
            cout<<-1<<endl;
            continue;
        }
        long long s = 0, e = L;
        while (s + 1 <e) {
            long long mid = (s+e)/2;
            if (win(n, m) == win(n+mid, m+mid)) {
                s = mid;
            }
            else {
                e = mid;
            }
        }

        cout<<e<<endl;
    }
}