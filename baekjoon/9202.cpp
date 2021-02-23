#include <bits/stdc++.h>

using namespace std;

int w;
string words[300000];
int b;
string board[4];
bool visited[4][4] = {false};

typedef struct Trie Trie;
struct Trie {
    char c;
    bool isEnd;
    bool hasBeenAdded;
    vector<Trie*> children;
    
}; 

int score[9] = {0, 0, 0, 1, 1, 2, 3, 5, 11};
int yMove[8] = {0,0,1,1,1,-1,-1,-1};
int xMove[8] = {-1,1,-1,-0,1,-1,0,1};
vector<Trie*> lastChar;
int maxScore = 0;
string longest = "";
int countFound = 0; 
bool hasChild(Trie* node, char c) {
    for (auto x: node->children) {
        if (x->c == c) {
            return true;
        }
    }
    return false;
}
Trie* getChild(Trie* node, char c) {
    for (auto x: node->children) {
        if (x->c == c) {
            return x;
        }
    }
    return NULL;
}

void dfs(int y,int x, Trie* node, string curWord) {
    if (node->isEnd && !node->hasBeenAdded) {
        countFound++;
        maxScore += score[curWord.size()];
        if (curWord.size() > longest.size()) {
            longest = curWord;
        }
        else if (curWord.size() == longest.size()) {
            longest = longest.compare(curWord) < 0 ? longest : curWord;
        }
        node->hasBeenAdded = true;
    }
    for (int i=0; i<8; i++) {
        int nextY = y + yMove[i];
        int nextX = x + xMove[i];
        if (nextY >= 0 && nextY <4 && nextX >= 0 && nextX <4) {
            if (hasChild(node,board[nextY][nextX]) && !visited[nextY][nextX]) {
                Trie* nextNode = getChild(node, board[nextY][nextX]);
                curWord.push_back(board[nextY][nextX]);
                visited[nextY][nextX] = true;
                dfs(nextY, nextX, nextNode, curWord);
                curWord.pop_back();
                visited[nextY][nextX] = false;
            }
        }
    }
}

void boggle(Trie* root) {
    for (int i =0; i<4; i++) {
        cin>>board[i];
    }    
    for (int i =0; i<4; i++) {
        for (int j=0; j<4; j++) {
            if (hasChild(root,board[i][j])) {
                Trie* node = getChild(root, board[i][j]);
                string s = "";
                s.push_back({board[i][j]});
                visited[i][j] = true;
                dfs(i,j, node, s);
                visited[i][j] = false;
            }
        }
    }
    for (auto x: lastChar) {
        x->hasBeenAdded = false;
    }
}

void addWord(Trie* root, string word) {
    // cout<<"add word: "<<word<<endl;
    Trie* node = root;
    int i = 0;
    while (i < word.size()) {
        if (hasChild(node,word[i])) {
            // cout<<"node "<<node->c<<" has child with "<<word[i]<<endl;
            node = getChild(node, word[i]);
        }
        else {
            // cout<<"create new node "<<word[i]<<" to push "<<node->c<<endl;
            Trie* child = new Trie({word[i], false, false});
            node->children.push_back(child);
            node = child;
        }
        i++;
    }
    node->isEnd = true;
    lastChar.push_back(node);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>w;
    Trie* root = new Trie({'*',false, false});
    for (int i=0; i<w; i++) {
        cin>>words[i];
        addWord(root, words[i]);
    }
    cin>>b;
    for (int i =0; i<b; i++) {
        boggle(root);
        cout<<maxScore<<" "<<longest<<" "<<countFound<<"\n";
        maxScore = 0;
        longest = "";
        countFound = 0;
    }
    
}
