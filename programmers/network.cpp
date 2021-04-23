#include <string>
#include <vector>
#include <string.h>

using namespace std;

int visited[200];

void dfs(int x, vector<vector<int>> computers, int n) {
    if(visited[x]) return;
    visited[x] = 1;
    for (int i =0; i< n; i++) {
        if (computers[x][i]) dfs(i, computers, n);
    }
    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    memset(visited, 0, sizeof(visited));
    for (int i =0; i<n; i++) {
        if (visited[i] == 0) {
            answer++;
            dfs(i, computers, n);
        }
        
    }
    return answer;
}