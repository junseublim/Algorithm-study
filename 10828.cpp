#include<bits/stdc++.h>

using namespace std;
stack<int> s;
int main() {
    int n;
    cin>>n;
    for (int i =0; i<n; i++) {
        string com;
        int num;
        cin>>com;
        if (com == "push") {
            cin>>num;
            s.push(num);
        }
        else if (com == "top") {
            if (s.size() == 0) {
                cout<<-1<<endl;
            }
            else {
                cout<<s.top()<<endl;
            }
        }
        else if (com =="pop") {
            if (s.size() == 0) {
                cout<<-1<<endl;
            }
            else {
                cout<<s.top()<<endl;
                s.pop();
            }
        }
        else if (com=="size") {
            cout<<s.size()<<endl;
        }
        else if (com=="empty") {
            if (s.empty()) 
            cout<<1<<endl;
            else cout<<0<<endl;
        }
    }
}