#include <bits/stdc++.h>

using namespace std;
int cache[1000000];
int num[1000000];

void go(int n, int cnt, int m) {
    if (n == 1) {
        if(cache[n] != -1 && cache[n] < cnt) {
            return;
        }
        cache[n] = cnt;
        num[n] = m;
        return;
    }
    if (cache[n] != -1 && cache[n] < cnt) return;
    cache[n] = cnt;
    num[n] = m;
    if (n%2 == 0) {
        go(n/2, cnt+1, 2);
    }
    if (n%3 == 0) {
        go(n/3, cnt+1, 3);
    }
    go(n-1, cnt+1, 1);
}


int main() {
    int n;
    cin>>n;
    memset(cache, -1, sizeof(cache));
    go(n, 0, 0);
    cout<<cache[1]<<endl;
    stack<int> s;
    int i = 1;
    s.push(1);
    while(true) {
        if (num[i] == 2) {
            s.push(i*2);
            i *=2;
        }
        else if (num[i] == 3) {
            s.push(i*3);
            i*=3;
        }
        else if (num[i] == 1) {
            s.push(i+1);
            i+=1;
        }
        else break;
    }
    while(!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }
}
