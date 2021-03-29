#include <bits/stdc++.h>

using namespace std;
int num[1000];
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
        while(num[i] <= cache[idx]){
            idx--;
        }
        cache[idx+1] = num[i];
        if (idx+1>longest) longest = idx+1;
    }
    cout<<longest<<endl;

}