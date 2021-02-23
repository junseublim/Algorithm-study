#include<bits/stdc++.h>

using namespace std;
int n;
int total = 0;

void dfs(int cnt, int curr) {
    if (cnt == 3) {
        if (curr == 0)
            total++;
        return;
    }
    int three =3;
    for (; three<=curr; three+=3) {
        dfs(cnt+1, curr-three);
    }
}

int main() {
    cin>>n;
    n /=3;
    int k =1;
    for (int i = 3; i<=n; i++) {
        total+= k;
        k++;
    }
    cout<<total<<endl;
    
}