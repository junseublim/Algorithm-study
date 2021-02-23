#include <bits/stdc++.h>

using namespace std;
#define INF 20000000

int n,m, dist[101][101];

void floyd() {
    for (int j = 1; j <=n; j++) {
        for (int i = 1; i <= n; i++) {
            for (int k=1; k <= n; k++) {
                dist[i][k] = min(dist[i][k], dist[i][j] + dist[j][k]);
            }   
        }
    }
}



int main() {
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i == j) dist[i][j] = 0;
            else {dist[i][j] = INF;}
        }
    }
    
    for (int i =0; i<m;i++) {
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        if (c<dist[a][b]) {
            dist[a][b] =c;
        }
    }
    floyd();
    for (int i = 1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (dist[i][j] == INF) cout<<0<<" ";
            else cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }

}