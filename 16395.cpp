#include <bits/stdc++.h>

using namespace std;

int triangle[31][31];

int main() {
    triangle[1][1] = 1;
    for (int i =2; i<=30; i++) {
        for (int j=1; j<=i; j++) {
            triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
        } 
    }
    int n,k; 
    cin>>n>>k;
    cout<<triangle[n][k]<<endl;
}