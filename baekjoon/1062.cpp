#include <iostream>
#include <vector>
using namespace std;

vector<bool> alphabet (26, false);
int needed[5] = {0, 'c'-'a', 'n'-'a','t'-'a','i'-'a'};
vector<string> words;
int n, k;
int selectCount;
int maxCount;

void checkWords() {
    int currCount = 0;
    for (auto word : words) {
        bool able = true;
        for (auto c : word) {
            if (!alphabet[c-'a'])
                able = false;
        }
        if (able)
            currCount++;
    }
    if (currCount > maxCount) {
        maxCount = currCount;
    }
}

void dfs(int index) {
    alphabet[index] = true;
    selectCount++;
    if (selectCount == k) {
        checkWords();
    }
    else {
        for (int i= index+1; i<26; i++) {
            if (!alphabet[i])
                dfs(i);
        }        
    }
    
    alphabet[index]= false;
    selectCount--;
}


int main() {
    
    cin>>n>>k;
    for (int i=0; i<n; i++) {
        string temp;
        cin>>temp;
        words.push_back(temp);
    }

    for (auto x: needed) {
        alphabet[x] = true;
    }
    if (k < 5) {
        cout<<0<<endl;
    }
    else {
        k -= 5;
        if (k == 0) {
            checkWords();
        }
        for (int i=0; i<26; i++) {
            if (!alphabet[i]) {
                dfs(i);
            }
        }
        cout<<maxCount<<endl;
    }

}