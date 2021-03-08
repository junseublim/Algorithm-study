#include <bits/stdc++.h>

using namespace std;
priority_queue<int, vector<int>, greater<int> > pq;
int main() {
    int C;
    cin>>C;
    while(C--){
        int n; cin>>n;
        for (int i=0; i<n; i++) {
            int temp;
            cin>>temp;
            pq.push(temp);
        }
        int total = 0;
        while(pq.size() >1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            total +=a+b;
            pq.push(a+b);
        }
        cout<<total<<endl;
        pq.pop();
    }
}