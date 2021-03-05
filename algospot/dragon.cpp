#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000000001;
int n,p,l;
int length[51];

const string EXPAND_X = "X+YF";
const string EXPAND_Y = "FX-Y";

char dragon(const string& s, int gen, int skip) {
    cout<<s<<" "<<gen<<" "<<skip<<endl;
    if (gen == 0) {
        return s[skip];
    }
    for (int i = 0; i<s.size(); i++) {
        if (s[i] == 'X' || s[i] == 'Y') {
            if (skip >= length[gen]+1) {
                skip -= length[gen]+1;
            }
            else if (s[i] == 'X')
                return dragon(EXPAND_X, gen-1, skip);
            else
            {
                return dragon(EXPAND_Y, gen-1, skip);
            }
            
        }
        else if (skip > 0)
            --skip;
        else return s[i];
    }
    return '#';
    
}
void preCalc() {
    length[0] = 1;
    for (int i =1; i<51; i++) {
        length[i] = max(length[i-1] * 2 +2, MAX);
    }
}

int main() {
    preCalc();
    int C;
    cin>>C;
    while(C--) {
        cin>>n>>p>>l;
        string temp = "";
        for (int i =0; i<l; i++) {
            temp+=dragon("FX", n, p+i);
        }
        cout<<temp<<"\n";
    }
}