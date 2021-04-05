#include<bits/stdc++.h>

using namespace std;

int recur (int n, int r, int c){
    if(r ==0 && c== 0) return 0;
    if (r < n/2 && c < n/2) return recur(n/2,r,c);
    if (r < n/2 && c < n) return recur(n/2,r,c-n/2) + (n/2)*(n/2);
    if (r < n && c < n/2) return recur(n/2,r-n/2,c) + (n/2)*(n/2)*2;
    return recur(n/2,r-n/2,c-n/2) + (n/2)*(n/2)*3;
}


int main() {
    int N,r,c;
    cin>>N>>r>>c;
    int n = pow(2,N);
    cout<<recur(n,r,c)<<endl;

}