#include <bits/stdc++.h>

using namespace std;

double n,p;
int m;

double balance(double pay) {
    double value = (double)n;
    for (int i=0; i<m; i++) {
        value= value + value*((p/12)/100);
        value -= pay;
    }
    return value;
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        cin>>n>>m>>p;
        double s = 0, e = n * (1.0 + (p/12)/ 100);
        for (int i =0; i<100; i++) {
            double mid = (s+e)/2;
            double ret = balance(mid);
            if (ret <= 0) {
                e = mid;
            }
            else {
                s = mid;
            }
        }
        printf("%.10f\n", e);
    }
    
}