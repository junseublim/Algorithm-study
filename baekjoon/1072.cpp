#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
    ll x,y;
    cin>>x>>y;
    ll z = y*100/x;
    
    ll start = 0, end = x;
    ll middle;
    ll newX, newY;
    ll newZ;
    ll least = x;
    if (z >= 99) {
        cout<<-1<<endl;
        return;
    }
    while (start <= end) {
        middle = (start+end)/2;
        newX = x + middle;
        newY = y + middle;
        newZ = newY*100/newX;
        if (newZ != z) {
            least = min(least, middle);
            end = middle-1;
        }
        else {
            start = middle + 1;
        }
    }
    cout<<least<<endl;


}