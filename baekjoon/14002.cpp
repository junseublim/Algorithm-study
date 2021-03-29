#include <bits/stdc++.h>

using namespace std;
int num[1000];
int pos[1000];
int cache[1001];
int main() {
    int n;
    cin>>n;
    memset(cache, -1, sizeof(cache));
    for (int i = 0; i<n; i++) {
        cin>>num[i];
    }
    int longest = 0;
    for (int i =0; i<n; i++) {
        int idx = longest;
        while(idx > 0 && num[i] <= num[cache[idx]]){
            idx--;
        }
        cache[idx+1] = i;
        pos[i] = idx+1;
        if (idx+1>longest) longest = idx+1;
    }
    cout<<longest<<endl;
    int k = cache[longest];
    int curr = longest;
    stack<int> s;
    for (int i = k; i >= 0; i--) {
        //cout<<"num["<<i<<"] = "<<num[i]<<" pos : "<<pos[i]<<endl;
        if (pos[i] == curr) {
            s.push(num[i]);
            curr--;
        }
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

}