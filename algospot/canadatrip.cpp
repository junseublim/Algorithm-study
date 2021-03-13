#include <bits/stdc++.h>

using namespace std;
int n,k;
// 도시까지의 거리
int L[5000];
// 간격
int G[5000];
// 도착하기 전
int M[5000];
const int MAX = 8030000;

int go(int dist) {
    int cnt = 0;
    for (int i =0; i<n; i++) {
        if (dist >= L[i]) {
            cnt += M[i]/G[i] + 1;
        }
        else if (L[i] - M[i] > dist) continue;
        else {
            cnt += (dist-(L[i]-M[i]))/G[i] + 1;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>k;
        for (int i=0; i<n; i++) {
            cin>>L[i]>>M[i]>>G[i];
        }
        int s = 0, e = MAX;
        while(s<=e) {
            int mid = (s+e)/2;
            if (go(mid) >= k) {
                e = mid-1;
            }
            else s = mid+1;
        }
        cout<<s<<"\n";
    }
}