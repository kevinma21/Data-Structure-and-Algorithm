#include<iostream>
#include"Queue.h"
#include"Stack.h"
using namespace std;

class Tree {
public:
    Node *root;
    Tree() {root=NULL;}
    void CreateTree();
    void PreOrder(Node *p);
    void InOrder(Node *p);
    void PostOrder(Node *p);
    void LevelOrder();
    int Height(Node *root);
    int Count(Node *root);
    int LeafCount(Node *root);
    int Deg1Count(Node *root);
    int Deg2Count(Node *root);

    void IPreOrder(); // preorder with iterativ procedure
    void ItInreOrder(); // innorder with iterativ procedure
    
    int SearchInorder(int ArrOrder[], int inStart, int inEnd, int data);
    Node *GenereteFromTravelsal(int inOrder[], int preOrder[], int inStart, int inEnd);
};

void Tree:: CreateTree() {
    Node *p, *t;
    int x;
    Queue q(100);
    
    cout<<"Enter root value: "; cin>>x;
    root = new Node;
    root->data = x;
    root->lchild=root->rchild=NULL;
    q.Enqueue(root);
    
    while(!q.IsEmpety()) {
        p = q.Dequeue();
        cout<<"Enter left child of "<<p->data<<": "; cin>>x;
        if(x!=-1) {
            t = new Node;
            t->data = x;
            t->lchild=t->rchild=NULL;
            p->lchild = t;
            q.Enqueue(t);
        }
        
        cout<<"Enter right child of "<<p->data<<": "; cin>>x;
        if(x!=-1) {
            t = new Node;
            t->data = x;
            t->lchild=t->rchild=NULL;
            p->rchild = t;
            q.Enqueue(t);
        }
        
    }
}

void Tree:: PreOrder(Node *p) {
    if(p) {
        cout<<p->data<<" ";
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}

void Tree:: InOrder(Node *p) {
    if(p) {
        InOrder(p->lchild);
        cout<<p->data<<" ";
        InOrder(p->rchild);
    }
}

void Tree:: PostOrder(Node *p) {
    if(p) {
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        cout<<p->data<<" ";
    }
}

void Tree:: LevelOrder() {
    Node *p=root;
    Queue q(100);
    
    cout<<p->data<<" ";
    q.Enqueue(p);
    
    while(!q.IsEmpety()) {
        p = q.Dequeue();
        if(p->lchild){
            cout<<p->lchild->data<<" ";
            q.Enqueue(p->lchild);
        }
        if(p->rchild){
            cout<<p->rchild->data<<" ";
            q.Enqueue(p->rchild);
        }
    }
}

void Tree:: IPreOrder() {
    Node *p = root;
    Stack stk(100);
    
    while(p || !stk.IsEmpty()) {
        if(p) {
            cout<<p->data<<" ";
            stk.Push(p);
            p=p->lchild;
        } else {
            p =stk.Pop();
            p=p->rchild;
        }
    }
}

void Tree:: ItInreOrder() {
    Node *p = root;
    Stack stk(100);
    
    while(p || !stk.IsEmpty()) {
        if(p) {
            stk.Push(p);
            p=p->lchild;
        } else {
            p =stk.Pop();
            cout<<p->data<<" ";
            p=p->rchild;
        }
    }
}

int Tree:: SearchInorder(int *ArrinOrder, int inStart, int inEnd, int data) {
    for(int i=inStart;i<inEnd;i++) {
        if(ArrinOrder[i]==data)
            return i;
    }
    return -1;
}

Node *Tree:: GenereteFromTravelsal(int *inOrder, int *preOrder, int inStart, int inEnd) {
    static int preIndex = 0;
    if(inStart>inEnd)
        return NULL;
    
    Node *node = new Node;
    node->data = preOrder[preIndex++];
    
    if(inStart==inEnd)
        return node;
    
    int splitIndex = SearchInorder(inOrder, inStart, inEnd, node->data); // for search index of root
    node->lchild = GenereteFromTravelsal(inOrder, preOrder, inStart, splitIndex-1);
    node->rchild = GenereteFromTravelsal(inOrder, preOrder, splitIndex+1, inEnd);
    
    return node;
}

int Tree::Height(Node *p) {
    int l = 0;
    int r = 0;
    if (p == nullptr){
        return 0;
    }
 
    l = Height(p->lchild);
    r = Height(p->rchild);
 
    if (l > r){
        return l + 1;
    } else {
        return r + 1;
    }
}

int Tree:: Count(Node *root) {
    if(root)
        return Count(root->lchild) + Count(root->rchild) + 1;
    return 0;
}

int Tree:: LeafCount(Node *root) {
    int x, y;
    if(root) {
        x = LeafCount(root->lchild);
        y = LeafCount(root->rchild);
        if(!root->lchild && !root->rchild) {
            return x + y + 1;
        } else
            return x + y;
    }
        
    return 0;
}

int Tree:: Deg1Count(Node *root) {
    int x, y;
    if(root) {
        x =  Deg1Count(root->lchild);
        y = Deg1Count(root->rchild);
        if(root->lchild!=NULL ^ root->rchild!=NULL) {
            return x + y + 1;
        } else
            return x + y;
    }
    return 0;
}

int Tree:: Deg2Count(Node *root) {
    int x, y;
    if(root) {
        x = Deg2Count(root->lchild);
        y = Deg2Count(root->rchild);
        if(root->lchild!=NULL && root->rchild!=NULL) {
            return x + y + 1;
        } else
            return x + y;
    }
    
    return 0;
}

int main() {
    Tree t;
    
    t.CreateTree();
    
    int preorder[] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
    int inorder[]  = {7, 6, 9, 3, 4, 5, 8, 2, 1};

    Node *T = t.GenereteFromTravelsal(inorder, preorder, 0, sizeof(inorder)/sizeof(inorder[0])-1);
    t.PreOrder(T);
    
    
    return 0;
}
