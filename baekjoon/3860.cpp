#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
const int INF = 987654321;
int w,h;
int e, g;
typedef struct Hole {
    int x2,y2,w;
    Hole() {
        x2=0;y2=0;w=0;
    }
    Hole(int x22,int y22, int ww) {
        x2=x22; y2=y22; w= ww;
    }
} Hole;

int dist[30][30];
int gy[30][30];
Hole holes[30][30];
int yMove[4] = {-1,0,0,1};
int xMove[4] = {0,-1,1,0};

void bellman() {
    int n = w *h;
    for (int i=0; i<n-1; i++) {
        for (int y =0; y<h; y++) {
            for (int x = 0; x<w; x++) {
                if (dist[y][x] == INF) continue;
                //귀신 구멍
                if (gy[y][x] == 2) {
                    Hole hole = holes[y][x];
                    dist[hole.y2][hole.x2]  = min(dist[hole.y2][hole.x2], dist[y][x] + hole.w); 
                }
                // 묘지
                else if (y==h-1 && x == w-1) continue;
                // 일반
                else{
                    for (int j = 0; j<4; j++) {
                        if (y+yMove[j] <h && y+yMove[j] >= 0 && x+xMove[j] < w && x+xMove[j] >=0) {
                            if(gy[y+yMove[j]][x+xMove[j]] == 1) continue;
                            dist[y+yMove[j]][x+xMove[j]] = min(dist[y][x] +1, dist[y+yMove[j]][x+xMove[j]]);
                        }
                    }
                }
                
            }
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (true) {
        cin>>w>>h;
        if (w == 0 ) break;
        for (int i =0; i<30; i++) {
            for (int j=0; j<30; j++) {
                dist[i][j] = INF;
                gy[i][j] = 0;
                Hole h = Hole(0,0,0);
                holes[i][j] = h;
            }
        }
        dist[0][0] = 0;
        cin>>g;
        for (int i = 0; i<g; i++) {
            int x0,y0;
            cin>>x0>>y0;
            gy[y0][x0] = 1;
        }
        cin>>e;
        for (int i =0; i<e; i++) {
            int x1,y1,x2,y2;
            int weight;
            cin>>x1>>y1;
            cin>>x2>>y2;
            cin>>weight;
            Hole hole = Hole(x2,y2,weight);
            gy[y1][x1] = 2;
            holes[y1][x1] = hole;
        }
        bellman();
        int isLoop= false;
        for (int y =0; y<h; y++) {
            for (int x = 0; x<w; x++) {
                if (dist[y][x] == INF) continue;
                if (gy[y][x] == 2) {
                    Hole hole = holes[y][x];
                    if (dist[hole.y2][hole.x2] > dist[y][x] + hole.w) {
                        isLoop = true;
                    }
                }
                else if (y==h-1 && x == w-1) continue;
                else{
                    for (int j= 0; j<4; j++) {
                        if (y+yMove[j] < h && y+yMove[j] >= 0 && x+xMove[j] < w && x+xMove[j] >=0) {
                            if (dist[y][x] +1 < dist[y+yMove[j]][x+xMove[j]]) {
                                if(gy[y+yMove[j]][x+xMove[j]] == 1) continue;
                                isLoop = true;
                            }
                        }
                    }
                }
            }
        }
        // for (int i = 0;i<h; i++) {
        //     for (int j =0; j<w; j++) {
        //         cout<<gy[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // for (int i = 0;i<h; i++) {
        //     for (int j =0; j<w; j++) {
        //         cout<<dist[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
       
        if (isLoop) {
            cout<<"Never"<<"\n";
        }
        else {
            if (dist[h-1][w-1] != INF) {
                cout<<dist[h-1][w-1]<<"\n";
            }
            else cout<<"Impossible"<<"\n";
        }
    }
}