#include <bits/stdc++.h>

using namespace std;
int n;
typedef pair<int, int> pii;

vector<pii> lb;
//first == 데우는 시간
//second == 먹는 시간
bool cmp(pii a, pii b) {
    if (a.second > b.second) {
        return true;
    }
    else if (a.second == b.second)
    {
        if (a.first < b.first){
            return true;
        }
    }
    return false;
}

int main() {
    int C;
    cin>>C;
    while(C--) {
        cin>>n;
        lb.clear();
        int total = 0;
        for (int i=0; i<n; i++) {
            pii temp;
            cin>>temp.first;
            lb.push_back(temp);
            total+= temp.first;
        }
        for (int i=0; i<n; i++) {
            cin>>lb[i].second;
        }
        sort(lb.begin(), lb.end(), cmp);
        int add = 0;
        int time = 0;
        for (int i=n-1; i>=0; i--) {  
            if (lb[i].second > time + add) {
                add = lb[i].second - time;
            }
            time  = time + lb[i].first;
        }
        cout<<total+add<<endl;

    }
}