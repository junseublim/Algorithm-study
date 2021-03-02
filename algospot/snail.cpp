#include <bits/stdc++.h>

using namespace std;
int n,m;
double cache[1001][2002];

double getPerc(int days, int meters) {
    if (days == m) {
        if (meters >= n) {
            return 1;
        }
        return 0;
    }
    double &ret = cache[days][meters];
    if (ret != -1) return ret;
    ret = 0.75 * getPerc(days+1, meters+2);
    ret += 0.25 * getPerc(days+1, meters+1);
    return ret;
}

int main() {
    int C;
    cin>>C;
    while(C--){
        cin>>n>>m;
        for (int i =0; i<1001; i++) {
            for (int j=0; j<2002; j++) {
                cache[i][j] = -1;
            }
        }
        printf("%0.10f\n", getPerc(0,0));
    }
}