#include <iostream>
using namespace std;

class Queue {
private:
    int size;
    int front;
    int rear;
    int *Q;
public:
    Queue(int size);
    ~Queue();

    void Display();
    void Enqueue(int x);
    int Dequeue();

};

Queue:: Queue(int size) {
    this->size = size;
    front=rear=0;
    Q = new int[this->size];
}

Queue:: ~Queue () {
    delete []Q;
}

void Queue:: Display() {
    int i=(front+1)%size;
    do {
        cout<<Q[i]<<" ";
        i=(i+1)%size;
    } while(i!=Q[(rear+1)%size]);
    cout<<endl;
}

void Queue:: Enqueue(int x) {
    if((rear+1)%size==front)
        cout<<"Queue is full"<<endl;
    else {
        rear = (rear+1)%size;
        Q[rear] = x;
    }
}

int Queue:: Dequeue() {
    int x=-1;

    if(front==rear)
        cout<<"Queue is empty"<<endl;
    else {
        front=(front+1)%size;
        x = Q[front];
    }
    return x;
}

int main() {
    Queue q(6);

    q.Enqueue(12);
    q.Enqueue(17);
    q.Enqueue(25);
    q.Enqueue(22);
    q.Enqueue(22);
    

    q.Display();

    return 0;
}
