//
//  main.cpp
//  test
//
//  Created by kevin pratama on 03/12/22.
//

#include <iostream>
using namespace std;

void fib1(int n){
    int arr[n];
    arr[0] = 0;
    arr[1] = 1;
    for(int i=2; i<=n; i++)
        arr[i] = arr[i-2] + arr[i-1];
    for(int i=0; i<=n; i++)
        cout<<arr[i]<<" ";
}

void fib2(int n){
    int a=0,b=1,s=0,i;
    for(i=2; i<=n; i++){
        s = a + b;
        a = b;
        b = s;
    }
    cout<<s<<endl;
}

int fib3(int n){
    if(n<=1) return n;
    else return fib3(n-1) + fib3(n-2);
}

int arr[10];

int fib4(int n){
    if(n<=1){
        if(arr[n] == -1)
            arr[n] = n;
        return arr[n];
    } else {
        if(arr[n-1] == -1)
            arr[n-1] = fib4(n-1);
        if(arr[n-2] == -1)
            arr[n-2] = fib4(n-2);
        arr[n] = arr[n-1] + arr[n-2];
        return arr[n];
    }
}

int main() {
    
    for(int i=0;i<10;i++){
        arr[i] = -1;
    }
    int r = fib4(6);
    cout<<r<<endl;
    
    return 0;
}
