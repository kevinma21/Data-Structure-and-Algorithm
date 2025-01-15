#include<iostream>
#ifndef Queue_h
#define Queue_h
using namespace std;

class Node {
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Queue {
private:
    int size;
    int front;
    int rear;
    Node **q;
public:
    Queue(int size);
    ~Queue();
    void Enqueue(Node *x);
    Node *Dequeue();
    int IsEmpety();
};


Queue:: Queue (int size) {
    this->size = size;
    front=rear=-1;
    q = new Node*[this->size+1];
}

Queue:: ~Queue() {
    delete []q;
}

void Queue:: Enqueue(Node *x) {
    if((rear+1)%size==front)
        cout<<"Queue is full"<<endl;
    else {
        rear = (rear+1)%size;
        q[rear] = x;
    }
}

Node* Queue:: Dequeue() {
    Node *x=NULL;
    if(IsEmpety())
        cout<<"Queue is Empty"<<endl;
    else {
        front = (front+1)%size;
        x = q[front];
    }
    
    return x;
}

int Queue:: IsEmpety() {
    return front==rear;
}

#endif /* Queue_h */
