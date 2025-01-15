#include<iostream>
using namespace std;

class Node {
public:
    Node *prev;
    int data;
    Node *next;
};

class CircularDoubly {
private:
    Node *head;
public:
    CircularDoubly() {head=NULL;};
    CircularDoubly(int A[], int n);
    ~CircularDoubly();
    
    int Length();
    void Display();
    void Insert(int index, int x);
    int Delete(int index);
    
};

CircularDoubly:: CircularDoubly(int A[], int n) {
    Node *t, *last;
    head = new Node;
    head->data = A[0];
    head->prev = head;
    head->next = head;
    last = head;
    
    for(int i=1;i<n;i++) {
        t = new Node;
        t->data = A[i];
        last->next = t;
        t->prev = last;
        t->next = head;
        head->prev = t;
        last = t;
    }
}

CircularDoubly:: ~CircularDoubly () {
    Node *p = head;
    do {
        head=head->next;
        delete p;
        p = head;
    } while(p!=head);
}

int CircularDoubly:: Length() {
    int len=0;
    Node *p = head;
    do{
        len++;
        p = p->next;
    } while(p!= head);
    
    return len;
}

void CircularDoubly:: Display() {
    Node *p = head;
    do {
        cout<< p->data << " ";
        p=p->next;
    } while(p!=head);
    cout<<endl;
}

void CircularDoubly:: Insert(int index, int x) {
    Node *p = head, *t = new Node;
    
    if(index < 0 || index > Length())
        return;
    if(index==0) {
        t->data = x;
        if(head==NULL) {
            head = t;
            head->prev = head;
            head->next = head;
        } else {
            t->prev = head->prev;
            head->prev->next = t;
            head->prev = t;
            t->next = head;
            head = t;
        }
    } else {
        t->data = x;
        for(int i=0;i<index-1;i++) p=p->next;
        t->next = p->next;
        p->next = t;
        t->next->prev = t;
        t->prev = p;
    }
}

int CircularDoubly:: Delete(int index) {
    Node *p = head;
    int x=0;
    if(index < 1 || index > Length())
        return -1;
    if(index==1){
        head=head->next;
        head->prev = p->prev;
        p->prev->next = head;
        x = p->data;
        delete p;
    } else {
        for(int i=0;i<index-1;i++) p=p->next;
        p->prev->next= p->next;
        p->next->prev = p->prev;
        x = p->data;
        delete p;
    }
    return x;
}

//int main() {
//    int A[] = {1,2,3,4,5};
//    CircularDoubly LL(A, 5);
//    
//    
//    LL.Display();
//    
//    return 0;
//}
