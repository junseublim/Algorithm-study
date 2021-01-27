#include <bits/stdc++.h>

using namespace std;
vector<int> lottery;
vector<int> selected;
string s;
int k;
void backtrack(int curr, int s) {
    if (s == 6) {
        for (int i =0; i<k;i++) {
            if (selected[i]) {
                cout<<lottery[i]<<" ";
            }
        }
        cout<<"\n";
        return;
    }
    if (curr >= k ) {
        return;
    }
    selected[curr] = 1;
    backtrack(curr+1, s+1);
    selected[curr] = 0;
    backtrack(curr+1, s);
    
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(true){
        cin>>k;
        if (k == 0) break;
        lottery.assign(k,0);
        selected.assign(k,0);

        for (int i=0; i<k; i++) {
            cin>>lottery[i];
        }
        backtrack(0,0);
        cout<<"\n";
    }
}