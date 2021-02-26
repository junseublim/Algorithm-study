#include<bits/stdc++.h>
using namespace std;

string s;
int main() {
    cin>>s;
    int temp = 1;
    char before = 'a';
    for (int i=0; i<s.size(); i++) {
        if (s[i]=='c') {
            int btemp = temp;
            temp *=26;
            if (before == s[i]) {
                temp -= btemp;
            }
        }
        else{
            int btemp = temp;
            temp *=10;
            if (before == s[i]) {
                temp -= btemp;
            }
        }
        before = s[i];
    }
    cout<<temp<<endl;

}