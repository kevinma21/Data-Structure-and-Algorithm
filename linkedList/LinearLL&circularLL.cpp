#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
}*first=NULL, *second=NULL, *third=NULL, *head;


void create (int A[], int n) {
    Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;
    
    for(int i=1;i<n;i++){
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    
}

void create2 (int A[], int n) {
    Node *t, *last;
    second = new Node;
    second->data = A[0];
    second->next = NULL;
    last = second;
    
    for(int i=1;i<n;i++){
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    
}

void display(Node *p) {
    while(p!=NULL) {
        cout<<p->data<<" ";
        p=p->next;
    }
}


void Rdisplay(Node *p) {
    if(p!=NULL) {
        cout<<p->data<<" ";
        Rdisplay(p->next);
    }
}

int count (Node *p) {
    int c=0;
    while(p) {
        c++;
        p=p->next;
    }
    return c;
}

int Rcount (Node *p) {
    if(p)
        return count(p->next)+1;
    else
        return 0;
}

int sum(Node *p) {
    int sum = 0;
    while(p) {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int Rsum(Node *p) {
    if(p)
        return Rsum(p->next)+p->data;
    else
        return 0;
}

int max(Node *p) {
    int max=INT_MIN;
    while(p) {
        if(max < p->data) max = p->data;
        p=p->next;
    }
    return max;
}

int Rmax(Node *p) {
    int max=INT_MIN;
    if(p==0)
        return INT_MIN;
    else {
        max = Rmax(p->next);
        return (max > p->data) ? max : p->data;
    }
}

int min(Node *p) {
    int min=INT_MAX;
    while(p) {
        if(min > p->data) min = p->data;
        p=p->next;
    }
    return min;
}

int Rmin(Node *p) {
    int min=INT_MAX;
    if(p==0)
        return INT_MAX;
    else {
        min = Rmin(p->next);
        return (min < p->data) ? min : p->data;
    }
}

Node * Lsearch(Node *p, int x) {
    Node *q=0;
    while(p) {
        if(x == p->data) {
            if(p == first ) return p;
            else {
                q->next = p->next ;
                p->next = first;
                first = p;
            }
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}

Node * Rsearch(Node *p, int x) {
    if(p==NULL)
        return NULL;
    if(p->data == x)
        return p;
    return Rsearch(p->next, x);
}

void insert(Node *p, int index, int x) {
    Node *t;
    if(index < 0 || index > count(p))
        return;
    t = new Node;
    t->data=x;
    if(index==0){
        t->next = first;
        first = t;
    } else {
        for(int i=0;i<index-1;i++)
            p=p->next;
        t->next=p->next;
        p->next = t;
    }
}

void insertLast(int x) {
    Node *t, *last;
    t= new Node;
    t->data=x;
    t->next=NULL;
    if(first==NULL)
        first=last=t;
    else {
        last=first;
        while(last->next) last=last->next;
        last->next=t;
        last=t;
    }
}

void sortedInsert(Node *p, int x) {
    Node *t,*q=NULL;
    t = new Node;
    t->data = x;
    t->next = NULL;
    if(first==NULL)
        first=t;
    else {
        while(p && p->data < x) {
            q = p;
            p = p->next;
        }
        if(p==first){
            t->next = first;
            first = t;
        } else {
            t->next = q->next;
            q->next = t;
        }
    }
    
}

void deletingFirst(Node *p) {
    first = first->next;
    delete p;
}

void deleteNode(Node *p, int pos) {
    Node *q=NULL;
    if(pos > count(p) || pos < 1)
        return;
    if(pos-1==0)
        deletingFirst(p);
    else {
        for(int i=0;i<pos-1;i++) {
            q = p;
            p=p->next;
        }
        q->next = p->next;
        delete p;
    }
    
}

int sorted(Node *p) {
    int x=INT_MIN;
    while(p) {
        if(p->data > x)
            x = p->data;
        else
            return 0;
            
        p=p->next;
    }
    return 1;
}

void removeDuplicate(Node *p) {
    Node *q;
    q = p->next;
    while(q) {
        if(p->data != q->data) {
            p = q;
            q=q->next;
        } else {
            p->next = q->next;
            delete q;
            q=p->next;
        }
    }
}

void reverse1(Node *p) {
    int index = count(p);
    int *arr,i=0;
    arr = new int[index];
    for(;i<index;i++) {
        arr[i] = p->data;
        p = p->next;
    }
    p = first;
    i--;
    for(;i>-1;i--) {
        p->data = arr[i];
        p=p->next;
    }
    delete [] arr;
}

// reverse links with sliding method
// very recomended to use for reverse a linked list
void reverse2 (Node *p) {
    Node *r=NULL, *q=NULL;
    
    while(p) {
        r = q;
        q = p;
        p=p->next;
        q->next = r;
    }
    first=q;
    
}

// reverse with recursive function
void reverse3(Node *q, Node *p) {
    if(p) {
        reverse3(p, p->next);
        p->next = q;
    } else first = q;
}

void concat (Node *p, Node *q){
    third = p;
    while(p->next!=NULL)
        p=p->next;
    p->next = q;
}

void merge2 (Node *p, Node *q) {
    Node *last=NULL;
    if(p->data < q->data) {
        third=last=p;
        p=p->next;
        last->next=NULL;
    } else {
        third=last=q;
        q=q->next;
        last->next=NULL;
    }
    
    while(p&&q) {
        if(p->data < q->data) {
            last->next = p;
            last = p;
            p=p->next;
            last->next=NULL;
        } else {
            last->next = q;
            last = q;
            q=q->next;
            last->next=NULL;
        }
    }
    
    if(p) last->next = p;
    else last->next = q;
    
}

int isloop(Node *p) {
    Node *q = p;
    
    do {
        p=p->next;
        q=q->next;
        q = q ? q->next : q;
    } while (p&&q && p!=q);
    return p == q ? 1 : 0;
}


/*
        CIRCULAR SECTION!!!
*/
void circularCreate(int A[], int n) {
    Node *t, *last;
    head = new Node;
    head->data = A[0];
    head->next = head;
    last = head;
    
    for(int i=1;i<n;i++){
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
    
}

void circularDisplay(Node *h) {
    do {
        cout<<h->data<<" ";
        h=h->next;
    } while(h!=head);
    cout<<endl;
}

void RcircularDisplay(Node *h) {
    static int flag = 0;
    if(h!=head || !flag) {
        flag = 1;
        cout<<h->data<<" ";
        RcircularDisplay(h->next);
    }
    cout<<endl;
}

int circularLength(Node *p) {
    int len = 0;
    do {
        len++;
        p=p->next;
    } while(p!=head);
    return len;
}

void circularInsert(Node *p, int index, int x) {
    Node *t;
    if(index < 0 || index > circularLength(p)){
        return;
    }
    if(index==0) {
        t = new Node;
        t->data = x;
        if(head==NULL){
            t = head;
            head->next = head;
        } else {
            while(p->next!=head) p=p->next;
            p->next = t;
            t->next = head;
            head = t;
        }
    } else {
        for(int i=0;i<index-1;i++) p=p->next;
        t = new Node;
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

int circularDelete(Node *p, int index) {
    Node *q;
    int x, i;
    if(index < 0 || index > circularLength(p))
        return -1;
    if(index==1){
        while(p->next!=head) p=p->next;
        x = head->data;
        if(p==head){
            delete head;
            head = NULL;
        } else {
            p->next = head->next;
            delete head;
            head=p->next;
        }
    } else {
        for(i=0;i<index-2;i++) {
            p=p->next;
        }
        q = p->next;
        p->next = q->next;
        x = q->data;
        delete q;
    }
    return x;
}



//int main() {
//    int A[] = {2,3,4,5,6};
//    circularCreate(A, 5);
//    
//    circularInsert(head, 5, 9);
//    circularDisplay(head);
//
//    return 0;
//}


