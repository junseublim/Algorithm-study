#include <bits/stdc++.h>

using namespace std;




typedef struct {
    int weight;
    int price;
} Jewel;

vector<Jewel> jewels;
vector<int> bags;

bool compWeight( Jewel i, Jewel j) {
    return i.weight < j.weight;
}
struct cmp{
    bool operator()(Jewel t, Jewel u){
        return t.price < u.price;
    }
};

int main() {
    int n,k;
    cin>>n>>k;
    for (int i =0; i<n; i ++) {
        int m, v;
        cin>>m>>v;
        Jewel j = {m,v};
        jewels.push_back(j);
    }
    for (int i =0; i<k; i++) {
        int bag;
        cin>>bag;
        bags.push_back(bag);
    }
    sort(bags.begin(), bags.end());
    sort(jewels.begin(), jewels.end(), compWeight);
    long long total = 0;
    int j = 0;
    priority_queue<Jewel, vector<Jewel>,cmp> pq;
    for (int i =0; i<k; i++) {
        int possSize = bags[i];
        while (j<n && jewels[j].weight <= possSize) {
            pq.push(jewels[j]);
            j++;
        }
        if (pq.size()){
            int val = pq.top().price;
            total += (long long)val;
            pq.pop();
        }
    }
    cout<<total<<endl;
    
}