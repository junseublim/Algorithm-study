#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
vector<int> selected;
vector<char> characters;
set<string> answers;
int L,C;
set<char> vowels = {'a','i','e','o','u'};

void check() {
    string s;
    int hasVowel = 0;
    int hasTwoCons = 0;
    for (int i =0; i<selected.size(); i++) {
        if (selected[i]) {
            s.push_back(characters[i]);
            if (vowels.count(characters[i])) {
                hasVowel = 1;
            }
            else {
                hasTwoCons++;
            }
        }
    }
    if (hasVowel && hasTwoCons>=2) {
        answers.insert(s);
    }
}

void dfs(int pos, int count) {
    if (count == L) {
        check();
        return;
    }
    for(int i= pos; i< C; i++) {
        if (selected[i] ==0) {
            selected[i] = 1;
            dfs(i, count+1);
            selected[i] = 0;
        }
    }
}

int main() {

    cin>>L>>C;
    selected.assign(C,0);
    for (int i=0; i<C; i++) {
        char c;
        cin>>c;
        characters.push_back(c);
    }
    sort(characters.begin(), characters.end());
    for (int i=0; i<C; i++) {
        dfs(i, 0);
    }
    for (auto answer: answers) {
        cout<<answer<<endl;
    }
    

}