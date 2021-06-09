#include <bits/stdc++.h>

using namespace std;

class LinkedList {
    public: 
        int element;
        LinkedList* next;
        LinkedList* last;
    public: 
        LinkedList() {
            element = -1;
            next = NULL;
            last = this;
        };
        void append(int v) {
            LinkedList* nextNode = new LinkedList();
            nextNode->element = v;
            last->next = nextNode;
            last = nextNode;
        }
};


int main() {
    LinkedList* l = new LinkedList();
    l->append(1);
    l->append(5);
    l->append(2);
    l->append(4);
    l->append(3);
    l->append(6);
    while(l != NULL) {
        cout<<l->element<<endl;
        l = l->next;
    }


}