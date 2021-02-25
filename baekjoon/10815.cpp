#include <bits/stdc++.h>

using namespace std;
int n,m;
vector<int> cards;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i =0; i<n; i++) {
        int temp;
        cin>>temp;
        cards.push_back(temp);
    }
    sort(cards.begin(), cards.end());
    cin>>m;
    for (int i =0; i<m; i++) {
        int target;
        cin>>target;
        int s = 0;
        int found = 0;
        int e = cards.size()-1;
        while(s<=e) {
            int mid = s+e;
            mid /=2;
            if (cards[mid] < target) {
                s = mid+1;
            }
            else if (cards[mid] > target) {
                e = mid-1;
            }
            else {
                found = 1; 
                break;
            }
        }
        cout<<found<<" ";
    }
}