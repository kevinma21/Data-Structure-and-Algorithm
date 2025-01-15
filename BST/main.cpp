#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
typedef struct simpulku *ptrsimpul;
typedef struct simpulku {

int data ;
ptrsimpul kanan;
ptrsimpul kiri;
}simpul;
typedef struct {
simpul *akar;
}pohon;

void buatpohonbaru (int dt, pohon *v) {
    simpul *simpulbaru;
    simpulbaru=new simpul;
    simpulbaru->data=dt;
    simpulbaru->kanan=NULL;
    simpulbaru->kiri=NULL;
    (*v).akar=simpulbaru;
    }

void tambahKanan (int dt,simpul **akar){
    if((*akar)->kanan==NULL){
    simpul *simpulbaru;
    simpulbaru=new simpul;
    simpulbaru->data=dt;
    simpulbaru->kanan=NULL;
    simpulbaru->kiri=NULL;
    (*akar)->kanan=simpulbaru;
    }

else{
cout<<"subpohon kanan telah terisi\n";
}
}
void tambahKiri (int dt,simpul **akar){
    if((*akar)->kiri==NULL) {
    simpul *simpulbaru;
    simpulbaru=new simpul;
    simpulbaru->data=dt;
    simpulbaru->kanan=NULL;
    simpulbaru->kiri=NULL;
    (*akar)->kiri=simpulbaru;
    }
else {
cout<<"Subpohon kiri telah terisi\n";
}
}
void kunjunganPreorder(simpul *akar){
    if(akar!=NULL){
    cout<<akar->data<<" ";
    kunjunganPreorder (akar->kiri);
    kunjunganPreorder (akar->kanan);
}
}
void kunjunganinorder(simpul *akar){
    if(akar!=NULL){
    kunjunganinorder (akar->kiri);
    cout<<akar->data<<" ";
    kunjunganinorder (akar->kanan);
}
}
void kunjunganpostorder(simpul *akar){
    if(akar!=NULL){
    kunjunganpostorder (akar->kiri);
    kunjunganpostorder (akar->kanan);
    cout<<akar->data<<" ";
    
}
}
main ()
{
pohon v;
printf("tStruktur Pohon: \n\n");
printf("           30\n\t       / \\\n\t      4   45 \n\t      \\    \\\n\t      34   55\n\t      /     \\\n         14     48\n\t     /\\     /\\\n        13 15 47 49 \n\n");
buatpohonbaru (30,&v);
tambahKiri (10,&v.akar);
tambahKanan (20,&v.akar->kiri);
tambahKiri (15,&v.akar->kiri->kanan);
tambahKanan(25,&v.akar->kiri->kanan);
tambahKanan (55,&v.akar);
tambahKiri (45,&v.akar->kanan);
tambahKanan(70,&(v.akar->kanan));

//tambahKiri(45,&(v.akar->kiri->kanan));
//tambahKanan(19,&(v.akar->kanan->kiri));


    cout<<"Kunjungan Preorder"<<endl;
    cout<<"=================="<<endl;
kunjunganPreorder(v.akar);
    cout<<endl;
    cout<<"Kunjungan Inorder"<<endl;
    cout<<"=================="<<endl;
    kunjunganinorder (v.akar);
    cout<<endl;
    cout<<"Kunjungan postorder"<<endl;
    cout<<"=================="<<endl;
    kunjunganpostorder (v.akar);
    cout<<endl;
    getch();
    }
