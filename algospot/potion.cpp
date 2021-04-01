#include <bits/stdc++.h>

using namespace std;
int actual[200];
int putted[200];
int ans[200];
int gcds[1001][1001];
int getGcd(int a, int b ){
    if (gcds[a][b] != -1) return gcds[a][b]; 
    if (b == 0) return a;
    return getGcd(b, a%b);
}

int main() {
    int c;
    cin>>c;
    memset(gcds, -1, sizeof(gcds));
    while(c--) {
        int n;
        cin>>n;
        int gcd;
        for (int i =0; i<n; i++) {
            cin>>actual[i];
            if (i == 0) gcd = actual[i];
            else gcd = getGcd(gcd, actual[i]);
        }
        int a = gcd;
        for (int i =0; i<n; i++) {
            cin>>putted[i];
            a = max(a, int(ceil((double)putted[i]*gcd/(double)actual[i])));
        }  
        for (int i =0; i<n; i++) {
            ans[i] = a* (actual[i]/gcd) - putted[i]; 
        }
        for (int i =0; i<n; i++) {
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
}