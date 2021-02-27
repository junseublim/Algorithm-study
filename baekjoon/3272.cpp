#include <bits/stdc++.h>

using namespace std;
vector<int> nums;
int main() {
    int n;
    cin>>n;
    for (int i =0; i<n; i++) {
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }
    int x;
    cin>>x;
    sort(nums.begin(), nums.end());
    int i =0, j = nums.size()-1;
    int cnt = 0;
    while (i<j) {
        if (nums[i] + nums[j] == x) {
            cnt++;
            i++;
            j--;
        }
        else if( nums[i] + nums[j] > x) {
            j--;
        }
        else {
            i++;
        }
    }
    cout<<cnt<<endl;

    
}