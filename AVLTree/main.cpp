#include<iostream>
using namespace std;

class Node {
public:
    Node *lchild;
    int data;
    int height;
    Node *rchild;
};

class AVL {
public:
    Node *root;
    AVL (){root = NULL;}
    
    Node * InPre(Node *p);
    Node * InSucc(Node *p);
    
    int NodeHeight(Node *p);
    int BalenceFactor(Node *p);
    Node * LLRotation(Node *p);
    Node * RRRotation(Node *p);
    Node * LRRotation(Node *p);
    Node * RLRotation(Node *p);
    Node * Insert(Node *p, int key);
    Node * Delete(Node *p, int key);
    
};

Node * AVL:: InPre(Node *p) {
    while(p && p->rchild) {
        p=p->rchild;
    }
    return p;
}

Node * AVL:: InSucc(Node *p) {
    while(p && p->lchild) {
        p=p->lchild;
    }
    return p;
}

int AVL:: NodeHeight(Node *p) {
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;
    
    return hl>hr ? hl+1 : hr+1;
}

int AVL:: BalenceFactor(Node *p) {
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0 ;
    hr = p && p->rchild ? p->rchild->height : 0 ;
    
    return hl - hr;
}

Node *AVL:: LLRotation(Node *p) {
    Node *pl = p->lchild;
    Node *plr = pl->rchild;
    
    pl->rchild = p;
    p->lchild = plr;
    
    p->height = NodeHeight(p);
    pl->height =  NodeHeight(pl);
    
    if(root==p)
        root=pl;
    return pl;
}

Node *AVL:: LRRotation(Node *p){
    Node *pl = p->lchild;
    Node *plr = pl->rchild;
    
    pl->rchild = p->lchild;
    p->rchild = plr->rchild;
    
    plr->lchild = pl;
    plr->rchild = p;
    
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    plr->height = NodeHeight(plr);
    
    if(root==p)
        root=plr;
    return plr;
}

Node *AVL:: RRRotation(Node *p) {
    Node *pr = p->rchild;
    Node *prl = pr->lchild;
    
    pr->lchild = p;
    p->lchild = prl;
    
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    
    if(root==p)
        root=pr;
    return pr;
}

Node *AVL:: RLRotation(Node *p) {
    Node *pr = p->rchild;
    Node *prl = pr->lchild;
    
    pr->lchild = p->rchild;
    p->lchild = prl->lchild;
    
    prl->rchild = pr;
    prl->lchild = p;
    
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    prl->height = NodeHeight(prl);
    
    if(root==p)
        root=prl;
    return prl;
    
    
    return NULL;
}

Node *AVL:: Insert(Node *p, int key) {
    Node *t=NULL;
    
    if(p==NULL) {
        t = new Node;
        t->data = key;
        t->height = 1;
        t->lchild=t->rchild=NULL;
        return t;
    }
    
    if(key<p->data)
        p->lchild = Insert(p->lchild, key);
    else if(key>p->data)
        p->rchild = Insert(p->rchild, key);
    
    p->height = NodeHeight(p);
    
    if(BalenceFactor(p)==2 && BalenceFactor(p->lchild)==1)
        return LLRotation(p);
    else if(BalenceFactor(p)==2 && BalenceFactor(p->lchild)==-1)
        return LRRotation(p);
    else if(BalenceFactor(p)==-2 && BalenceFactor(p->rchild)==-1)
        return RRRotation(p);
    else if(BalenceFactor(p)==-2 && BalenceFactor(p->rchild)==1)
        return RLRotation(p);
    
    return p;
}

Node * AVL:: Delete(Node *p, int key) {
    if(p==NULL) return NULL;
    if(p->lchild==NULL && p->rchild==NULL) {
        if(p==root)root=NULL;
        delete p;
        return NULL;
    }
    
    if(key < p->data)
        p->lchild = Delete(p->lchild, key);
    else if(key > p->data)
        p->rchild = Delete(p->rchild, key);
    else if(key==p->data){
        Node *q;
        if(NodeHeight(p->lchild) > NodeHeight(p->rchild)) {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        } else {
            q =InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    
    p->height = NodeHeight(p);
    
    if(BalenceFactor(p)==2 && BalenceFactor(p->lchild)==1)
        return LLRotation(p);
    else if(BalenceFactor(p)==2 && BalenceFactor(p->lchild)==-1)
        return LRRotation(p);
    else if(BalenceFactor(p)==-2 && BalenceFactor(p->rchild)==-1)
        return RRRotation(p);
    else if(BalenceFactor(p)==-2 && BalenceFactor(p->rchild)==1)
        return RLRotation(p);
    
    return p;
}


int main() {
    AVL tree;
    
    Node *temp;
    
    tree.root = tree.Insert(tree.root, 10);
    tree.Insert(tree.root, 20);
    tree.Insert(tree.root, 15);
    
    
    temp = tree.Delete(tree.root, 15);
    
    return 0;
}
