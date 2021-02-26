#include<bits/stdc++.h>

using namespace std;
int n;
int roman[] = {1,5,10,50};
int cnt = 0;
int nums[1001];

void dfs(int alpha, int used, int sum) {
    if (used == n) {
        if (nums[sum]) return;
        nums[sum] = 1;
        cnt++;
        return;
    }
    for (int i =alpha; i<4; i++) {
        dfs(i, used+1, sum+roman[i]);
    }
}

int main() {
    
    cin>>n;
    dfs(0,0,0);    
    cout<<cnt<<endl;
}