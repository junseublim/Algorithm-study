#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--) {
        deque<int> dq;
        string func;
        cin>>func;
        int n;
        cin>>n;
        string k;
        cin>>k;
        int num = -1;
        bool error = 0;
        for (int i =0; i< k.size(); i++) {
            if (k[i] >= '0' && k[i]<='9') {
                if (num == -1) num = 0;
                num *=10;
                num += k[i]-'0';
            }
            else if (k[i] == ',' || k[i] == ']') {
                if (num == -1) continue;
                dq.push_back(num);
                num = -1;
            }
        }
        bool reverse = false;
        for (int i=0; i<func.size(); i++) {
            if (func[i] == 'R') {
                reverse = !reverse;
            }
            else {
                if (dq.size() == 0) {
                    error = true;
                    break;
                }
                if (reverse) {
                    dq.pop_back();
                }
                else dq.pop_front();
            }
        }
        if (error) {
            cout<<"error\n";
            continue;
        }
        cout<<"[";
        if (reverse) {
            for (int i = dq.size()-1; i>=0; i--) {
                cout<<dq[i];
                if (i != 0) cout<<",";
            }
        }
        else {
            for (int i = 0; i<dq.size(); i++) {
                cout<<dq[i];
                if (i != dq.size()-1) cout<<",";
            }
        }
        cout<<"]\n";
    }
}