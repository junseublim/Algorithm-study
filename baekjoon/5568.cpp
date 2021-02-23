#include <bits/stdc++.h>

using namespace std;
vector<int> cards;
int curNum = 0;
int n, k;
set<int> st;
vector<int> visited;
void bt(int currCount) {
    if (currCount == k-1) {
        st.insert(curNum);
        return;
    }
    for (int i = 0; i<n; i++) {
        if (!visited[i]) {
            int prevNum = curNum;
            string temp = to_string(curNum) + to_string(cards[i]); 
            curNum = atoi(temp.c_str());
            visited[i] = 1;
            bt(currCount+1);
            visited[i] = 0;
            curNum = prevNum;
        }
        
    }
}

int main() {

    cin>>n>>k;
    cards.assign(n, 0);
    visited.assign(n, 0);
    for (int i =0; i<n; i++) {
        cin>>cards[i];
    }
    for (int i =0; i<n; i++) {
        int prevNum = curNum;
        string temp = to_string(curNum) + to_string(cards[i]); 
        curNum = atoi(temp.c_str());
        visited[i] = 1;
        bt(0);
        visited[i] = 0;
        curNum = prevNum;
    }
    cout<<st.size()<<endl;
    // for (auto x: st) {
    //     cout<<x<<endl;
    // }
}