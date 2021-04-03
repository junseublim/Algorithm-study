#include <bits/stdc++.h>

using namespace std;

typedef struct Node {
    char c;
    vector<Node*> children;
    int isEnd;
    Node(int cc) {
        c = cc;
        isEnd = 0;
    }
} Node;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin>>n>>m;
    Node* root = new Node('1');
    for (int i=0; i<n;i++) {
        string a;
        cin>>a;
        Node* next = root;
        for (int j=0; j<a.size(); j++) {
            int found = 0;
            for (int k =0; k<next->children.size(); k++) {
                if (next->children[k]->c == a[j]) {
                    next = next->children[k];
                    found = 1;
                    break;
                }
            }
            if (!found) {
                    Node* temp = new Node(a[j]);
                    next->children.push_back(temp);
                    next = temp;
            }
        }
        next->isEnd = 1;
    }
    int cnt = 0;
    for (int i=0; i<m; i++) {
        string a;
        cin>>a;
        Node* next = root;
        bool isIn = true;
        for (int j=0; j<a.size(); j++) {
            int found = 0;
            for (int k =0; k<next->children.size(); k++) {
                if (next->children[k]->c == a[j]) {
                    next = next->children[k];
                    found = 1;
                    break;
                }
            }
            if (!found) {
                isIn = false;
                break;
            }
        }
        if (isIn && next->isEnd) {
            cnt++;
        }
    }
    cout<<cnt<<endl;

}