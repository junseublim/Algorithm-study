#include <bits/stdc++.h>

using namespace std;

typedef struct Node {
    int y;
    int x;
    int val;
    Node (int yy,int xx, int vv) {
        y=yy;
        x=xx;
        val=vv;
    }
} Node;
 
struct cmp{
    bool operator()(Node a, Node b){
        return  a.val <  b.val;
    }
};
int n, m;
int maze[501][501];
int cnt[501][501];
int visited[501][501];
int minimum = 10001;
typedef pair<int,int> pii;
priority_queue<Node, vector<Node>, cmp> pq;
int mY[] = {0,0,-1,1};
int mX[] = {-1,1,0,0};
int main() {
    cin>>n>>m;
    for (int i =0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin>>maze[i][j];
        }
    }
    cnt[0][0] = 1;
    minimum = 100000;
    pq.push(Node(0,0,maze[0][0]));
    while(!pq.empty()) {
        Node next = pq.top();
        int y = next.y;
        int x = next.x;
        pq.pop();
        for (int i =0; i<4; i++) {
            int nY = y + mY[i];
            int nX = x + mX[i];
            if (nY >= 0 && nY <n && nX >=0 && nX <m) {
                if (maze[nY][nX] < maze[y][x]) {
                    cnt[nY][nX] += cnt[y][x];
                    if (!visited[nY][nX]) {
                        pq.push(Node(nY,nX, maze[nY][nX]));
                        visited[nY][nX] = 1;
                    }
                }
            }
        }
    }
    cout<<cnt[n-1][m-1]<<endl;
}