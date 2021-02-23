#include <bits/stdc++.h>

using namespace std;

typedef struct Node Node;
struct Node {
    int num;
    Node* left;
    Node* right;
};

Node* insert(Node* node, int x) {
    if (node == NULL) {
        node = new Node({x,nullptr, nullptr});
        return node;
    }
    else if (x < node->num) {
        Node* left = insert(node->left, x);
        node->left = left;
        return node;
    }
    else {
        Node* right = insert(node->right, x);
        node->right = right;
        return node;
    }

   
}
void preorder(Node* node) {
    if (node == nullptr){
        return;
    }
    printf("%d\n", node->num);
    preorder(node->left);
    preorder(node->right);
}
void postorder(Node* node) {
    if (node == nullptr){
        return;
    }
    postorder(node->left);
    postorder(node->right);
    printf("%d\n", node->num);
}

int main() {
    int x;
    Node* root = NULL;
    while(cin>>x) {
        root = insert(root,x);
    }
    postorder(root);
    
}