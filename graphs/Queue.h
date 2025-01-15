//
//  Queue.h
//  Graphs
//
//  Created by kevin pratama on 21/02/23.
//

#include<iostream>
#ifndef Queue_h
#define Queue_h

using namespace std;

class Node {
public:
    int data;
    Node * next;
};

class Queue {
private:
    Node * front;
    Node * rear;
public:
    Queue () {
        front=rear=nullptr;
    }
    
    void Enqueue (int value);
    int Dequeue ();
    int IsEmpty();
};

void Queue:: Enqueue (int value) {
    Node * t;
    t = new Node;
    t->data = value;
    t->next = nullptr;
    
    if(t==nullptr)
        return;
    
    if(front==nullptr)
        front=rear=t;
    else {
        rear->next = t;
        rear = t;
    }
}

int Queue:: Dequeue() {
    Node *p = front;
    int x = -1;
    
    if(front==nullptr&&rear==nullptr)
        return x;
    else {
        front=front->next;
        x = p->data;
        delete p;
    }
    return x;
}

int Queue:: IsEmpty() {
    return front==nullptr;
}

#endif /* Queue_h */
