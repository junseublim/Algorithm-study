#include <bits/stdc++.h>

using namespace std;

int forest[500][500];
int dp[500][500];
int n;

int my[] = {-1, 0, 0, 1};
int mx[] = {0, 1, -1, 0};
int maxV = 0;
int go(int y, int x)
{
    int &ret = dp[y][x];
    if (ret != -1)
        return ret;
    ret = 1;
    int child = 0;
    for (int i = 0; i < 4; i++)
    {
        if (y + my[i] >= 0 && y + my[i] < n && x + mx[i] >= 0 && x + mx[i] < n)
        {
            if (forest[y + my[i]][x + mx[i]] < forest[y][x])
                child = max(child, go(y + my[i], x + mx[i]));
        }
    }
    ret += child;
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> forest[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            maxV = max(maxV, go(i, j));
        }
    }
    cout << maxV << "\n";
}