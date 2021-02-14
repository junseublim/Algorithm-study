#include <bits/stdc++.h>

using namespace std;
int n,m,k;
int sz;
typedef long long ll;
vector<ll> tree;

int getMult(int loc) {
    if (loc >= tree.size()) return 1;
    if (tree[loc] != 1) return tree[loc];
    else {
        tree[loc] = getMult(loc*2) * getMult(loc*2+1);
        return tree[loc];
    }
}

void change(int loc, ll newV) {
    loc += sz;
    tree[loc] = newV;
    loc /= 2;
    while (loc >= 1) {
        tree[loc] = tree[loc*2] * tree[loc*2+1];
        tree[loc] %= 1000000007;
        loc /= 2;
    }
}
void Multiply(int a, int b) {
    a +=sz;
    b += sz;
    ll mult = 1;
    while (a<=b) {
        if (a%2==1) mult *= tree[a++];
        mult %= 1000000007;
        if (b%2==0) mult *= tree[b--];
        mult %= 1000000007;
        a/=2;
        b/=2;
    }
    cout<<mult<<"\n";
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    sz = pow(2, ceil(log2(n)));
    tree.assign(sz*2, 1);
    for (int i = 0; i<n; i++) {
        cin>>tree[sz+i];
    }
    getMult(1);
    for (int i=0; i<m+k; i++) {
        ll a,b,c;
        cin>>a>>b>>c;
        if (a == 1) {
            change(b-1,c);
         }
        else {
            Multiply(b-1,c-1);
        }
    }
}