#include <bits/stdc++.h>

using namespace std;
int n,m, ans;
int mem[110], cost[110];
int dp[101][10001]; //[j][i] j까지 app 대상으로 살펴봤을때 cost i로 얻을 수 있는 최대 메모리 크기

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i =1; i<=n; i++) {
        cin>>mem[i];
    }
    for (int i =1; i<=n; i++) {
        cin>>cost[i];
    }
    for (int j =1; j<=n; j++) {
        for (int i =0; i<=10000; i++) {
            //[j][i] j앱까지 고려했을 때(대상으로 했을 떄) cost i로 확보할 수 있는 최대 메모리
            //j번째앱을 사용하거나/ 사용하지 않거나    
            //둘중 큰값
            //dp[j-i][i]
            //dp[j-1][i-cost[j]] + mem[j];
            dp[j][i] = dp[j-1][i];
            if (i-cost[j] >= 0) {
                dp[j][i] = max(dp[j][i], dp[j-1][i-cost[j]]+mem[j]);
            }
        }   
        for (int i =0; i< 100; i++) {
            cout<<dp[j][i]<<" ";
        }
        cout<<endl;
        
    }
    for (int i=0; i<=10000; i++) {
        //비용 찾아보면서, m이상의 메모리를 확보했는지 확인 해봄.
        if (dp[n][i] >= m) {
            ans = i;
            break;
        }
    }

    printf("%d", ans);


}