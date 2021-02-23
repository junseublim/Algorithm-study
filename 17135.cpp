#include <bits/stdc++.h>

using namespace std;

int n,m,d;
int tower[16][16];
int towerCopy[16][16];
int visited[16][16];
int maximum;

typedef struct Node {
    int y;
    int x;
    int dist;
    Node (int yy, int xx, int dd){
        y =yy; x= xx; dist = dd;
    }
} Node;

int my[] = {0,-1,0};
int mx[] = {-1,0,1};
typedef pair<int,int> pii;
pii shoot(int shooter) {
    for (int i =0; i<16;i++) {
        memset(visited[i], 0, sizeof(visited[i]));
    }
    queue<Node> q;
    q.push(Node(n-1, shooter, 1));
    while (q.size()) {
        Node nxt = q.front();
        q.pop();
        if (visited[nxt.y][nxt.x]) continue;
        visited[nxt.y][nxt.x] = 1;
        if (nxt.dist > d) break;
        if (tower[nxt.y][nxt.x]) {
            return make_pair(nxt.y, nxt.x);
        }
        for (int i =0; i<3; i++ ){
            if (nxt.y+ my[i] >= 0 && nxt.y+my[i]<n && nxt.x+ mx[i] >= 0 && nxt.x+mx[i]<m) {
                q.push(Node(nxt.y+my[i], nxt.x+mx[i], nxt.dist+1));
            }
        }

    }
    return make_pair(-1,-1);
}
void moveDown() {
    for (int i=n-1; i>=0; i--) {
        if (i == 0) {
            for (int j=0; j<m; j++) {
                tower[i][j] = 0;
            } 
            continue;
        }
        for (int j=0; j<m; j++) {
            tower[i][j] = tower[i-1][j];
        }
    }
}
void defense(int one,int two, int three) {
    int total = 0;
    for (int i =0; i<n; i++) {
        pii temp1 = shoot(one);
        pii temp2 = shoot(two);
        pii temp3 = shoot(three);
        if (temp1.first != -1 && tower[temp1.first][temp1.second] == 1) {
            tower[temp1.first][temp1.second] = 0;
            total++;
        }
        if (temp2.first != -1 && tower[temp2.first][temp2.second] == 1) {
            tower[temp2.first][temp2.second] = 0;
            total++;
        }
        if (temp3.first != -1 && tower[temp3.first][temp3.second] == 1) {
            tower[temp3.first][temp3.second] = 0;
            total++;
        }
        moveDown();
    }
    maximum = max(maximum, total);
}

void setTower() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m;j++) {
            tower[i][j] = towerCopy[i][j];
        }
    }
}


int main() {
    cin>>n>>m>>d;
    for (int i =0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin>>tower[i][j];
            towerCopy[i][j] = tower[i][j];
        }
    }
    for (int i =0; i<m-2; i++) {
        for (int j=i+1; j<m-1; j++) {
            for (int k=j+1; k<m; k++) {
                setTower();
                defense(i,j,k);
            }
        }
    }
    cout<<maximum<<endl;

}