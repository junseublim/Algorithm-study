#include <bits/stdc++.h>
#include <string.h>

using namespace std;
string str;        
int dp[200][200];

bool match(int s, int l) {
    //cout<<"s : "<<s<<" l : "<<l<<endl;
    if (l == 0) return 1;
    if (dp[s][l] != -1) return dp[s][l];
    dp[s][l] = 0;
    if (str.substr(s,2) == "01" ) {
        dp[s][l] |= match(s+2, l-2);
    }
    if (l >= 4 && str.substr(s,3) == "100") {
        int k = 3;
        int able = 1;
        dp[s][l] = 1;
        while(k < l && str[s+k] == '0') k++;
        if (k >= l) dp[s][l] = 0;
        else {
            while (k < l) {
                if (str[s+k] != '1') dp[s][l] = 0;
                k++;
            }
        }
    }
    //cout<<"s : "<<s<<" l : "<<l<<" "<<dp[s][l]<<endl;
    return dp[s][l];
}


int main() {

    int n;
    cin>>n;
    while(n--) {        
        cin>>str;
        memset(dp, -1, sizeof(dp));
        int able = 0;
        queue<pair < int, int > > q;
        for (int i = 2; i<=str.size(); i++) {
            q.push(make_pair(0,i));
        }
        while(!q.empty()) {
            pair<int, int> pii = q.front();
            q.pop();
            //cout<<"pii : "<<pii.first<<" "<<pii.second<<endl;
            if (match(pii.first, pii.second)) {
                int start = pii.first + pii.second;
                if (start  == str.size()) {
                    able = 1;
                    break;
                }
                for (int i = 2; start+i <= str.size(); i++) {
                    q.push(make_pair(start, i));
                }
            }
        }
        
        if (able) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}