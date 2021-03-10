#include <bits/stdc++.h>

using namespace std;
int n,m;
map<string, int> nameToId;
vector<string> names;
vector<vector<int> > canEatfoods;
vector<vector<int> > personsCanEat;
vector<int> hasEaten;
vector<int> foodChosen;

int minV;

void solve(int cnt) {
    if (cnt>=minV) return;
    int nameIdx = 0;
    while(nameIdx < n && hasEaten[nameIdx]) {
        nameIdx++;
    }
    if (nameIdx == n) {
        minV = cnt;
        return;
    }
    for (int i =0; i<canEatfoods[nameIdx].size(); i++) {
        int food = canEatfoods[nameIdx][i];
        for (int j=0; j<personsCanEat[food].size(); j++) {
            hasEaten[personsCanEat[food][j]]++;
        }
        solve(cnt+1);
        for (int j=0; j<personsCanEat[food].size(); j++) {
            hasEaten[personsCanEat[food][j]]--;
        }
    }
    
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--) {
        cin>>n>>m;
        minV = 50;
        names.clear();
        nameToId.clear();
        hasEaten.assign(n,0);
        foodChosen.assign(m,0);
        canEatfoods.assign(n,vector<int>(0,0));
        personsCanEat.assign(m,vector<int>(0,0));
        for (int i=0; i<n;i++) {
            string t;
            cin>>t;
            names.push_back(t);
            nameToId.insert(make_pair(t,i));
        }
        for (int i =0; i<m;i++) {
            int num;
            cin>>num;
            for (int j =0; j< num;j++) {
                string t;
                cin>>t;
                personsCanEat[i].push_back(nameToId.find(t)->second);
                canEatfoods[nameToId.find(t)->second].push_back(i);
            }
        }
        solve(0);
        cout<<minV<<endl;
    }
}