#include <bits/stdc++.h>

using namespace std;
int nums[1000000];
int cache[1000000];

int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i =0; i<1000000; i++) {
        cache[i] = -1000000000;
    }
    int n;
    cin>>n;
    for (int i=0; i< n; i++) {
        cin>>nums[i];
    }
    int longest = 0;
    int s, e;
    int mid;
    int idx;
    for (int i=0; i< n; i++) {
        s = 0;
        e = longest;
        idx = 0;
        while (s<=e) {
            mid = (s+e)/2;
            if (cache[mid] < nums[i]) {
                idx = mid;
                s = mid+1;
            }
            else {
                e= mid-1;
            }
        }
        cache[idx+1] = nums[i];
        if (idx+1 > longest) longest = idx+1;
    }
    cout<<longest<<"\n";
}