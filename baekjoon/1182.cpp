#include <bits/stdc++.h>

using namespace std;

int num[20];
int n, s;
int ans = 0;
void go (int total, int idx, int cnt) {
    if (idx == n) {
        if (total == s && cnt != 0) {
            ans++;
            
        }
        return;
    }
    go(total + num[idx], idx+1, cnt+1);
    go(total, idx+1, cnt);
}


int main() {
    cin>>n>>s;
    for (int i=0; i<n;i++) {
        cin>>num[i];
    }
    go(0,0,0);
    cout<<ans<<endl;

}