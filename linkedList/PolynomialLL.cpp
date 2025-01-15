#include<iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

class Node {
public:
    int coeff;
    int exp;
    Node *next;
};

class Polynomial {
private:
    int num;
    Node *poly = NULL;
public:
    Polynomial (int num);
    void Display();
    int Eval(int exp);
    
};

Polynomial:: Polynomial(int num) {
    Node *t, *last=NULL;
    this->num = num;
    
   
    for(int i=0;i<this->num;i++) {
        int coeff, exp;
        cout<<"Insert coefficient: "; cin>>coeff;
        cout<<"Insert exponen: "; cin>>exp;
        if(!poly){
            t = new Node;
            t->coeff = coeff;
            t->exp = exp;
            t->next = NULL;
            poly=last=t;
        } else {
            t = new Node;
            t->coeff = coeff;
            t->exp = exp;
            t->next = NULL;
            last->next = t;
            last = t;
        }
    }
}

void Polynomial:: Display() {
    Node *p = poly;
    while(p) {
        if(p->next){
            if(p->exp==0) {
                cout<< p->coeff <<"x"<<"+";
                p=p->next;
            } else {
                cout<< p->coeff <<"xˆ"<<p->exp<<"+";
                p=p->next;
            }
        } else {
            if(p->exp==0) {
                cout<< p->coeff <<"x";
                p=p->next;
            } else {
                cout<< p->coeff <<"xˆ"<<p->exp;
                p=p->next;
            }
        }
    }
    cout<<endl;
}



int Polynomial:: Eval(int num) {
    Node *p = poly;
    int sum = 0;
    while(p) {
        sum+=p->coeff*pow(num, p->exp);
        p=p->next;
    }
    return sum;
}


int main() {
    Polynomial LL(4);
    
    LL.Display();
    cout<<" Evaluation this Polynomial is: " << LL.Eval(1)<<endl;
    
}
