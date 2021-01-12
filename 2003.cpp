#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin>>n>>m;
    vector<int> numbers(n);
    for (int i=0; i<n; i++) {
        cin>>numbers[i];
    }
    int start = 0, end = 0, sum = 0;
    int count = 0;
    while( start <= n ) {
        while (sum < m && end<n) {
            sum += numbers[end];
            end++;
        }
        if (sum == m) {
            count++;
        }
        else if (sum < m) {
            break;
        }
        start++;
        end = start;
        sum = 0;
    }
    cout<<count<<endl;
}