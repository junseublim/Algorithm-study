#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,m;
int p[100001];
ll w[100001];

int findf(int a) {
    if (p[a] == a) return a;
    //여기서 무게도 같이 업데이트 한다
    int t = p[a];
    p[a]= findf(p[a]);
    w[a] = w[t] + w[a];
    return p[a];
}

void unionf(int a, int b, ll c) {
    findf(a);
    findf(b);
    int ap = findf(a);
    int bp = findf(b);
    p[ap] = bp;
    w[ap] = w[b] - w[a] + c;
}


int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    while(true) {
        cin>>n>>m;
        if (n ==0 )break;
        memset(w, 0, sizeof(w));
        for (int i =0; i<100001; i++) {
            p[i] = i;
        }
        for (int i =0; i<m; i++) {
            char query;
            int a,b;
            ll c;
            cin>>query;
            if (query=='!') {
                cin>>a>>b>>c;
                unionf(a,b,c);
                
            }
            else {
                cin>>a>>b;
                if (findf(a) != findf(b)) {
                    cout<<"UNKNOWN\n";
                }
                else {
                    cout<<w[a]-w[b]<<"\n";
                }
            }
        }
        
    }
    
}