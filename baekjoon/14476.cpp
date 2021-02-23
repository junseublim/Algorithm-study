#include <bits/stdc++.h>

using namespace std;

int ans1 = -1;
int ans2 = -1;
vector<int> leftgcd;
vector<int> rightgcd;
vector<int> numbers;

int gcd(int a, int b) {
    if (b == 0 ) return a;
    return gcd(b, a%b);
}

int main() {
    int n;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    numbers.assign(n,0);
    leftgcd.assign(n,0);
    rightgcd.assign(n,0);
    for (int i=0; i<n;i++) {
        cin>>numbers[i];
    }
    for (int i =1; i<n; i++) {
        leftgcd[i] = gcd(leftgcd[i-1], numbers[i-1]);
        rightgcd[i] = gcd(rightgcd[i-1], numbers[n-i]);  
        // cout<<"leftgcd "<<i<<" "<<leftgcd[i]<<endl;
        //  cout<<"rightgcd : "<<i<<" "<<rightgcd[i]<<endl;
    }
    for (int i =0; i<n; i++) {
        int gcdV = gcd(leftgcd[i], rightgcd[n-i-1]);
        int out = numbers[i];
        if (gcdV == 0) continue;
        if (out % gcdV != 0 && gcdV > ans1) {
            ans1 =gcdV;
            ans2 = out; 
        } 
    }
    cout<<ans1<<" "<<ans2<<endl;

}