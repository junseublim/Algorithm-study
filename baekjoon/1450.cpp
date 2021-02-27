#include <bits/stdc++.h>
using namespace std;
long long n,c;
vector<long long> a;
vector<long long> b;
vector<long long> ac;
vector<long long> bc;
int cnt = 1;
void comb1(int index, long long sum) {
    if (index == a.size()) {
        ac.push_back(sum);     
        return;
    }
    comb1(index+1, sum+a[index]);
    comb1(index+1, sum);
}
void comb2(int index, long long sum) {
    if (index == b.size()) {
        bc.push_back(sum);    
        return;
    }
    comb2(index+1, sum+b[index]);
    comb2(index+1, sum);
}
int main() {   
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>c;
    for (int i =0; i<n/2;i++) {
        long long  temp;
        cin>>temp;
        a.push_back(temp);
    }
    for (int i =n/2; i<n;i++) {
        long long  temp;
        cin>>temp;
        b.push_back(temp);
    }
    comb1(0, 0);
    comb2(0, 0);
    sort(ac.begin(), ac.end());
    sort(bc.rbegin(), bc.rend());
    long long i = 0;
    long long j = 0;
    long long cnt = 0;
    for (; j<bc.size(); j++) {
        while (i <ac.size() && ac[i]+bc[j] <= c) {
            i++;
        }
        cnt+= i;
        if (ac.size() == i) i--;
    }
    cout<<cnt<<"\n";

    
    
}