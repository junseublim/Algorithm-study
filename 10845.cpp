#include<bits/stdc++.h>

using namespace std;
queue<int> q;
int main() {
    int n;
    cin>>n;
    for (int i =0; i<n; i++) {
        string com;
        int num;
        cin>>com;
        if (com == "push") {
            cin>>num;
            q.push(num);
        }
        else if (com == "front") {
            if (q.size() == 0) {
                cout<<-1<<endl;
            }
            else {
                cout<<q.front()<<endl;
            }
        }
        else if (com =="pop") {
            if (q.size() == 0) {
                cout<<-1<<endl;
            }
            else {
                cout<<q.front()<<endl;
                q.pop();
            }
        }
        else if (com=="size") {
            cout<<q.size()<<endl;
        }
        else if (com=="empty") {
            if (q.empty()) 
            cout<<1<<endl;
            else cout<<0<<endl;
        }
        else if (com=="back") {
             if (!q.size()) 
            cout<<-1<<endl;
            else cout<<q.back()<<endl;
        }
    }
}