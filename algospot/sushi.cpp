#include <bits/stdc++.h>

using namespace std;

int n,m;
int price[20];
int prefer[20];
int maxPrefer[201];
int main() {
    int C;
    cin>>C;
    while(C--) {
        cin>>n>>m;
        m /= 100;
        memset(maxPrefer, 0, sizeof(maxPrefer));
        for (int i=0; i<n; i++) {
            cin>>price[i]>>prefer[i];
            price[i] /= 100;
        }

        for (int i=0; i<=m; i++) {
            int index = i %(201);
            for (int j =0; j<n; j++) {
                //cout<<"m : "<<m<<" price[j] : "<<price[j]<<endl;
                if (i - price[j] >= 0) {
                    maxPrefer[index] = max(maxPrefer[index], maxPrefer[(i-price[j])%201] + prefer[j]);
                }
            }
        }
        // for (int i =0; i<201; i++) {
        //     cout<<maxPrefer[i]<<" ";
        //     if (i != 0 && i % 10 == 0) cout<<endl;
        // }

        cout<<endl<<maxPrefer[m%201]<<endl;

    }
}