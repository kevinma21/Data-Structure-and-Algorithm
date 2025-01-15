//
//  main.cpp
//  tower-of-hanoi
//
//  Created by kevin pratama on 06/12/22.
//

#include <iostream>
using namespace std;

void toh(int n, int a, int b, int c){
    if(n>0){
        toh(n-1,a,c,b);
        cout<<a<<"->"<<c<<endl;
        toh(n-1,b,a,c);
    }
}

void TOH(int n, int a, int b, int c){
    while(n--){
        a = a;

    }
}

int main() {
    // insert code here...
    toh(3,1,2,3);
    cout<<endl;
    return 0;
}

