#include <bits/stdc++.h>

using namespace std;
int n;
int house[16][16];
int fromUp[16][16];
int fromLeft[16][16];
int fromDiag[16][16];
int main() {
    cin>>n;
    for (int i =0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin>>house[i][j];
        }
    }
    fromLeft[0][1] = 1;
    for (int i =0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if(fromLeft[i][j]) {
                if (j+1 <n && house[i][j+1] != 1) fromLeft[i][j+1] += fromLeft[i][j];
                if (i+1 <n && j+1< n && !house[i][j+1] && !house[i+1][j] && !house[i+1][j+1]) fromDiag[i+1][j+1] += fromLeft[i][j];
            }
            if (fromUp[i][j]) {
                if (i+1<n && !house[i+1][j]) fromUp[i+1][j] += fromUp[i][j];
                if (i+1 <n && j+1< n && !house[i][j+1] && !house[i+1][j] && !house[i+1][j+1]) fromDiag[i+1][j+1] += fromUp[i][j];
            }
            if (fromDiag[i][j]) {
                if (i+1<n && !house[i+1][j]) fromUp[i+1][j] += fromDiag[i][j];
                if (j+1<n && !house[i][j+1]) fromLeft[i][j+1] += fromDiag[i][j];
                if (i+1 <n && j+1< n && !house[i][j+1] && !house[i+1][j] && !house[i+1][j+1]) fromDiag[i+1][j+1] += fromDiag[i][j];
            }
        }
    }
    cout<<fromUp[n-1][n-1] + fromLeft[n-1][n-1] + fromDiag[n-1][n-1]<<endl;

}