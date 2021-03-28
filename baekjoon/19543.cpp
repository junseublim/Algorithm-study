#include <bits/stdc++.h>

using namespace std;
int n,m,k;
string rows[26];
string mapper;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    for (int i =0; i<k;i++) {
        cin>>rows[i];
    }
    cin>>mapper;
    int cnt = 0;
    int s =0,e= m-1;
    for (int i =0; i<n; i++) {
        string curr = rows[k-1-(mapper[i]-'A')];
        if (i == 0) {
            for (int j =m-2; j >=0; j--) {
                if (curr[j] != 'R') {
                    s = j+1;
                    break;
                }
            }
            cnt += (e-s+1);
            cout<<e<<" "<<s<<endl;
            continue;
        }
        int ee = e;
        while (ee>0 && curr[ee] == 'R') {
            ee--;
        }
        int ss = ee;
        while (ss > 0 && (curr[ss] == 'R' || (curr[ss] == 'U'  &&  s <= ss))) {
            ss--;
        }
        cnt += (ee-ss+1);
        e= ee;
        s= ss;

        cout<<e<<" "<<s<<endl;
    }
    cout<<cnt<<"\n";
    return 0;
}