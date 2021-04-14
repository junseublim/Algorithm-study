#include <bits/stdc++.h>

using namespace std;

typedef struct Character {
    char c;
    int cnt;
    Character(char cc, int ccnt){
        c=cc;cnt=ccnt;
    }
} Character;
stack<Character> s;
string str;
string bomb;
int main() {
    cin>>str>>bomb;
    for (int i =0; i<str.size(); i++) {
        if (s.size() == 0) {
            if (bomb[0] == str[i]) {
                s.push(Character(str[i], 1));
            }
            else {
                s.push(Character(str[i], 0));
            }
        }
        else {
            int idx = s.top().cnt;
            if (bomb[idx] == str[i]) {
                s.push(Character(str[i], idx+1));
            }
            else {
                if (bomb[0] == str[i]) {
                    s.push(Character(str[i], 1));
                }
                else s.push(Character(str[i], 0));
            }
        }
        if (s.top().cnt == bomb.size()) {
            for(int i =0; i<bomb.size(); i++) {
                s.pop();
            }
        }
    }
    stack<char> ss;
    while(!s.empty()){
        ss.push(s.top().c);
        s.pop();
    }
    if (ss.empty()) {
        cout<<"FRULA"<<endl;
    }
    else{
        while(!ss.empty()) {
            cout<<ss.top();
            ss.pop();
        }
        cout<<endl;
    }
}