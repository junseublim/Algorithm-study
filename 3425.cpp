#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <string>
using namespace std;
vector<string> program;
stack<int> s;


void getProgram() {
    
    string temp;
    string num;
    while (true) {
        cin>>temp;
        if (temp == "QUIT") break;
        if (temp == "NUM") {
            cin>>num;
            temp = temp + " " + num;
        }
        program.push_back(temp);
        if (temp == "END") break;
    }
}   

void getStack() {
    string com;
    for (int i =0; i< program.size(); i++) {
        com = program[i];
        long long v, v1, v2;
        if(com =="DUP") {
            if (s.size() < 1) {
                cout<<"ERROR"<<endl;
                return;
            }
            s.push(s.top());
        }
        else if (com == "POP") {
            if (s.size() < 1) {
                cout<<"ERROR"<<endl;
                return;
            }
            s.pop();
        }
        else if (com == "INV") {
            if (s.size() < 1) {
                cout<<"ERROR"<<endl;
                return;
            }
            v = s.top();
            s.pop();
            s.push(v*-1);
        }
        else if (com == "SWP") {
            if (s.size() < 2) {
                cout<<"ERROR"<<endl;
                return;
            }
            v1 = s.top();
            s.pop();
            v2 = s.top();
            s.pop();
            s.push(v1);
            s.push(v2);
        }
        else if (com == "ADD") {
            if (s.size() < 2) {
                cout<<"ERROR"<<endl;
                return;
            }
            v1 = s.top();
            s.pop();
            v2 = s.top();
            s.pop();
            if (abs(v2+v1) > pow(10,9)) {
                cout<<"ERROR"<<endl;
                return;
            }
            s.push(v1+v2);
        }
        else if (com == "SUB") {
            if (s.size() < 2) {
                cout<<"ERROR"<<endl;
                return;
            }
             v1 = s.top();
            s.pop();
             v2 = s.top();
            s.pop();
            if (abs(v2-v1) > pow(10,9)) {
                cout<<"ERROR"<<endl;
                return;
            }
            s.push(v2-v1);
        }
        else if (com == "MUL") {
            if (s.size() < 2) {
                cout<<"ERROR"<<endl;    
                return;
            }
            v1 = s.top();
            s.pop();
            v2 = s.top();
            s.pop();
            if (abs(v2*v1) > pow(10,9)) {
                cout<<"ERROR"<<endl;
                return;
            }
            s.push(v2*v1);
        }
        else if (com =="DIV") {
            if (s.size() < 2) {
                cout<<"ERROR"<<endl;
                return;
            }
            v1 = s.top();
            s.pop();
            v2 = s.top();
            s.pop();
            if (v1 == 0) {
                cout<<"ERROR"<<endl;
                return;
            }
            if (abs(v2/v1) > pow(10,9)) {
                cout<<"ERROR"<<endl;
                return;
            }
            s.push(v2/v1);
        }
        else if (com == "MOD") {
            if (s.size() < 2) {
                cout<<"ERROR"<<endl;
                return;
            }
            v1 = s.top();
            s.pop();
            v2 = s.top();
            s.pop();
            if (v1 == 0) {
                cout<<"ERROR"<<endl;
                return;
            }
             if (abs(v2%v1) > pow(10,9)) {
                cout<<"ERROR"<<endl;
                return;
            }
            s.push(v2%v1);
        }
        else if (com.substr(0,3) == "NUM") {
            long long x = stoi(com.substr(4));
            s.push(x);
        }
    }
    if (s.size() != 1) {
        cout<<"ERROR"<<endl;
    }
    else {
        cout<<s.top()<<endl;
    }
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    program.assign(0, "");
    while(true) {
        program.clear();
        getProgram();
        if (program.size() == 0) break;
        int count;
        cin>>count;
        for (int i=0; i< count; i++) {
            long long temp;
            cin>>temp;
            s.push(temp);
            getStack();
            while(s.size()){
                s.pop();
            }
        }
        cout<<endl;

    }
}