#include <bits/stdc++.h>

using namespace std;
int n,m;
vector<double> locations;

bool decisions(double mid) {
    double prev = locations[0];
    int placed = 1;
    for (int i =1; i<m; i++) {
        if (locations[i] - prev >= mid) {
            placed++;
            prev = locations[i];
        }
    }    
    return (placed>=n);
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        cin>>n>>m;
        locations.clear();
        for (int i =0; i<m; i++) {
            double temp;
            cin>>temp;
            locations.push_back(temp);
        }
        double lo = 0, hi = 241;
        for (int it =0; it<100; it++){
            double mid = (lo+hi)/2.0;
            if (decisions(mid))
                lo = mid;
            else hi = mid;
        }
        printf("%0.2f\n", lo);
    }
}