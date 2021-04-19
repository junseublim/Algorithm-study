#include <bits/stdc++.h>

using namespace std;
vector<int> vi;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; 
    cin>>n;
    stack<int> s;
    priority_queue<int, vector<int>, less<int> > pq1;
    priority_queue<int, vector<int>, greater<int> > pq2;
    for (int i =0; i<n; i++) {
        int temp;
        cin>>temp;
        if (temp <=0) {
            pq2.push(temp);
        }
        else pq1.push(temp);
    }
    int total = 0;
    while(!pq1.empty()) {
        int a = pq1.top();
        pq1.pop();
        if (!pq1.empty()) {
            int b = pq1.top();
            pq1.pop();
            if (b == 1) {
                total += a+b;
            }
            else total += a*b;
        }
        else total += a;
    }
    while(!pq2.empty()) {
        
        int a = pq2.top();
        pq2.pop();
        if (!pq2.empty()) {
            int b = pq2.top();
            pq2.pop();
            total += a*b;
        }
        else total += a;
    }
    cout<<total;

}