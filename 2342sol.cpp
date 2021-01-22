#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
 
int step[100001];
int dp[5][5][100001];
int len;
 
int func(int l, int r, int i) {
    if (i == len)
        return 0;
 
    int& ref = dp[l][r][i];
    if (ref != -1)
        return ref;
 
    if (l == 0 && r == 0)
        return ref = func(step[i], r, i + 1) + 2;
 
    if (l == step[i])
        return ref = func(l, r, i + 1) + 1;
    else if (r == step[i])
        return ref = func(l, r, i + 1) + 1;
 
    int left = 0;
    if (l == 0)
        left = func(step[i], r, i + 1) + 2;
    else if (abs(l - step[i]) == 2)
        left = func(step[i], r, i + 1) + 4;
    else
        left = func(step[i], r, i + 1) + 3;
 
    int right = 0;
    if (r == 0)
        right = func(l, step[i], i + 1) + 2;
    else if (abs(r - step[i]) == 2)
        right = func(l, step[i], i + 1) + 4;
    else
        right = func(l, step[i], i + 1) + 3;
 
    return ref = min(left, right);
}
 
int main() {
    int tmp;
    while (1) {
        scanf("%d", &tmp);
        if (tmp == 0)
            break;
        else
            step[len++] = tmp;
    }
    memset(dp, -1, sizeof(dp));
 
    printf("%d", func(0, 0, 0));
 
    return 0;
}