//
//  Stack.h
//  BST
//
//  Created by kevin pratama on 08/02/23.
//
#include<iostream>
#ifndef Stack_h
#define Stack_h

using namespace std;

class Node {
public:
    Node * lchild;
    int data;
    Node * rchild;
};

class Stack {
private:
    int size;
    int top;
    Node **arr;
public:
    Stack(int size);
    ~Stack();
    
    void Push(Node *x);
    int StackTop();
    Node * Pop();
    int IsEmpty();
    
};

Stack:: Stack(int size) {
    this->size = size;
    arr = new Node*[this->size];
    top = -1;
}

Stack:: ~Stack() {
    delete []arr;
}

void Stack:: Push(Node *x) {
    if(top==size-1)
        return;
    else {
        top++;
        arr[top] = x;
    }
    
}

Node *Stack:: Pop() {
    Node * x=NULL;
    if(top==-1)
        return NULL;
    else {
        x = arr[top--];
    }
        return x;
}

int Stack:: StackTop() {
    int x = arr[top]->data;
    return x;
}

int Stack:: IsEmpty() {
    return top==-1 ? 1 : 0;
}

#endif /* Stack_h */
