#include<bits/stdc++.h>

using namespace std;
vector<int> c;
int s[501];
int n;

void solve(int k) {
    int s = 0;
    int e = c.size();
    int upper = c.size();
    while(s<=e) {
        int mid = (s+e)/2;
        if (c[mid] > k) {
            e = mid-1;
            upper = mid;
        }
        else {
            s = mid+1;
        }

    }
    if (upper == c.size())
    {
        c.push_back(k);
    }
    else{
        c[upper] = k;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    for (int t =0; t<T; t++) {
        cin>>n;
        c.assign(1, -1);
        for (int i =0; i<n; i++) {
            cin>>s[i];
            solve(s[i]);
        }
        cout<<c.size()-1<<"\n";
    }
}