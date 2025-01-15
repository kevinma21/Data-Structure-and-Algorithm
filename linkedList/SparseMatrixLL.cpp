#include<iostream>
using namespace std;

class Node {
public:
    int col;
    int val;
    Node *next;
};

class Sparse {
private:
    int row;
    int col;
    Node **a;
public:
    Sparse (int row, int col);
    void Display();
};

Sparse:: Sparse (int row, int col) {
    int x;
    Node *t, *last=NULL;
    this->row = row;
    this->col = col;
    a = new Node *[this->row];
    
    for(int i=0;i<this->row;i++) a[i] = NULL;
    
    for(int i=0;i<this->row;i++) {
        for(int j=0;j<this->col;j++) {
            cout<<"Enter the Element at row:"<<i<<" and column:"<<j<<endl;
            cout<<"Element: "; cin>>x;
            if(x!=0) {
                if(!a[i]) {
                    t = new Node;
                    t->col = j;
                    t->val = x;
                    t->next = NULL;
                    a[i] = t;
                    last = t;
                } else {
                    t = new Node;
                    t->col = j;
                    t->val = x;
                    t->next = NULL;
                    last->next = t;
                    last = t;
                }
            }
        }
        cout<<endl;
    }
}

void Sparse:: Display() {
    Node *p;
    for(int i=0;i<this->row;i++) {
        p = a[i];
        for(int j=0;j<this->col;j++) {
            if(p && p->col==j) {
                cout<< p->val << " ";
                p=p->next;
            } else cout<< 0<< " ";
        }
        cout<<endl;
    }
}


//int main() {
//
//    Sparse LL(3,3);
//    LL.Display();
//
//
//}
