#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int y;
    int x;
    int minimum;
    int maximum;
    int house;
} Visit;

int k;
int n;
const int INF = 987654321;
vector<string> town;
vector<vector<int>> heights;
vector<vector<int>> MinDiffheights;
pair<int,int> post;
int minimumDiff = INF;
queue<Visit> q;

void bfs() {
    Visit v = {post.first, post.second, heights[post.first][post.second],town[post.first][post.second], 0};
    q.push(v);
    while(q.size()) {
        Visit next = q.front();
        int y = next.y;
        int x = next.x;
        q.pop();
        if (town[y][x]=='K') {
            k++;
        }
        if (next.house == k) {
            minimumDiff = min(minimumDiff, next.maximum-next.minimum);
            continue;
        }
        
        if ( y-1 >=0 ) {
            int height =  heights[y-1][x];
            Visit temp = {y-1,x, min(next.minimum, height), max(next.maximum, height),next.house };
        }
    }


    return;
}

int main() {
    cin>>n;
    k = 0;
    heights.assign(n, vector<int>(n));
    town.assign(n, "");
    for (int i=0; i<n; i++) {
            cin>>town[i];
            for (int j=0; j<n; j++) {
                if (town[i][j] == 'K') {
                    k++;
                }
                else if (town[i][j] == 'P') {
                    post = {i,j};
                }
            }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin>>heights[i][j];
        }
    }
    bfs();
}