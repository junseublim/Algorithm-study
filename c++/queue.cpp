#include <bits/stdc++.h>

using namespace std;


#define MAX_QUEUE_SIZE 5

class Queue {
    private:
        int capacity;
        int rear;
        int front;
        int size;
        int *array;
    public:
        Queue() {
            size = 0;
            capacity = MAX_QUEUE_SIZE;
            front = capacity-1;
            rear = capacity-1;
            array = (int*)malloc(sizeof(int)*MAX_QUEUE_SIZE);
        }
        int first();
        void pop();
        void push(int a);
};

int Queue::first() {
    if (front == rear) {
        cout<<"queue empty!"<<endl;
        return -1;
    }
    return array[(front+1)%capacity];
}
void Queue::pop() {
    if (front == rear) {
        cout<<"queue empty!"<<endl;
        return;
    }
    front = (front+1)%capacity;
    cout<<"front : "<<front<<" rear : "<<rear<<endl;
}
void Queue::push(int a) {
    if (front == (rear+1)%capacity) {
        cout<<"queue full!"<<endl;
        return;
    }
    rear = (rear+1)%capacity;
    array[rear] = a;
    cout<<"front : "<<front<<" rear : "<<rear<<endl;
}

int main() {
    Queue* q = new Queue();
    q->push(1);
    q->push(2);
    q->push(3);
    q->push(4);
    q->push(5);
    cout<<q->first()<<endl;
    q->pop();
    q->pop();
    cout<<q->first()<<endl;
    q->pop();
    cout<<q->first()<<endl;
    q->pop();
    q->pop();
    cout<<q->first()<<endl;
}