#include <bits/stdc++.h>

using namespace std;
const int MAX = 1000000;
string p;
int k;
vector<bool> numbers (MAX+1, false);
vector<int> primes;
int main() {
    cin>>p>>k;
    for (int i=2; i<k; i++) {
        if(numbers[i] == false) {
            primes.push_back(i);
            for (int j = i*2; j<k; j+=i) {
                numbers[j] = true;
            }
        }
    }
    
    for (auto prime : primes) {
        int i =0;
        int div = 0;
        while(i < p.size()) {
            div = div*10 + (p[i]-'0');
            div = div%prime;
            i++;
        }
        if (div == 0) {
            cout<<"BAD "<<prime<<endl;
            return 0;
        }
        
    }
    cout<<"GOOD"<<endl;



}