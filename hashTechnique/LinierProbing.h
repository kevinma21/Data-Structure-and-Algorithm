//
//  LinierProbing.h
//  Hash Technique
//
//  Created by kevin pratama on 20/02/23.
//

#include<iostream>
#ifndef LinierProbing_h
#define LinierProbing_h
#define SIZE 10
using namespace std;


class Probing {
private:
    int HT[10] = {0};
public:
    void Insert(int x);
    int Hash(int key);
    int Probe(int x);
    int Search(int x);
};

int Probing:: Hash(int key) {
    return key % SIZE;
}

int Probing:: Probe(int x){
    int index = Hash(x);
    int i=0;
    while(HT[index+i]%SIZE!=0)
        i++;
    return (index+i)%SIZE;
}

void Probing:: Insert (int x) {
    int index = Hash(x);
    if(HT[index]!=0)
        index=Probe(x);
    HT[index] = x;

}

int Probing:: Search(int x) {
    int index = Hash(x);
    int i=0;
    while(HT[(index+i)%SIZE]!=x&& HT[(index+i)%10]!=0)
        i++;
    if(HT[(index+i)%SIZE]==x)
        return (index+i)%SIZE;
    else
        return -1;
}


#endif /* LinierProbing_h */
