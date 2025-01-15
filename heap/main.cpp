#include<stdio.h>
#include"c++.h"
using namespace std;


void Insert(int A[], int index)
{
    int i = index;
    int temp = A[i];
    
    while(i>1 && temp>A[i/2]) {
        A[i] = A[i/2];
        i = i/2;
    }
    A[i] = temp;
}

int Delete(int A[], int n) {
    int i,j,x, temp, val;
    val = A[1];
    x = A[n];
    A[1] = A[n];
    A[n] = val;
    i=1;j=i*2;
    
    while(j<n-1) {
        if(A[j+1]>A[j])
            j=j+1;
        if(A[i]<A[j]) {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = j*2;
        }
        else
            break;
    }
    return val;
}

int main() {
    int A[] = {0,10,20,30,25,5,40,35};
    
    Heap obj(A);
    obj.Sorted(7);
    obj.Display(7);
    
    return 0;
}
