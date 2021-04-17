#include <bits/stdc++.h>

using namespace std;


int main() {
    int T; 
    cin>>T;
    while(T--) {
        int n; 
        cin>>n;
        priority_queue<pair<int, int> > maxHeap;
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > minHeap;
        int able[1000000];
        memset(able ,0, sizeof(able));
        for (int i=0; i<n; i++) {
            char C;
            int m;
            cin>>C>>m;
            if (C == 'I') {
                maxHeap.push(make_pair(m, i));
                minHeap.push(make_pair(m, i));
                able[i] = 1;
            }
            else {
                if (m == 1) {
                    while(!maxHeap.empty() && able[maxHeap.top().second] == 0) {
                        maxHeap.pop();
                    } 
                    pair<int,int> pii = maxHeap.top();
                    maxHeap.pop();
                    able[pii.second] = 0;
                }
                else {
                     while(!minHeap.empty() && able[minHeap.top().second] == 0) {
                        minHeap.pop();
                    } 
                    pair<int,int> pii = minHeap.top();
                    minHeap.pop();
                    able[pii.second] = 0;
                }
            }
        }
        while(!maxHeap.empty() && able[maxHeap.top().second] == 0) {
            maxHeap.pop();
        } 
        while(!minHeap.empty() && able[minHeap.top().second] == 0) {
            minHeap.pop();
        }
        if (maxHeap.empty() || minHeap.empty()) {
            cout<<"EMPTY\n";
        }
        else {
            cout<<maxHeap.top().first<<" "<<minHeap.top().first<<"\n";
        }
    }
}