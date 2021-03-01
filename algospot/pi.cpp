#include <bits/stdc++.h>

using namespace std;
string s;
int sz;
int cache[10001];
const int INF = 987654321;
int classify(int a, int b) {
    string M = s.substr(a, b);
    if (M == string(M.size(), M[0])) return 1;
    bool progressive = true;
    for (int i =0; i< M.size()-1; i++) {
        if (M[i+1] - M[i] != M[1]-M[0]) {
            progressive = false;
        }
    }
    if (progressive && abs(M[1]-M[0]) == 1) return 2;
    bool alternating = true;
    for (int i=0; i<M.size() ; i++) {
        if (M[i] != M[i%2]) alternating = false;
    }
    if (alternating) return 4;
    if (progressive) return 5;
    return 10;
}

int memorize(int begin) {
    if (begin == sz) return 0;
    int& ret = cache[begin];
    if (ret != -1) return ret;
    ret = INF;
    for (int L = 3; L<=5; L++) {
        if (begin + L <=sz) {
            ret = min(ret, classify(begin,L) + memorize(begin+L));
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int C;
    cin>>C;
    while(C--){
        memset(cache, -1, sizeof(cache));
        cin>>s;
        sz = s.size();
        for (int i =s.size()-3; i>=0; i--) {
            memorize(i);
        }
        cout<<memorize(0)<<"\n";
    }
}