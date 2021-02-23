#include <bits/stdc++.h>

using namespace std;
int n,m;
int p[1000001];


int findf(int a) {
    if (a == p[a]) return a;
    p[a] = findf(p[a]);
    return p[a];
}

void unionf(int a, int b) {
    a = findf(a);
    b = findf(b);
    p[a] = b; 
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    while (n >=0) {
        p[n] = n;
        n--;
    }
    while(m-- > 0) {
        int cmd, a,b;
        cin>>cmd>>a>>b;
        if (cmd == 0) {
            unionf(a,b);
        }
        else {
            int ap = findf(a);
            int bp = findf(b);
            if (ap == bp) {
                cout<<"YES\n";
            }
            else {
                cout<<"NO\n";
            }
        }
    }


}