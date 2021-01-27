#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
vector<vector<string> > memo(101, vector<string>(101, " "));

string addString(string a, string b) {
    
    int i = a.size()-1;
    int j = b.size()-1;
    string c ="";
    int carry = 0;
    while( i>= 0 && j>=0) {
        int temp = (a[i]-'0' + b[j]-'0');
        if (carry) temp += 1;
        carry = 0;
        if (temp >= 10) {
            carry = 1;
            temp %= 10;
        }
        c.insert(0, to_string(temp));
        i--;j--;
    }
    while (i>=0) {
        int temp = a[i]-'0';
        if (carry) temp += 1;
        carry = 0;
        if (temp >= 10) {
            carry = 1;
            temp %= 10;
        }
        c.insert(0,to_string(temp));
        i--;
    }
    while (j>=0) {
        int temp = b[j]-'0';
        if (carry) temp += 1;
        carry = 0;
        if (temp >= 10) {
            carry = 1;
            temp %= 10;
        }
        c.insert(0,to_string(temp));
        j--;
    }
    if (carry) {
        c.insert(0,to_string(1));
    }
    // cout<<"add "<<a<<" "<<b<<endl;
    // cout<<c<<endl;
    return c;
    
}

string comb(ll n, ll k) {
    //cout<<"memo"<<n<<" "<<k<<endl;
    if (memo[n][k] != " ") {
      //  cout<<"found"<<endl;
        return memo[n][k];
    }
    if (n < k){
        return  "0";
    } else if (k == 0) {
        return "1";
    }
    else return memo[n][k] = addString(comb(n-1,k), comb(n-1,k-1));
}   
int main() {
    ll n;
    ll k;
    cin>>n>>k;
    string s = comb(n,k);
    cout<<s<<endl;
}