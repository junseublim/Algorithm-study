#include <bits/stdc++.h>

using namespace std;
int chus[1000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int num;
    for(int i =0; i<n; i++) {
        cin>>chus[i];
    }
    sort(chus, chus+n);
    int want = 1;
    for(int i =0; i<n; i++) {
        num = chus[i];
        int want2 = want;
        for (int i =0; i<want2; i++) {
            if (num+i > want) {
                cout<<want<<"\n";
                return 0;
            }
            else if (num+i == want) want++;
        }
    }
    cout<<want<<"\n";
}