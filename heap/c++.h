//
//  c++.h
//  Heap
//
//  Created by kevin pratama on 12/02/23.
//

#include<iostream>
#ifndef c___h
#define c___h

using namespace std;

class Heap {
private:
    int *arr;
    void Swap(int *x, int *y);
public:
    Heap(int A[]);
    
    void Display(int n);
    void Insert(int n);
    int Delete(int n);
    void Sorted(int n);
};

Heap:: Heap(int A[]) {
    arr = new int;
    arr = A;
}

void Heap:: Display(int n) {
    for(int i=1;i<=n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void Heap:: Insert(int n) {
    int i = n;
    int temp = arr[i];
    
    while(i>1 && temp>arr[i/2]) {
        arr[i] = arr[i/2];
        i = i/2;
    }
    arr[i] = temp;
}

void Heap:: Swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// only root can be deleted
int Heap:: Delete(int n) {
    int i,j,x,val;
    val = arr[1];
    x = arr[n];
    arr[n] = val;
    arr[1] = x;
    i = 1; j = i * 2;
    
    while(j < n - 1) {
        if(arr[j+1] > arr[j])
            j = j + 1;
        if(arr[i] < arr[j]) {
            Swap(&arr[i], &arr[j]);
            i = j;
            j = j * 2;
        } else
            break;
    }
    
    return val;
}

void Heap:: Sorted(int n) {
    for(int i=1;i<=n;i++)
        Insert(i);
    
    for(int i=n;i>0;i--)
        Delete(i);
    
}

#endif /* c___h */
