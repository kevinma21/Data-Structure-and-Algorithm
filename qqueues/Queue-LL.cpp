//#include<iostream>
//using namespace std;
//
//class Node {
//public:
//    int data;
//    Node *next;
//};
//
//class Queue {
//private:
//    Node *front;
//    Node *rear;
//public:
//    Queue() {front=NULL;rear=NULL;}
//    ~Queue();
//    
//    void Display();
//    void Enqueue (int x);
//    int Dequeue ();
//};
//
//Queue:: ~Queue () {
//    Node *p = front;
//    while(p) {
//        front=front->next;
//        delete p;
//        p = front;
//    }
//}
//
//void Queue:: Display() {
//    Node *p = front;
//    while(p) {
//        cout<<p->data<<" ";
//        p=p->next;
//    }
//    cout<<endl;
//}
//
//void Queue:: Enqueue(int x) {
//    Node *t ;
//    t = new Node;
//    t->data = x;
//    t->next = NULL;
//    if(t==NULL)
//        cout<<"Node is Full"<<endl;
//    else {
//        if(front==NULL) {
//            front=rear=t;
//        } else {
//            rear->next = t;
//            rear = t;
//        }
//    }
//}
//
//int Queue:: Dequeue() {
//    int x = -1;
//    Node *p = front;
//    if(front==NULL)
//        cout<<"Node is empty"<<endl;
//    else {
//        front=front->next;
//        x = p->data;
//        delete p;
//    }
//    return x;
//}
//
//
//
//int main() {
//    Queue q;
//    
//    q.Enqueue(10);
//    q.Enqueue(20);
//    q.Enqueue(30);
//    q.Enqueue(40);
//    q.Enqueue(50);
//    q.Enqueue(60);
//    
//    
//    q.Display();
//    
//    return 0;
//}
