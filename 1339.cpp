#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int N;
int maxLength =0 ;
int maxValue = 0;
vector<string> words;
vector<int> aToN (26, -1);
vector<vector<char>> pos;
int posSize;

void addAll() {
    int currTotal = 0;
    for (int i =0; i< words.size(); i++) {
        string word = words[i];
        int num = 0;
        for (int j = 0; j<word.size(); j++) {
            num += aToN[word[j]-'A'] * pow(10, (word.size() - j -1));
            //cout<<"char "<<word[j]<<" is "<< aToN[word[j]-'A']<<endl;
        }

        currTotal += num;
    }
    maxValue = max(currTotal, maxValue);
}

void dfs(int curPos, int biggest) {
    // cout<<"dfs "<<curPos<<endl;

    if (curPos == posSize) {
        // cout<<"addALL"<<endl;
        addAll();
        return;
    }
    for (int j =0; j < pos[curPos].size(); j++) {
        if (aToN[pos[curPos][j]-'A'] == -1) {
            aToN[pos[curPos][j]-'A'] = biggest;
           // cout<<"found "<<pos[curPos][j]<<endl;
            dfs(curPos, biggest-1);
            aToN[pos[curPos][j]-'A'] = 0;
        }
    }
    // cout<<"All"<<endl;
    dfs(curPos+1, biggest);
    
}

int main () {
    cin>>N;
    for (int i= 0; i<N; i++) {
        string temp;
        cin>>temp;
        words.push_back(temp);
        maxLength = max(maxLength, int(temp.size()));
    }
    pos.assign(26, vector<char>());
    vector<bool> assigned(26,false);
    int pushLoc = 0;
    for (int i= 0; i<maxLength; i++) {
        int pushed = 0;
        for (auto word: words) {
            if (word.size() >= maxLength-i && !assigned[word[word.size()-(maxLength-i)]-'A']) {
                assigned[word[word.size()-(maxLength-i)]-'A'] = true;
                pos[pushLoc].push_back(word[word.size()-(maxLength-i)]);
                pushed = 1;
            }
        }
        if (pushed) {
            pushLoc++;
        }
    }
    // for (auto x: pos) {
    //     for (auto y: x) {
    //         cout<<y<<" ";
    //     }
    //     cout<<endl;
    // }
    posSize = 0;
    int i = 0;
    while(i < 26) {
        if (pos[i].size() != 0){
            posSize = i+1;
            // cout<<"curr Pos: "<< pos[posSize].size()<<endl;
        }
        i++;
    }
    // cout<<"posSize: " <<posSize <<endl;
    dfs(0, 9);
    cout<<maxValue<<endl;
    
}