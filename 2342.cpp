#include <bits/stdc++.h>

using namespace std;
const int INF = 6000000;
const int MAX = 100001;
int inp[MAX];
int steps[MAX][5][5];
int sz;
//현재 왼쪽다리 l, 오른쪽 다리 r, 다음 차례 idx
//steps[idx][l][r] == 왼쪽다리 l, 오른쪽 다리 r, idx 차례 일때 최소힘
int ddr(int l, int r, int idx) {
    //cout<<"ddr "<<l<<" "<<r<<" idx: "<<idx<<endl;
    if (idx == sz) {
        //cout<<"final:"<<prev<<endl;
        return 0;
    }
    int nxt = inp[idx];
    int left = INF, right = INF;
    if (idx == 0) {
        ///처음 처리
        //cout<<"first "<<nxt<<endl;
        steps[idx][l][r] = min(ddr(nxt, r, idx+1)+2, ddr(l, nxt, idx+1)+2);
        //cout<<"오른발 움직임"<<steps[idx][l][nxt]<<endl;
        
        //cout<<"왼발 움직임"<<steps[idx][nxt][r]<<endl;
        return steps[idx][l][r];
    }
    if (l == nxt || r == nxt) {
        //cout<<"already leg on"<<endl;
        if (steps[idx][l][r] != INF) {
            return steps[idx][l][r];
        }
        steps[idx][l][r] = ddr(l,r, idx+1)+1;
        return steps[idx][l][r];
    }
    if (steps[idx][nxt][r] != INF) 
    {
        return steps[idx][l][r];
    }
    else {
        if (l == 0 ){
            left = min(left, ddr(nxt,r, idx+1)+2);
        }
        else if (abs(l-nxt) == 2){
            left = min(left, ddr(nxt,r, idx+1)+4);
        }
        else {
            left = min(left, ddr(nxt,r, idx+1)+3);
        }
        if (r == 0) {
            right = min(right, ddr(l,nxt, idx+1)+2);
        }
        else if (abs(r-nxt) == 2){
            right = min(right, ddr(l,nxt, idx+1)+4);
        }
        else {
            right = min(right, ddr(l,nxt, idx+1)+3);
        }
    }
    // steps[idx][nxt][r] = left;
    // steps[idx][l][nxt] = right;
    // return min(left, right);
    steps[idx][l][r] = min(left,right);
    return steps[idx][l][r];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tmp;
    int idx = 0;
    for (int i =0; i<MAX; i++) {
        for (int j = 0; j<5; j++) {
            for (int k= 0; k<5; k++) {
                steps[i][j][k] = INF;
            }
        }
    }
    while (true) {
        cin>>tmp;
        if (tmp == 0) break;
        inp[idx++] = tmp;
    }
    sz = idx;
    int minimum = ddr(0,0,0);
    // for (int i =0; i<5; i++) {
    //     for (int j = 0; j<5; j++) {
    //         for (int k= 0; k<5; k++) {
    //             cout<<steps[i][j][k]<<" "; 
    //         }
    //         cout<<endl;
    //     }
    //     cout<<endl;
    // }
    cout<<minimum;

}