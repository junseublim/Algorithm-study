#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
int visited[1000][1000];
string vs[1000];
int my[] = {0,0,-1,1};
int mx[] = {-1,1,0,0};

typedef struct Node {
     int y;
     int x;
     int t;
     int broke;
    Node( int yy,  int xx,  int tt,  int b) {
        y=yy;x=xx;t=tt;
        broke = b;
    }
} Node;
int n,m;

int bfs(int y, int x) {
    queue<Node> q;
    q.push(Node(y,x,1,0));
    while(!q.empty()) {
        Node nxt = q.front();
        q.pop();
        if (visited[nxt.y][nxt.x] == 1) continue;
        else if (visited[nxt.y][nxt.x] == 2 && nxt.broke == 1) {
            continue;
        } 

        visited[nxt.y][nxt.x] = nxt.broke+1;

        if (vs[nxt.y][nxt.x] == '1')
        {
            if (nxt.broke == 0) {
                nxt.broke = 1;
            }
            else continue;
        }
        
        if (nxt.y == n-1 && nxt.x == m-1) {
            return nxt.t;
        }
        for (int i =0; i<4; i++) {
            if (nxt.y+my[i] >= 0 && nxt.y+my[i] < n && nxt.x+mx[i] >= 0 && nxt.x+mx[i] < m) {
                q.push(Node(nxt.y+my[i], nxt.x+mx[i], nxt.t+1, nxt.broke));
            }
        }
    }
    return -1;
}


int main() {
    
    cin>>n>>m;
    
    for (int i = 0; i<n; i++) {
        string s = "";
        cin>>s;
        vs[i] = s;
    }
    memset(visited,0, sizeof(visited));
    cout<<bfs(0,0);
}