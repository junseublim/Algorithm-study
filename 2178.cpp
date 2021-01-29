#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
int moveY[] = {-1,0,0,1};
int moveX[] = {0,-1,1,0};

typedef struct Node{
    int x,y, cnt;
    Node(int yy, int xx, int cntcnt) {
        x= xx; y= yy; cnt= cntcnt;
    }
} Node;


int main() {
    int n,m;
    string vs[100];
    vector<vector<int> > vvi;
    cin>>n>>m;
    vvi.assign(n, vector<int>(m,INF));
    for (int i =0; i<n; i++) {
        cin>>vs[i];
    }
    n--;m--;
    Node nd = Node(0,0,1);
    queue<Node> q;
    q.push(nd);
    int mini = INF;
    while(!q.empty()) {
        Node curr = q.front();
        q.pop();
        //cout<<"current : "<<curr.y<<" " <<curr.x<<" count: "<<curr.cnt<<endl;
        if (curr.y == n && curr.x == m) {
            mini = min(mini, curr.cnt);
        }
        if (vs[curr.y][curr.x] == '0')  {
            //cout<<"wall"<<endl;
            continue;
        }
        if (curr.cnt < vvi[curr.y][curr.x]) {
            vvi[curr.y][curr.x] = curr.cnt;
            for (int i =0; i<4;i++) {
                if (0<= curr.y + moveY[i] && curr.y + moveY[i] <= n
                    && 0<= curr.x + moveX[i] && curr.x + moveX[i] <=m) {
                        q.push(Node(curr.y+moveY[i],curr.x+moveX[i], curr.cnt+1));
                    }
            }
        }
        
    }
    cout<<mini<<endl;
}