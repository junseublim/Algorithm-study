#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int minDiff = 2000000001;
int main() {
    int n;
    cin>>n;
    for (int i =0; i<n;i++) {
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());

    int i = 0;
    int j = n-1;
    int y,x;
    while(i<j) {
        if (abs(v[i]+v[j]) < minDiff) {
            y=v[i];
            x=v[j];
            minDiff = abs(v[i] + v[j]);
        }
        if (v[i]+v[j] < 0) {
            i++;
        }
        else if (v[i]+v[j] > 0) {
            j--;
        }
        else {
            break;
        }
    }
    cout<<y<<" "<<x<<endl;
}