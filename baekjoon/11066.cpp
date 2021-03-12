#include <bits/stdc++.h>
using namespace std;
int chapters[500];
int n;
int cache[500][500];
int getMin(int s, int e) {
    if (s==e) {
        return 0;
    }
    int& ret = cache[s][e];
    if (ret != -1) return ret;

    int sum = 0;
    for (int i =s; i<=e; i++) {
        sum += chapters[i];
    }
    ret = 98754321;
    int left =  0;
    int right = sum;
    for (int i = s; i<e; i++) {
        left += chapters[i];
        right -= chapters[i];
        ret = min(ret, getMin(s,i) + getMin(i+1,e) + left + right);
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--) {        
        memset(cache, -1, sizeof(cache));
        cin>>n;
        for (int i=0; i<n; i++) {
            cin>>chapters[i];
        }
        cout<<getMin(0,n-1)<<"\n";
    }
}