#include <bits/stdc++.h>

using namespace std;

int k;
vector<string> words;
int cache[15][15];
int minLength;
bool involves(const string& big, const string& small) { 
    if (small.size() > big.size()) return false;
    for (int i =0; i<big.size();i++) {
        for (int j =0; j<small.size();j++) {
            if (big[i] == small[j]) {
                int cnt = 1;
                int ii = i+1;
                int jj = j+1;
                while (ii<big.size() && jj < small.size()) {
                    if (big[ii] == small[jj]){
                        cnt++;
                        ii++;
                        jj++;
                    }
                    else break;
                }
                if (cnt == small.size()) {
                    return true;
                }
            }   
        }
    }
    return false;
}
int Merge(const string& a, const string& b) {
    for (int i=0; i<a.size(); i++) {
        if (a[i] == b[0]){
            int ii = i+1;
            int jj = 1;
            int cnt = 1;
            while (ii<a.size()){
                if (a[ii] == b[jj]) {
                    ii++;
                    jj++;
                    cnt++;
                }
                else break;
            }
            if (ii == a.size()) {
                return cnt;
            }
        }
    }
    return 0;
}
void preprocess() {
    for (int i =0; i<words.size(); i++) {
        bool involved = false;
        for (int j =0; j< words.size(); j++) {
            if (i == j) continue;
            involved = involves(words[j],words[i]);
            if (involved) break;
        }
        if (involved) {
            words.erase(words.begin() + i);
            i--;
        }
    }
    for (int i =0; i<words.size(); i++) {
        for(int j=0; j<words.size(); j++) {
            if (i ==j) cache[i][j] = 0;
            else {
                cache[i][j] = Merge(words[i], words[j]);
            }
        }
    }

}

int restore(int index, set<int> s) {
    s.insert(index);
    if (s.size() == words.size()) return words[index].size();
    int length = 987654321;
    for (int i =0; i<words.size(); i++) {
        if (s.count(i))continue;
        length = min(length, int(words[index].size()) + restore(i, s) - cache[index][i]);
    }
    return length;
}
 
string reconstruct(int last, set<int> s) {
    s.insert(last);
    if (s.size() == words.size()) return "";
    for (int i =0; i<words.size(); i++) {
        if (s.count(i)) continue;
        int temp = restore(i, s) + words[last].size() - cache[last][i];
        s.erase(last);
        if (temp == restore(last, s)) {
            s.insert(last);
            return words[i].substr(cache[last][i]) + reconstruct(i, s);
            break;
        }
        s.insert(last);
    }
    return "";
}

int main() {
    int C;
    cin>>C;
    while(C--) {
        cin>>k;
        words.clear();
        for (int i =0; i<k; i++) {
            string temp;
            cin>>temp;
            words.push_back(temp);
        }
        preprocess();
        int k = words.size();
        set<int> s;
        int minLength = 987654321;
        string ss;
        int first = 0;
        for (int i =0; i<words.size(); i++) {
            int temp = restore(i,s);   
            if (temp < minLength) {
                minLength = temp;
                first = i;
            }
        }
        set<int> s2;
        cout<<words[first]<<reconstruct(first, s2)<<endl;
        
    }
}