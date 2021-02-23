#include <bits/stdc++.h>

using namespace std;
int graph[100][100];
int main() {
    int n;
    cin>>n;
    for (int i=0; i<n;i++) {
        for (int j=0;j<n;j++) {
            cin>>graph[i][j];
        }
    }
    for (int i=0; i<n;i++) {
        for (int j=0;j<n;j++) {
            for (int k=0; k<n; k++) {
                if (graph[i][k] * graph[j][i])
                    graph[j][k] = 1;
            }
        }
    }
    for (int i=0; i<n;i++) {
        for (int j=0;j<n;j++) {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}