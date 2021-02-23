#include<bits/stdc++.h>

using namespace std;
int n;
int card[1010];
int total = 0;
typedef pair<int,int> pii;
pii k_turn[1001][1001];
pii m_turn[1001][1001];
pii m_play(int s,int e);
pii k_play(int s, int e) {
    if (s== e) {
        k_turn[s][e] = {card[s], 0};
        return {card[s], 0};
    }
    if (k_turn[s][e].first != -1) {
        return k_turn[s][e];
    } 
    pii temp1 = m_play(s+1,e);
    pii temp2 = m_play(s,e-1);
    if (temp1.first < temp2.first) {
        k_turn[s][e] = {temp1.second + card[s], temp1.first};
        return {temp1.second + card[s], temp1.first};
    }
    else {
        k_turn[s][e] = {temp2.second + card[e], temp2.first};
        return {temp2.second + card[e], temp2.first};
    }
}

pii m_play(int s, int e) {
    if (s== e) {
        m_turn[s][e] = {card[s], 0};
        return {card[s], 0};
    }
    if (m_turn[s][e].first != -1) {
        return m_turn[s][e];
    } 
    pii temp1 = k_play(s+1,e);
    pii temp2 = k_play(s,e-1);
    if (temp1.first < temp2.first) {
        m_turn[s][e] = {temp1.second + card[s], temp1.first};
        return {temp1.second + card[s], temp1.first};
    }
    else {
        m_turn[s][e] = {temp2.second + card[e], temp2.first};
        return {temp2.second + card[e], temp2.first};
    }
}
int main() {
    int T;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    for (int t= 0; t<T; t++) {
        cin>>n;
        total = 0;
        for (int i =0; i<1000; i++) {
            for (int j =0; j<1000; j++) {
                k_turn[i][j] = {-1,-1};
                m_turn[i][j] = {-1,-1};
            }
        }
        for (int i=0; i<n; i++) {
            cin>>card[i];
            total += card[i];
        }
        pii keun = k_play(0, n-1);
        cout<<keun.first<<"\n";
    }
    

}