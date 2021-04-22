#include <bits/stdc++.h>
using namespace std;

int cntBits(int n) {
    int ret = 0;
    for (int i =0; i < 32; i++) { 
        if (1<<i & n) {
            ret++;
        }
    }
    return ret;
}

int getSmallest(int n) {
    for (int i = 0; i<32; i++) {
        if (1<<i & n) {
            return 1<<i;
        }
    }
    return 0;
}


int main() {
    int n,k;
    cin>>n>>k;
    int cnt = 0;
    while (cntBits(n) > k) {
        //최소 bit 두개 구해서 차이만큼 더하기
        int smallest, secondSmall;
        smallest = getSmallest(n);
        secondSmall = getSmallest(n & ~smallest);
        cnt += secondSmall - smallest;
        n-= smallest;
        n += secondSmall;

    }   
    cout<<cnt<<endl;
}