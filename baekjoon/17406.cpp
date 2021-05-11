#include <bits/stdc++.h>

using namespace std;
int n,m,k;
int arr[51][51];
int turns[6][3];
int used[6];
int minV = 987654321;
int dy[2][4] = {{0,1,0,-1},{1,0,-1,0}};
int dx[2][4] = {{1,0,-1,0}, {0,1,0,-1}};

void rotate(int sy, int sx, int ey, int ex, int dir) {
    //if (dir == 0)cout<<"rotate"<<sy<<" "<<sx<<" "<<ey<<" "<<ex<<endl;
    int length = ey-sy;
    int idx = 0;
    int move = 1;
    int temp = arr[sy][sx];
    sy+=dy[dir][0];
    sx+=dx[dir][0];
    while(idx< 4) {
        //if (dir ==0) cout<<sy<<" "<<sx<<endl;
        if (move == length) {
            move = 0;
            idx++;
        }
        int temp2 = arr[sy][sx];
        arr[sy][sx] = temp;
        temp = temp2;
        sy+=dy[dir][idx];
        sx+=dx[dir][idx];
        move++;
    }
}

void turn(int idx, int dir) {
    // if (dir == 0){
    //     cout<<"before turn"<<turns[idx][0]<<turns[idx][1]<<turns[idx][2]<<endl;
    //     for(int i=1; i<=n;i++) {
    //         for (int j=1; j<=m; j++) {
    //             cout<<arr[i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }
    //     cout<<endl;
    // }

    int mid = (2*turns[idx][2]+1)/2;
    for (int i =0; i<mid; i++) {
        rotate(turns[idx][0]-turns[idx][2]+i, turns[idx][1]-turns[idx][2]+i, 
        turns[idx][0]+turns[idx][2]-i, turns[idx][1]+turns[idx][2]-i, dir);
    }
    // if (dir == 0){
    // cout<<"after turn"<<turns[idx][0]<<turns[idx][1]<<turns[idx][2]<<endl;
    // for(int i=1; i<=n;i++) {
    //     for (int j=1; j<=m; j++) {
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    // }
}

void calc() {
    for (int i = 1; i<=n; i++) {
        int v = 0;
        for (int j =1; j<=m; j++) {
            v += arr[i][j];
        }
        minV = min(minV, v);
    }
}
void go(int cnt) {
    if (cnt == k) {
        //계산
        calc();
        return;
    }
    for (int i=0; i<k;i++) {
        if (!used[i]) {
            used[i] = 1;
            turn(i, 0);
            go(cnt+1);
            used[i] = 0;
            turn(i, 1);
        }
    }
}
int main() {
    cin>>n>>m>>k;
    memset(used, 0, sizeof(used));
    for(int i=1; i<=n;i++) {
        for (int j=1; j<=m; j++) {
            cin>>arr[i][j];
        }
    }
    for (int i=0; i<k; i++) {
        cin>>turns[i][0]>>turns[i][1]>>turns[i][2];
    }
    go(0);
    cout<<minV<<endl;



}