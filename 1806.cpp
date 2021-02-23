#include <bits/stdc++.h>

using namespace std;

int n,s;
int sum[100001];
int minimum = 1000010;
int main() {
    cin>>n>>s;
    sum[0] = 0;
    for(int i =1;i<=n;i++) {
        cin>>sum[i];
        sum[i] += sum[i-1];
    }
    int i = 1;
    int j = 1;
    while(j <=n && i <= n) {
        if (sum[j]-sum[i-1] >= s) {
            minimum = min(minimum, j-i+1);
            if (i ==j) {
                i++;
                j++;
            }
            else {
                i++;
            }
        }
        else {
            j++;
        }

    }
    if (minimum == 1000010) {
        cout<<0<<endl;    
        return 0;
    }
    cout<<minimum<<endl;

}