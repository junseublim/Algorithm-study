#include <bits/stdc++.h>

using namespace std;
int nums[1000001];
int cache[1000000];
int pos[1000001];

int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(cache, 0, sizeof(cache));
    int n;
    cin>>n;
    for (int i=1; i< n+1; i++) {
        cin>>nums[i];
    }
    nums[0] = -1000000001;
    int longest = 0;
    int s, e;
    int mid;
    int idx;
    for (int i=1; i< n+1; i++) {
        s = 0;
        e = longest;
        idx = 0;
        while (s<=e) {
            mid = (s+e)/2;
            if (nums[cache[mid]] < nums[i]) {
                idx = mid;
                s = mid+1;
            }
            else {
                e= mid-1;
            }
        }
        cache[idx+1] = i;
        pos[i] = idx+1;
        if (idx+1 > longest) longest = idx+1;
    }
    cout<<longest<<"\n";
    int k = cache[longest];
    int curr = longest;
    stack<int> st;
    for (int i = k; i > 0; i--) {
        cout<<"num["<<i<<"] = "<<nums[i]<<" pos : "<<pos[i]<<endl;
        if (pos[i] == curr) {
            st.push(nums[i]);
            curr--;
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}