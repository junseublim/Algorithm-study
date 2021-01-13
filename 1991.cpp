#include <bits/stdc++.h>

using namespace std;
int n;

typedef struct Node Node;
struct Node {
    char c;
    Node* left;
    Node* right;
};
vector<Node*> nodes;
queue<Node> q;

int findNode(char c) {
    //cout<<"looking for : "<<c<< " node size: "<<nodes.size()<<endl;
    for (int i =0; i<nodes.size(); i++) {

        if ((*nodes[i]).c == c) {

            return i;
        }
    }
    return -1;
}

void preorder(Node* node) {
    if (node == nullptr){
        return;
    }
    printf("%c", node->c);
    preorder(node->left);
    preorder(node->right);
}

void inorder(Node* node) {
    if (node == nullptr){
        return;
    }
    inorder(node->left);
    printf("%c", node->c);
    inorder(node->right);
}
void postorder(Node* node) {
    if (node == nullptr){
        return;
    }
    postorder(node->left);
    postorder(node->right);
    printf("%c", node->c);
}

int main() {
    cin>>n;
    for (int i=0; i<n; i++) {
        char nodeC, left, right;
        cin>>nodeC>>left>>right;
        int pos = findNode(nodeC);
        if (pos != -1) {
            if (left != '.') {
                int leftPos = findNode(left);
                if (leftPos != -1) {
                    nodes[pos]->left = nodes[leftPos];
                }
                else {
                    Node* newLeft = new Node({left, nullptr, nullptr});
                    nodes.push_back(newLeft);
                    nodes[pos]->left = newLeft;                }
            }
             if (right != '.') {
                int rightPos = findNode(right);
                if (rightPos != -1) {
                    nodes[pos]->right = nodes[rightPos];
                }
                else {
                    Node* newright = new Node({right, nullptr, nullptr});
                    nodes.push_back(newright);
                    nodes[pos]->right = newright;
                }
            }
        }
        else {
            Node* newNode = new Node ({nodeC, nullptr,nullptr});
            nodes.push_back(newNode);
            if (left != '.') {
                int leftPos = findNode(left);
                if (leftPos != -1) {
                    newNode->left = nodes[leftPos];
                }
                else {
                    Node* newLeft = new Node({left, nullptr, nullptr});
                    nodes.push_back(newLeft);
                    newNode->left = newLeft;
                }
            }
             if (right != '.') {
                int rightPos = findNode(right);
                if (rightPos != -1) {
                   newNode->right = nodes[rightPos];
                }
                else {
                    Node* newright = new Node({right, nullptr, nullptr});
                    nodes.push_back(newright);
                    newNode->right = newright;
                }
            }
        }
        
    }

    preorder(nodes[0]);
    printf("\n");
    inorder(nodes[0]);
    printf("\n");
    postorder(nodes[0]);
}

