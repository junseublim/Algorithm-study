#include <bits/stdc++.h>

using namespace std;

vector<int> russia;
vector<int> korea;
int n;
int main() {
    int C;
    cin>>C;
    while(C--) {
        cin>>n;
        korea.clear();
        russia.clear();
        for (int i =0;i<n; i++) {
            int temp;
            cin>>temp;
            russia.push_back(temp);
        }
        for (int i =0;i<n; i++) {
            int temp;
            cin>>temp;
            korea.push_back(temp);
        }
        sort(russia.rbegin(), russia.rend());
        sort(korea.rbegin(), korea.rend());
        int ks = 0;
        int cnt = 0;
        for (int i =0; i<n; i++) {
            if (korea[ks] >= russia[i]) {
                cnt++;
                ks++;
            }
        }
        cout<<cnt<<endl;


    }
}