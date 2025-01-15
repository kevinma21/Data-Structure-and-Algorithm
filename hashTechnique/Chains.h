#include<iostream>
#ifndef Chains_h
#define Chains_h
using namespace std;

class Node {
public:
    int data;
    Node *next;
};

class Chains {
private:
    Node *h[10];
    void SortedInsert(Node **hash, int x);
    int Hash(int key);
public:
    Chains() {
        for(int i=0;i<10;i++)
            h[i] = nullptr;
    }
   
    Node * Search(int key);
    void Insert(int key);
    
};

void Chains:: SortedInsert(Node **hash, int x) {
    Node *t,*q=NULL,*p=*hash;
    
    t=new Node;
    t->data=x;
    t->next=nullptr;
    
    if(*hash==nullptr){
        *hash=t;
    }else{
        while(p&&p->data<x){
            q=p;
            p=p->next;
        }
        
        if(p==*hash){
            p->next=*hash;
            *hash=p;
        }else{
            t->next=q->next;
            q->next=t;
        }
    }
}

Node * Chains:: Search(int key) {
    Node *p = h[Hash(key)];
    while(p!=nullptr) {
        if(key==p->data) {
            return p;
        }
        p=p->next;
    }
    return nullptr;
}

int Chains:: Hash(int key) {
    return key % 10;
}

void Chains:: Insert(int key) {
    int index = Hash(key);
    SortedInsert(&h[index], key);
}




#endif /* Chains_h */
