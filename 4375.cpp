#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n;
ll target = 1;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin>>n) {
        int k = 1;
        target = 1;
        while(target%n != 0) {
            target= (target*10)%n +1;
            k++;
        }
        cout<<k<<"\n";
    }
}