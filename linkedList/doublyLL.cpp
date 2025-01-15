#include<iostream>
using namespace std;

class Node {
public:
    Node *prev;
    int data;
    Node *next;
};

class DoublyLL {
private:
    Node *first;
public:
    DoublyLL() {first = NULL; };
    DoublyLL(int A[], int n);
    ~DoublyLL();
    
    void Display();
    int Length();
    void Insert(int index, int x);
    int Delete(int index);
    void Reverse();
    
};

DoublyLL:: DoublyLL(int A[], int n) {
    Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next=first->prev=NULL;
    last=first;
    for(int i=1;i<n;i++) {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last=t;
    }
}

void DoublyLL:: Display() {
    Node *p = first;
    while(p) {
        cout<< p->data << " ";
        p=p->next;
    }
    cout<<endl;
}

DoublyLL:: ~DoublyLL() {
    Node *p = first;
    while(p) {
        first = first->next;
        delete p;
        p=first;
    }
}

int DoublyLL:: Length() {
    int len = 0;
    Node *p = first;
    while(p) {
        len++;
        p=p->next;
    }
    return len;
}

void DoublyLL:: Insert(int index, int x) {
    Node *p = first, *t;
    if(index < 0 || index > Length())
        return;
    if(index==0){
        t = new Node;
        t->data = x;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    } else {
        for(int i=0;i<index-1;i++)
            p=p->next;
        t = new Node;
        t->data = x;
        
        t->prev = p;
        t->next = p->next;
        if(p->next)
            p->next->prev = t;
        p->next = t;
    }
}

int DoublyLL:: Delete(int index) {
    Node *p = first;
    int x;
    
    if(index < 1 || index > Length())
        return -1;
    
    if(index==1){
        first = first->next;
        if(first) first->prev = NULL;
        x = p->data;
        delete p;
    } else {
        for(int i=0;i<index-1;i++)
            p=p->next;
        
        if(p->next) {
            p->next->prev = p->prev;
            p->prev->next = p->next;
        } else {
            p->prev->next = NULL;
        }
        x = p->data;
        delete p;
    }
    return x;
}

void DoublyLL:: Reverse() {
    Node *p = first, *temp;
    
    while(p!=NULL) {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p=p->prev;
        if(p!=NULL && !p->next)
            first=p;
    }

}



//int main() {
//    int A[] = {10,20,30,40,50};
//    DoublyLL LL(A, 5);
//    LL.Reverse();
//    LL.Display();
//
//    return 0;
//}
