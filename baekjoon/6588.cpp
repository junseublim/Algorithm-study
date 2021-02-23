#include <bits/stdc++.h>

using namespace std;
const int MAX = 1000000;
bool numbers[MAX+1] = {false};
vector<int> oddPrimes;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int found = 1;
    for (int i =2; i<=MAX; i++) {
        if (numbers[i] == false) {
            if (i%2 == 1) {
                oddPrimes.push_back(i);
            }
            int j = i;
            while (j<=MAX) {
                numbers[j] = true;
                j +=i;
            }
        }
    }
    int first = 0;
    int last = oddPrimes.size()-1;
    int n;
    while(true) {
        cin>>n;
        if (n == 0) break;
        int a = first;
        int b = n -oddPrimes[first];
        while(true) {
            if ( b == *lower_bound(oddPrimes.begin(), oddPrimes.end(), b)) {
                cout<<n<<" = "<<oddPrimes[a]<<" + "<<b<<"\n";
                break;
            }
            a++;
            b = n - oddPrimes[a];
        }
    }
    
    
}