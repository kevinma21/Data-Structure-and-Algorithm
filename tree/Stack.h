//
//  Stack.h
//  Tree
//
//  Created by kevin pratama on 05/02/23.
//

#include<iostream>
#include"Queue.h"
#ifndef Stack_h
#define Stack_h
using namespace std;


class Stack {
private:
    int size;
    int top;
    Node **S;
public:
    Stack(int size);
    ~Stack();

    void Push(Node *x);
    Node * Pop();
    Node* Peek(Node *index);
    int IsEmpty();
    int IsFull();
    int StackTop();
    int IsBalanced(char *a);
};

Stack:: Stack(int size) {
    this->size = size;
    S = new Node*[this->size];
    top = -1;
}

Stack:: ~Stack() {
    delete []S;
}

void Stack:: Push(Node *x) {
    if(top==size-1){
        cout<<"Stack overflow"<<endl;
    } else {
        top++;
        S[top] = x;
    }
}

Node* Stack:: Pop() {
    Node *x = NULL;
    if(top==-1) cout<<"Stack underflow"<<endl;
    else {
        x=S[top--];
    }
    return x;
}


int Stack:: IsEmpty() {
    return top==-1 ? 1 : 0;
}

int Stack:: IsFull() {
    return top==size-1;
}



#endif /* Stack_h */
