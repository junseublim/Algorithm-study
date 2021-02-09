#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m;
    cin>>m;
    int n = 0;
    for (int i=0; i<m; i++) {
        string cmd;
        int x;
        cin>>cmd;
        if (cmd == "add") {
            cin>>x;
            n|= 1<<x;
        }
        else if (cmd == "remove") {
            cin>>x;
            n &= ~(1<<x);
        }
        else if (cmd == "all") {
            n = (1 << 21) - 1;
        }
        else if (cmd == "check") {
            cin>>x;
            //cout<<n<<" "<<(1<<x)<<endl;
            if (n&(1<<x)) 
                cout<<1<<endl;
            else cout<<0<<endl;
        }
        else if (cmd == "toggle") {
            cin>>x;
            n ^= 1<<x;
        }
        else if (cmd == "empty") {
            n= 0;
        }
        //cout<<n<<endl;
    }
    
}