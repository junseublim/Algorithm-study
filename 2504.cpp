#include <bits/stdc++.h>

using namespace std;


typedef struct {
    int num;
    char c;
} StackItem;
stack<StackItem> brackets;

int main() {
    string inp;
    cin>>inp;
    int total = 0;
    int current = 0;
    for (auto c: inp) {
        if (c == '(' || c=='[') {
            StackItem si = {0, c};
            brackets.push(si);
        }
        else if (c ==')') {
            if (brackets.empty()) {
                cout<<0<<endl;
                return 0;
            }
            if (brackets.top().c == '(') {
                brackets.pop();
                brackets.push({2, '*'});
                continue;
            }
            while(brackets.top().c != '(') {
                int top = brackets.top().num;
                current += top;
                brackets.pop();
                if (brackets.empty()) {
                    cout<<0<<endl;
                    return 0;
                }
            }
            brackets.pop();
            brackets.push({current*2, '*'});
            current = 0;
        }
        else if (c ==']') {
            if (brackets.empty()) {
                cout<<0<<endl;
                return 0;
            }
            if (brackets.top().c == '[') {
                brackets.pop();
                brackets.push({3, '*'});
                
                continue;
            }
            while(brackets.top().c != '[') {
                int top = brackets.top().num;
                current += top;
                brackets.pop();
                if (brackets.empty()) {
                    cout<<0<<endl;
                    return 0;
                }
            }
            brackets.pop();
            brackets.push({current*3, '*'});
            current = 0;
        }
    }
    while(brackets.size()) {
        if (brackets.top().c != '*') {
            cout<<0<<endl;
            return 0;
        }
        total += brackets.top().num;
        brackets.pop();
    }
    cout<<total<<endl;
    return 0;
}