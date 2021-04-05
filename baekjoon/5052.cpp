#include<bits/stdc++.h>

using namespace std;

typedef struct Node {
    char c;
    vector<Node*> children;
    int isEnd; 
    Node(char cc) {
        c=cc;
        isEnd = 0;
    }
} Node;

bool cmp(string a, string b) {
    if (a.size() < b.size()) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        Node* root = new Node('1');
        int yes = 1;
        vector<string> vs (n,"");
        for (int i=0; i<n; i++) {
            string a;
            cin>>a;
            vs[i] = a;
        }
        sort(vs.begin(), vs.end(), cmp);
        for (int i=0; i<n; i++) {
            if (!yes) {
                break;
            }
            string a = vs[i];
            Node* next = root;
            for(int j =0; j<a.size(); j++) {
                int found = 0;
                for (int k=0; k<next->children.size();k++) {
                    if (next->children[k]->c == a[j]) {
                        next = next->children[k];
                        found =1;
                        break;
                    }
                }
                if (!found) {
                    Node* temp = new Node(a[j]);
                    next->children.push_back(temp);
                    next = temp;
                }
                if (next->isEnd) {
                    yes = 0;
                    break;
                }
            }
            next->isEnd = 1;
        }
        if (yes) {
            cout<<"YES\n";
        }
        else {
            cout<<"NO\n";
        }
    }
}