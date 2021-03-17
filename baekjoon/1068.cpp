#include <bits/stdc++.h>

using namespace std;

typedef struct Node
{
    bool isValid;
    int childrenCnt;
    Node *children[50];
    Node()
    {
        isValid = false;
        childrenCnt = 0;
    }
} Node;

int main()
{
    int n;
    cin >> n;
    int root;
    Node *nodes[50];
    for (int i = 0; i < 50; i++)
    {
        Node *temp = new Node();
        nodes[i] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        nodes[i]->isValid = true;
        if (temp != -1)
        {
            nodes[temp]->children[nodes[temp]->childrenCnt++] = nodes[i];
        }
        else
            root = i;
    }
    int remove;
    cin >> remove;
    nodes[remove]->isValid = false;
    int cnt = 0;
    queue<Node *> q;
    if (nodes[root]->isValid)
    {
        q.push(nodes[root]);
    }
    while (q.size())
    {
        Node *node = q.front();
        q.pop();
        int pushed = 0;
        for (int i = 0; i < node->childrenCnt; i++)
        {
            if (node->children[i]->isValid)
            {
                q.push(node->children[i]);
                pushed++;
            }
        }
        if (!pushed)
            cnt++;
    }
    cout << cnt << endl;
}