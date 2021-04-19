#include <bits/stdc++.h>

using namespace std;
vector<int> vi;
int getMin() {
    int minIdx = 0, minV = 98654321;
    for (int i =0; i< vi.size()-1; i++) {
        if (vi[i] + vi[i+1] < minV) {
            minIdx= i;
            minV = vi[i] + vi[i+1];
        }
    }
    return minIdx;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; 
    cin>>n;
    stack<int> s;
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i =0; i<n; i++) {
        int temp;
        cin>>temp;
        pq.push(temp);
    }
    int total = 0;
    while(pq.size()>1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        total += a+b;
        pq.push(a+b);
    }
    cout<<total;

}