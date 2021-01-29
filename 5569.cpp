#include<bits/stdc++.h>

using namespace std;
int fromLeftOneMore[101][101];
int fromLeftDone[101][101];
int fromUpOneMore[101][101];
int fromUpDone[101][101];
int dist[101][101];

int w,h;
int main() {
    for (int i =0; i<101; i++) {
        for (int j = 0; j<101; j++) {
            if (j == 1 && i != 0) {
                fromLeftOneMore[i][j] = 1;
                dist[i][j] +=1;
            }
            if (i == 0 && j!= 0) {
                fromLeftDone[i][j] = 1;
                dist[i][j] +=1;
            }
            if (i == 1 && j>1) {
                fromLeftDone[i][j] = 1;
                dist[i][j] +=1;
            }
            if (i == 1 && j != 0) {
                fromUpOneMore[i][j] = 1;
                dist[i][j] +=1;
            }
            if (i != 0 && j == 0) {
                fromUpDone[i][j] = 1;
                dist[i][j] +=1;
            }
            if (i >1 && j == 1) {
                fromUpDone[i][j] = 1;
                dist[i][j] +=1;
            }
        }
    }
    cin>>w>>h;
    w -= 1;
    h -= 1;
    for (int i = 2; i<=h; i++) {
        for (int j = 2; j<=w; j++) {
            fromLeftDone[i][j] += fromLeftOneMore[i][j-1];
            fromLeftDone[i][j]%= 100000;
            fromLeftOneMore[i][j] += fromUpDone[i][j-1];
            fromLeftOneMore[i][j]%= 100000;
            fromLeftDone[i][j] += fromLeftDone[i][j-1];
            fromLeftDone[i][j]%= 100000;
            fromUpDone[i][j] += fromUpOneMore[i-1][j];
            fromUpDone[i][j]%= 100000;
            fromUpOneMore[i][j] += fromLeftDone[i-1][j];
            fromUpOneMore[i][j]%= 100000;
            fromUpDone[i][j] += fromUpDone[i-1][j];
            fromUpDone[i][j]%= 100000;
            dist[i][j] = fromLeftDone[i][j] + fromLeftOneMore[i][j] + fromUpOneMore[i][j] + fromUpDone[i][j];
            dist[i][j] %= 100000;
        }
    }
    // for (int i =0; i<30; i++) {
    //     for (int j = 0; j < 30; j++) {
    //         cout<<dist[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dist[h][w]<<endl;

}