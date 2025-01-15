#include <iostream>
#include<string.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
};

class Stack {
private:
    Node *top;
public:
    Stack() { top = NULL; };
    ~Stack() {
        Node *p = top;
        while(p) {
            top=top->next;
            delete p;
            p = top;
        }
    }
    
    void Push(int x);
    void Display();
    int Pop();
    int IsEmpty();
    int StackTop();
    
    
};

void Stack:: Push(int x) {
    Node *t;
    t = new Node;
    
    if(t==NULL) cout<<"stack is full"<<endl;
    else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Stack:: Pop() {
    int x=-1;
    Node *p = top;
    
    if(top==NULL) cout<<"Node is empty"<<endl;
    else {
        top=top->next;
        x = p->data;
        delete p;
    }
    return x;
}

void Stack:: Display() {
    Node *p = top;
    while(p) {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int Stack:: IsEmpty() {
    return !top ? 1 : 0;
}

int Stack:: StackTop() {
    return IsEmpty() ? -1 : top->data;
}

/*
 INFIX TO POSTFIX
 */
int Precedence(char x) {
    if(x=='+' || x=='-')
        return 1;
    else if(x=='*' || x=='/')
        return 2;
    return 0;
}
int IsOperand(char x) {
    if(x=='+' || x=='-' || x=='*' || x=='/' || x=='(' || x==')' || x=='^')
        return 0;
    else
        return 1;
}
char *IntoPostfix(char *infix) {
    int i=0,j=0;
    Stack s;
    char *postfix;
    postfix = new char[strlen(infix)+1];
    
    while(infix[i]!='\0') {
        if(IsOperand(infix[i]))
            postfix[j++] = infix[i++];
        else {
            if(Precedence(infix[i]) > Precedence(s.StackTop()))
                s.Push(infix[i++]);
            else
                postfix[j++] = s.Pop();
        }
    }
    
    while(!s.IsEmpty())
        postfix[j++] = s.Pop();
    postfix[j] = '\0';
    
    return postfix;
}

/* INFIX TO PoSTFIX WITH ASSOCIATIVITY AND PARENTHESIS */

int OutPre(char x) {
    if(x=='+' || x=='-')
        return 1;
    else if(x=='*' || x=='/')
        return 3;
    else if(x=='^')
        return 6;
    else if(x=='(')
        return 7;
    else if(x==')')
        return 0;
    return -1;
}

int InPre(char x) {
    if(x=='+' || x=='-')
        return 2;
    else if(x=='*' || x=='/')
        return 4;
    else if(x=='^')
        return 5;
    else if(x=='(')
        return 0;
    return -1;
}

char * IntoPostfix2(char *infix) {
    Stack s;
    int i=0,j=0;
    char *postfix;
    long len = strlen(infix)+1;
    postfix = new char[len];
    
    while(infix[i]!='\0') {
        if(IsOperand(infix[i]))
            postfix[j++] = infix[i++];
        else {
            if(s.StackTop()==-1 || OutPre(infix[i]) > InPre(s.StackTop()))
                s.Push(infix[i++]);
            else {
                postfix[j++] = s.Pop();
                i++;
            }
        }
    }
    
    while(!s.IsEmpty()) {
        if(s.StackTop() == '(')
            s.Pop();
        else
            postfix[j++] = s.Pop();
    }
    postfix[j] = '\0';
    
    return postfix;
}

int Eval(char *postfix) {
    Stack s;
    int i,x1,x2,r=0;
    for(i=0;postfix[i]!='\0';i++) {
        if(IsOperand(postfix[i]))
            s.Push(postfix[i]-'0');
        else {
            x2=s.Pop();
            x1=s.Pop();
            switch(postfix[i]) {
                case '+': r = x1+x2; break;
                case '-': r = x1-x2; break;
                case '*': r = x1*x2; break;
                case '/': r = x1/x2; break;
            }
            s.Push(r);
        }
    }
    
    return s.StackTop();
}

int main() {
    Stack s;
    
    char postfix[] = "234*+82/-";
    cout<<"result: " <<Eval(postfix)<<endl;
    
    return 0;
}
