#include<iostream>
#include"Chains.h"
#include"LinierProbing.h"
using namespace std;

int main() {
    
    Probing obj;
    
    obj.Insert(12);
    obj.Insert(25);
    obj.Insert(35);
    obj.Insert(26);
    
    cout<<"key was found in index "<<obj.Search(35)<<endl;
    
    return 0;
}
