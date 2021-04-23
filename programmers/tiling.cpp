#include <string>
#include <vector>
#include <iostream>
#include <string.h>

using namespace std;
int cache[60001];

int dfs(int n, int i) {
    if (i == n) return 1;
    if (i > n) return 0;
    if (cache[i] != -1) return cache[i];
    long long v = 0;
    v += dfs(n, i+1);
    v %= 1000000007;
    v += dfs(n, i+2);
    v %= 1000000007;
    cache[i] = v;
    return cache[i];
    
}

int solution(int n) {
    memset(cache, -1, sizeof(cache));
    int answer = 0;
    answer = dfs(n, 0);
    return answer;
}