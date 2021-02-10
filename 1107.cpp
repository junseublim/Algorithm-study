#include <bits/stdc++.h>

using namespace std;
int n;
int visited[1000001];
set<int> broken;
queue<pair<int, int> > q;

int cnt = 987654321;

void go() {
    while(!q.empty()) {
        pair<int, int> pii = q.front();
        q.pop();
        cnt = min(cnt, pii.second+ abs(pii.first-n));
    }
}

void addToQueue(int num, int cnt) {
    if (num > 10000000) {
        return;
    }
    q.push(make_pair(num, cnt));
    for (int i=0; i<10; i++) {
        if (broken.count(i)) continue;
        addToQueue(num*10 + i, cnt+1); 
    }
}

int main() {
    int m;
    cin>>n;
    cin>>m;
    for (int i=0; i<m;i++) {
        int temp;
        cin>>temp;
        broken.insert(temp);
    }
    q.push(make_pair(100, 0));
    if (!broken.count(0)) q.push(make_pair(0,1));
    for (int i=1; i<10; i++) {
        if (broken.count(i)) continue;
        addToQueue(i, 1);
    }
    go();
    cout<<cnt<<endl;
}