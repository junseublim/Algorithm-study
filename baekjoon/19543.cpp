#include <bits/stdc++.h>

using namespace std;
int n,m,k;
string rows[26];
vector<int> v[26];
string mapper;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m>>k;
    for (int i =0; i<k;i++) {
        cin>>rows[i];
        for (int j = 0; j<m; j++) {
            if (rows[i][j] == 'U') {
                v[i].push_back(j);
            }
        }
    }
    cin>>mapper;
    long long cnt = 0;
    int s= 0, e= m-1;
    for (int i = m-2; i>=0; i--) {
        if (rows[mapper[n-1]-'A'][i] == 'U') {
            s = i+1;
            break;
        }
    }
    cnt += (long long)e-(long long)s+1;
    for (int i =1; i<n; i++) {
        int idx = mapper[n-1-i]-'A';
        if (v[idx].empty()) {
            break;
        }
        int start = 0, end = v[idx].size()-1;
        int temp = -1;
        int mid;
        while (start <= end) {
            mid = (start+end)/2;
            if (v[idx][mid] < s) {
                start = mid+1;
            }
            else {
                temp = mid;
                end = mid-1;
            }
        }
        if (temp == -1) break;
        s = temp;
        if (s != 0) {
            s = v[idx][s-1]+1;
        }
        start = 0, end = v[idx].size()-1;
        temp = -1;
        while (start <= end) {
            mid = (start+end)/2;
            if (v[idx][mid] > e) {
                end = mid-1;
            }
            else {
                temp = mid;
                start = mid+1;
            }
        }
        if (temp == -1) break;
        e = v[idx][temp];
        cnt += (long long)e-(long long)s+1;
    }
    cout<<cnt<<"\n";
    return 0;
}