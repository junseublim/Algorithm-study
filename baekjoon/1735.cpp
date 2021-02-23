#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    if (b ==0) return a;
    return gcd(b, a%b);
}

int main () {
    int a,b, x,y;
    cin>>a>>b>>x>>y;

    int divider = b *y;
    int first = a *y;
    int second = b*x;
    int dividend = first + second;
    int denominator = gcd(dividend, divider);
    cout<<dividend/denominator<< " "<<divider/denominator<<endl;

}