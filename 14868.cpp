#include <bits/stdc++.h>

using namespace std;

set<int> s;

typedef struct Node {
    int num;
    Node* parent;
    Node() {
        num = 0;
    }
    Node(int nn) {
        num = nn;
    }
    Node(int nn, Node* p) {
        parent = p;
        num = nn;
    }
} Node;
Node cultures[100001];
int world[2001][2001];
int n,k;
int my[] = {0,0,-1,1};
int mx[] = {-1,1,0,0};

typedef struct QueueItem {
    int y;
    int x;
    int year;
    QueueItem(int yy, int xx, int yearyear) {
        y=yy;
        x=xx;
        year = yearyear;
    }
} QueueItem;
queue<QueueItem> q;

Node* find (int c) {
    if (cultures[c].num != cultures[c].parent->num) {
        return cultures[c].parent = find(cultures[c].parent->num);
    }
    else return &cultures[c];
}
void unionIt(int a, int b) {
    Node* tempa = find(a);
    Node* tempb = find(b); 
    if (tempa->num < tempb->num) {
        tempb->parent = tempa;
        s.erase(tempb->num);
    }
    else {
        tempa->parent = tempb;
        s.erase(tempa->num);
    }
}
bool checkIntegrated() {
    if (s.size() == 1) return true;
    return false;
}

int bfs() {
    int year = -1;
    while(!q.empty()) {
        QueueItem nxt = q.front();
        q.pop();
        for (int i =0; i<4;i++) {
            if (nxt.y+my[i] >0 && nxt.y+my[i] <= n && nxt.x+mx[i] > 0 && nxt.x+mx[i] <= n) {
                if (world[nxt.y+my[i]][nxt.x+mx[i]] == 0) {
                    world[nxt.y+my[i]][nxt.x+mx[i]] = world[nxt.y][nxt.x];
                    q.push(QueueItem(nxt.y+my[i],nxt.x+mx[i],nxt.year+1));
                    int sY = nxt.y+my[i];
                    int sX = nxt.x+mx[i];
                    for (int j =0; j<4; j++) {
                        if (sY+my[j] >0 && sY+my[j] <= n && sX+mx[j] > 0 && sX+mx[j] <= n) {
                            if (world[sY+my[j]][sX+mx[j]] == 0) continue;
                            if (find(world[sY][sX]) != find(world[sY+my[j]][sX+mx[j]])) {
                                unionIt(world[sY][sX], world[sY+my[j]][sX+mx[j]]);
                            }
                        }
                    }
                }
                else {
                    if (find(world[nxt.y][nxt.x]) != find(world[nxt.y+my[i]][nxt.x+mx[i]])) {
                        unionIt(world[nxt.y][nxt.x], world[nxt.y+my[i]][nxt.x+mx[i]]);
                    }
                }
            }
        }
        cout<<"year: "<<nxt.year<<endl;
        for (int i =1; i<=n; i++) {
            for (int j =1; j<=n; j++) {
                if (world[i][j] == 0) cout<<0<<" "; 
                else cout<<find(world[i][j])->parent->num<<" ";
            }
            cout<<endl;
        }
        if (checkIntegrated()) return nxt.year;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    int culture = 1;
    for (int i =0; i<k;i++) {
        int a,b;
        cin>>a>>b;
        world[a][b] = culture;
        cultures[culture] = Node(culture);
        cultures[culture].parent = &cultures[culture];
        s.insert(culture);
        q.push(QueueItem(a,b,1));
        for (int j =0; j<4; j++) {
            if (a+my[j] >0 && a+my[j] <= n && b+mx[j] > 0 && b+mx[j] <= n) {
                if (world[a+my[j]][b+mx[j]] == 0) continue;
                if (find(world[a][b]) != find(world[a+my[j]][b+mx[j]])) {
                    unionIt(world[a][b], world[a+my[j]][b+mx[j]]);
                }
            }
        }
        culture++;
    }
    if (checkIntegrated()) {
        cout<<0<<"\n";
        return 0;
    }
    cout<<bfs()<<"\n";
}