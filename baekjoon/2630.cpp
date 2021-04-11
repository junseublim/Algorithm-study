#include <bits/stdc++.h>

using namespace std;
int paper[128][128];
int white = 0;
int blue = 0;

void divide(int ys, int ye, int xs, int xe) {
    int num = paper[ys][xs];
    int able = 1;
    for (int i = ys; i<ye; i++) {
        for (int j = xs; j<xe; j++) {
            if (paper[i][j] != num) {
                able = 0;
            }
        }
    }
    if (able) {
        if (num == 0) {
            white += 1;
        }
        else {
            blue += 1;
        }
    }
    else {
        int ym = (ys+ye)/2;
        int xm = (xs+xe)/2;
        divide(ys,ym,xs,xm);
        divide(ym,ye,xs,xm);
        divide(ys,ym, xm,xe);
        divide(ym,ye, xm,xe);
    }
}


int main() {
    int n;
    cin>>n;
    for (int i =0; i<n; i++) {
        for (int j =0; j<n; j++) {
            cin>>paper[i][j];
        }
    }
    divide(0,n,0,n);
    cout<<white<<endl;
    cout<<blue<<endl;
}