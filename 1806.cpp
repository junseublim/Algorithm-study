#include <bits/stdc++.h>
using namespace std;
#define INF 987654321;
int main() {
    int n, m;
    cin>>n>>m;
    vector<int> numbers(n);
    for (int i=0; i<n; i++) {
        cin>>numbers[i];
    }
    int start = 0, end = 0, sum = 0;
    int minDif = INF;
    while( start <= n ) {
        while (sum < m && end<n) {
            sum += numbers[end];
            end++;
        }
        if (sum >= m) {
            //cout<<sum<<" "<<end<< ""<<start<<endl;
            int diff = end - start;
            minDif = min(diff, minDif);

        }
        else if (sum < m) {
            break;
        }
        start++;
        end = start;
        sum = 0;
    }
    if (minDif == 987654321) {
        cout<<0<<endl;
        return 0;
    }
    cout<<minDif<<endl;
}