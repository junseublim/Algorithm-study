#include <bits/stdc++.h>

using namespace std;
int n,m;
int a[1000000];
int b[1000000];
int c[1000000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for (int i =0; i<n; i++) {
        cin>>a[i];
    }
    for (int i =0; i<m; i++) {
        cin>>b[i];
    }
    int i =0, j= 0;
    int k = 0;
    while(i<n && j<m) {
        if (a[i] < b[j]) c[k++] = a[i++];
        else c[k++] = b[j++];
    }
    while (i<n) c[k++] = a[i++];
    
    while (j<m) c[k++] = b[j++];
    for (int i =0; i<n+m; i++) {
        cout<<c[i]<<" ";
    }

}