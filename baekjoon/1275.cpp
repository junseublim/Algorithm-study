#include <bits/stdc++.h>

using namespace std;
int n,q;
typedef long long ll;
vector<ll> numbers;
vector<ll> original;

ll sum(ll a, ll k) {
    if (a != 1) {
        return sum(1,k)-sum(1,a-1);
    }
    ll s = 0;
    while (k>=1) {
        s += numbers[k];
        k -= k&-k;
    }
    return s;
}
void add(int i, ll x) {
    while(i <= n) {
        numbers[i] += x;
        i += i&-i;
    }
}
void replace(int i, ll x, ll originalV) {
    while(i <= n) {
        numbers[i] += x - originalV;
        i += i&-i;
    }
}

int main() {
    scanf("%d %d",&n, &q);
    numbers.assign(n+1, 0);
    original.assign(n+1, 0);
    ll temp;
    for (int i =1; i<=n; i++) {
        scanf("%lld", &temp);
        original[i] = temp;
        add(i, temp);
    }   
    ll a,b,x,y; 
    for (int i =0; i<q; i++) {
        scanf("%lld %lld %lld %lld", &x, &y, &a, &b);
        if (x<y){
            printf("%lld\n", sum(x,y));  
        }
        else {
           printf("%lld\n", sum(y,x));
        }
         
        replace(a,b, original[a]);
        original[a] = b;
       
    }
}