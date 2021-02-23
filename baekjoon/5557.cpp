#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> board;
vector<int> nums;
queue<pair<int,int>> q;

int main() {
    int n;
    cin>>n;
    nums.assign(n, 0);
    board.assign(n, vector<long long>(21, 0));
    for (int i=0; i<n; i++) {
        cin>>nums[i];
    }
    board[0][nums[0]] = 1;
    for (int i =0; i<n-2; i++) {
        for (int j =0; j<=20; j++) {
            if (board[i][j] != 0) {
                if (j + nums[i+1] <= 20) {
                    board[i+1][j + nums[i+1]] += board[i][j];
                }
                if (j - nums[i+1] >= 0) {
                    board[i+1][j - nums[i+1]] += board[i][j];
                }
            }
        }
    }
    cout<<board[n-2][nums[n-1]]<<endl;
}