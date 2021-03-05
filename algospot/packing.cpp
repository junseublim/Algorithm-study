#include<bits/stdc++.h>

using namespace std;

int n, w;
string items[101];
int weights[101];
int values[101];
int cache[1001][101];
vector<int> picked;
int pack(int curW, int index) {
    if (index == -1) {
        return 0;
    }
    int &ret = cache[curW][index];
    if (ret != -1) return ret;
    int itemWeight = weights[index];
    int itemValue = values[index];
    ret = 0;
    if (curW - itemWeight >= 0)
        ret = pack(curW-itemWeight,index-1) + itemValue;
    ret = max(ret, pack(curW,index-1));
    return ret;
}
void reconstruct(int weight, int index){
    if (index == -1) return;
    if (pack(weight,index) == pack(weight,index-1)) {
        reconstruct(weight, index-1);
    }
    else {
        picked.push_back(index);
        reconstruct(weight - weights[index], index-1);
    }
}

int main() {
    int C;
    cin>>C;
    while(C--) {
        cin>>n>>w;
        picked.clear();
        for (int  i=0; i<1001; i++) {
            memset(cache[i], -1, sizeof(cache[i]));
        }
        for (int i =0; i<n; i++) {
            string temp;
            int w;
            int v;
            cin>>temp>>w>>v;
            items[i] = temp;
            weights[i] = w;
            values[i] = v;  
        }
        cout<<pack(w, n-1)<<" ";
        reconstruct(w,n-1);
        cout<<picked.size()<<"\n";
        for (auto x: picked) {
            cout<<items[x]<<"\n"; 
        }
    }
}