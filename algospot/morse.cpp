#include <bits/stdc++.h>

using namespace std;
int n,m,k;
int bino[201][201];

int M = 1000000000+10;
string answer;
void buildBino() {
    bino[0][0] = 1;
    for (int i =1; i<201; i++) {
        for (int j=0; j<=i; j++) {
            if (j ==0) bino[i][j] = 1;
            else {
                bino[i][j]= min(bino[i-1][j-1] + bino[i-1][j], M);
            }
        }
    }
}

void morse(int ls, int ss, int loc) {
    if (ls == 0) {
        while(ss--) {
            answer += 'o';
        }
        return;
    }
    if (ss == 0) {
        while(ls--) {
            answer += '-';
        }
        return;
    }
    int longSigns = bino[ls+ss-1][ls-1];
    if (loc <= longSigns) {
        answer += '-';
        morse(ls-1,ss, loc);
    }
    else {
        answer += 'o';
        loc -= longSigns;
        morse(ls, ss-1, loc);
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    buildBino();
    int C;
    cin>>C;
    while(C--) {
        answer = "";
        cin>>n>>m>>k;
        morse(n,m, k);
        cout<<answer<<"\n";
    }
}