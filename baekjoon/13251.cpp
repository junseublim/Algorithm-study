#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, n=0;
    cin>>m;
    vector<int> numColor;
    for (int i =0; i<m; i++) {
        int temp;
        cin>>temp;
        numColor.push_back(temp);
        n+=temp;
    }
    int k;
    cin>>k;
    double percentage = 0;
    for (auto x: numColor) {
        int divider = n;
        int dividend = x;
        double temp =1;
        int cnt = k;
        while (cnt != 0) {
            temp *= double(dividend)/double(divider);
            dividend--;
            divider--;
            cnt--;
        }
        percentage += temp;
    }
    printf("%.10f\n", percentage);
}
