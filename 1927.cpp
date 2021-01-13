#include <bits/stdc++.h>

using namespace std;

int main() {
    priority_queue<int, vector<int>,greater<int>> pq;
    int n;
    scanf("%d", &n);
    int x;
    for (int i=0; i <n; i++) {
         scanf("%d", &x);
        if (x ==0 ){
            if (pq.size()) {
                printf("%d\n",pq.top());
                pq.pop();
            }
            else {
                printf("%d\n",0);
            }
        }
        else {
            pq.push(x);
        }
    }
}