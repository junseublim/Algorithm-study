#include <bits/stdc++.h>

using namespace std;
int numbers[1001] = {0};
int last = -1;
int main() {
    int n, k;
    cin>>n>>k;
    int prime = 2;
    while (k > 0) {
        int i = 1;
        if (prime*i > n || numbers[prime*i]) {
            prime++;
            continue;
        }
        while(prime*i <= n) {
            if (numbers[prime*i]==0){
                numbers[prime*i] = 1;
                k--;
                //cout<<"found : "<<prime*i<<endl;
                if (k == 0) {
                    last = prime*i;
                    break;
                }
            }
            i++;
        }
        prime++;
    }
    cout<<last<<endl;

}