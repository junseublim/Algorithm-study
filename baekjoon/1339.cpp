#include <bits/stdc++.h>

using namespace std;
int N;
int maxValue = 0;
vector<int> aToN (26, 0);

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;

    for (int i= 0; i<N; i++) {
        string temp;
        cin>>temp;
        int mult = 1;
        for (int j =temp.size() -1; j>=0; j--,mult*=10) {
            aToN[temp[j]-'A'] += mult;
        }
    }
    int biggest = 9;
    sort(aToN.rbegin(), aToN.rend());
    for (auto a : aToN) {
        if (a != 0) {
            maxValue +=  biggest * a;
            biggest--;
        }   
    }
    cout<<maxValue<<endl;
    
}