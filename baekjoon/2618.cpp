#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
int N;
int W;
int dp[1001][1001];
vector<int> police1[1001];
vector<int> police2[1001];
vector<pii> crimes;
int main() {
    cin>>N>>W;
    for (int i = 0; i<=1000; i++){
        memset(dp[i], -1, sizeof(dp[i]));
    }
    police1[0].push_back(0);
    police2[0].push_back(0);
    dp[0][0] = 0;
    crimes.push_back(make_pair(-1,-1));
    for (int i=1; i<=W; i++) {
        int a,b;
        cin>>a>>b;
        crimes.push_back(make_pair(a,b));
    }
    
    for (int i = 1; i<crimes.size(); i++) {
        //cout<<i<<endl;
        int sz = police1[i-1].size();
        //경찰차 1번이 이전사건 처리함
        for (int j = 0; j<sz; j++) {
            //police2 == 경찰차 1번이 이전꺼 처리할때 경찰차 2번의 위치
            int police2Last = police1[i-1][j];
            if (j == i) continue;
            int police2Y, police2X;
            int police1Y, police1X;
            if (police2Last == 0) {
                police2Y = N;
                police2X = N;
            }
            else {
                police2Y = crimes[police2Last].first;
                police2X = crimes[police2Last].second;
            }
            if (i == 1) {
                police1Y = 1;
                police1X = 1;
            }
            else {
                police1Y = crimes[i-1].first;
                police1X = crimes[i-1].second;
            }
            //처음으로 활성화
            //경찰차 2번이 움직인다.
            if (dp[i-1][i] == -1) {
                dp[i-1][i] = dp[i-1][police2Last] + abs(police2Y - crimes[i].first) + abs(police2X - crimes[i].second);
                police1[i-1].push_back(i);
                police2[i].push_back(i-1);
                //cout<<"dp["<<i-1<<"]["<<i<<"] = "<< dp[i-1][i]<<endl;
            }
            else {
                dp[i-1][i] = min(dp[i-1][i], dp[i-1][police2Last] + abs(police2Y - crimes[i].first) + abs(police2X - crimes[i].second));
                //cout<<"dp["<<i-1<<"]["<<i<<"] = "<< dp[i-1][i]<<endl;
            }
            //경찰차 1번이 움직인다.
            if (dp[i][police2Last] == -1) {
                dp[i][police2Last] = dp[i-1][police2Last] + abs(police1Y - crimes[i].first) + abs(police1X - crimes[i].second);
                police1[i].push_back(police2Last);
                police2[police2Last].push_back(i);
                //cout<<"dp["<<i<<"]["<<police2Last<<"] = "<< dp[i][police2Last]<<endl;
            }
            else {
                dp[i][police2Last] = min(dp[i][police2Last], dp[i-1][police2Last] + abs(police1Y - crimes[i].first) + abs(police1X - crimes[i].second));
                //cout<<"dp["<<i<<"]["<<police2Last<<"] = "<< dp[i][police2Last]<<endl;
            }
        }
        //cout<<"//////////"<<endl;
        sz = police2[i-1].size();
        for (int j = 0; j<sz; j++) {
            int police1Last = police2[i-1][j];
            if (j == i) continue;
            int police1Y, police1X;
            int police2Y, police2X;
            if (police1Last == 0) {
                police1Y = 1;
                police1X = 1;
            }
            else {
                police1Y = crimes[police1Last].first;
                police1X = crimes[police1Last].second;
            } 
            if (i == 1) {
                police2Y = N;
                police2X = N;
            }
            else {
                police2Y = crimes[i-1].first;
                police2X = crimes[i-1].second;
            }
            //처음으로 활성화
            if (dp[i][i-1] == -1) {
                dp[i][i-1] = dp[police1Last][i-1] + abs(police1Y - crimes[i].first) + abs(police1X - crimes[i].second);
                police2[i-1].push_back(i);
                police1[i].push_back(i-1);
                //cout<<"dp["<<i<<"]["<<i-1<<"] = "<< dp[i][i-1]<<endl;
            }
            else {
                dp[i][i-1] = min(dp[i][i-1], dp[police1Last][i-1] + abs(police1Y - crimes[i].first) + abs(police1X - crimes[i].second));
                //cout<<"dp["<<i<<"]["<<i-1<<"] = "<< dp[i][i-1]<<endl;
            }
            if (dp[police1Last][i] == -1) {
                dp[police1Last][i] = dp[police1Last][i-1] + abs(police2Y - crimes[i].first) + abs(police2X - crimes[i].second);
                police2[i].push_back(police1Last);
                police1[police1Last].push_back(i);
                //cout<<"dp["<<police1Last<<"]["<<i<<"] = "<< dp[police1Last][i]<<endl;
            }
            else {
                dp[police1Last][i] = min(dp[police1Last][i], dp[police1Last][i-1] + abs(police2Y - crimes[i].first) + abs(police2X - crimes[i].second));
                //cout<<"dp["<<police1Last<<"]["<<i<<"] = "<< dp[police1Last][i]<<endl;
            }
        }
    }
    int maximum = 987654321;
    pii car;
    for (int i =0; i<=W; i++) {
        if (dp[W][i] != -1){
            if (maximum > dp[W][i]){
                maximum = dp[W][i];
                car = make_pair(W,i);
            }            
        }
        if (dp[i][W] != -1){
            if (maximum > dp[i][W]){
                maximum = dp[i][W];
                car = make_pair(i,W);
            }         
        }
    }
    int k = W;
    stack<int> s;
    int currVal = maximum;
    
    // for (int i =0; i<=W; i++) {
    //     for (int j =0; j<=W; j++) {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    while(k) {
        int found = 0;
        //cout<<"car"<<car.first<<" "<<car.second<<endl;
        //cout<<"Curr val "<<currVal<<endl;
        for (int i=car.second; i>= 0; i--) {
            if (car.second == i) continue;
            if (dp[car.first][i] == -1) continue;
            int beforey = crimes[i].first;
            int beforex = crimes[i].second;
            if (beforey == -1) {
                beforey = N;
                beforex = N;
            }
            int dist =  abs(beforey - crimes[k].first) + abs(beforex - crimes[k].second);
            //cout<<"prev : " <<dp[car.first][i]<<" dist : "<<dist<<endl;
            if (currVal == dp[car.first][i] + dist) {
                currVal -= dist;
                s.push(2);
                car = make_pair(car.first, i);
                found = 1;
                break;
            }
        }
        if (found) {
            k--;
            continue;
        }
        for (int i=car.first; i>=0; i--) {
            if (car.first == i) continue;
            if (dp[i][car.second] == -1) continue;
            int beforey = crimes[i].first;
            int beforex = crimes[i].second;
            if (beforey == -1) {
                beforey = 1;
                beforex = 1;
            }
            int dist =  abs(beforey - crimes[k].first) + abs(beforex - crimes[k].second);
            //cout<<"prev location: "<<crimes[police2[car.second][i]].first <<" "<<crimes[police2[k][i]].second<<endl;

            //cout<<"prev : " <<dp[i][car.second]<<" dist : "<<dist<<endl;
            if (currVal == dp[i][car.second] + dist) {
                currVal -= dist;
                car = make_pair(i,car.second);
                s.push(1);
                break;
            }
        }
        k--;
    }
    cout<<maximum<<endl;
    while(s.size()) {
        cout<<s.top()<<endl;
        s.pop();
    }
}