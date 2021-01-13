#include <bits/stdc++.h>

using namespace std;
map<string, int> m;
int main() {
    float count = 0;
    string s;
    while(getline(cin,s)){
        count++;
        if (m.count(s)){
            m[s]++;
        }
        else {
            m[s] = 1;
        }
    }
    vector<pair<string, float>> v;
    for (auto x: m) {
        v.push_back({x.first, float(x.second) / count * 100});
    }
    sort(v.begin() ,v.end());
    for (auto x: v) {
        printf("%s %.4f\n", x.first.c_str(), x.second);
    }


}