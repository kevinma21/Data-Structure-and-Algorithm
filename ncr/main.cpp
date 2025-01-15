//
//  main.cpp
//  ncr
//
//  Created by kevin pratama on 04/12/22.
//

#include <iostream>
using namespace std;

int fac(int n){
    if(n==0)
        return 1;
    return fac(n - 1) * n;
}

int nCr(int n, int r){
    return fac(n)/ (fac(r)*fac(n-1));
}

int NCR(int n, int r){
    if(n==r || r==0) return 1;
    else return NCR(n-1, r-1) + NCR(n-1, r);
}

int main() {
    // insert code here...
    cout<<NCR(4,2)<<endl;
    cout<<endl;
    return 0;
}


