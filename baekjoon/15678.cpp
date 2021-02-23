#include<bits/stdc++.h>

using namespace std;
int n;
int d;
typedef long long ll;
vector<ll> bridges;
vector<ll> maximums;
typedef pair<ll,int> pli;

struct cmp{
    bool operator()(pli a, pli b){
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    }
};
priority_queue<pli, vector<pli>, cmp> pq;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>d;
    bridges.assign(n,0);
    maximums.assign(n,0);
    for (int i=0; i<n; i++) {
        cin>>bridges[i];
    }
    maximums[0] = bridges[0];
    pq.push(make_pair(maximums[0],0));
    for (int i=1; i<n; i++) {
        pli temp;
        temp = pq.top();
        //cout<<"i : "<<i<<endl;
        //cout<<temp.first<<" "<<temp.second<<endl;
        while(i - temp.second > d) {
            pq.pop();
            temp = pq.top();
            //cout<<temp.first<<" "<<temp.second<<endl;
        }
        if (temp.first < 0) {
            maximums[i] = bridges[i];
        }
        else {
            maximums[i] = temp.first + bridges[i];
        }
        pq.push(make_pair(maximums[i], i));
    }
    // for (int i=0; i<n; i++) {
    //     cout<<maximums[i]<<" ";
    // }
    cout<<endl;
    cout<<*max_element(maximums.begin(), maximums.end())<<"\n";
}