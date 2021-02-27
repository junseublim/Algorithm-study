#include<bits/stdc++.h>
using namespace std;

int primes[4000001];
const int MAX = 4000001;
vector<int> p;
void getprimes() {
    primes[0] = 1;
    primes[1] = 1;
    for (int i =2;  i< MAX; i++) {
        if (primes[i] == 1) continue;
        else {
            p.push_back(i);
            for (int j = i*2; j<MAX; j+=i) {
                primes[j] = 1;
            }
        }
    }
}

int main() {
    int n;
    cin>>n;
    getprimes();
    int i = 0;
    int j = 0;
    int temp = 0;
    int cnt = 0;
    while (i < p.size() && j< p.size()) {
        if (temp < n) {
            temp+=p[j++];
        }
        else if (temp > n) {
            temp-=p[i++];
        }
        else {
            cnt++;
            temp += p[j++];
            temp -= p[i++];
        }
        
    }
    cout<<cnt<<endl;
}