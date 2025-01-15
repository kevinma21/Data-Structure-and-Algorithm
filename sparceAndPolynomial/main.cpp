//#include <iostream>
//using namespace std;
//
//class Element {
//public:
//    int i;
//    int j;
//    int x;
//};
//
//class Sparse {
//private:
//    int n;
//    int m;
//    int num;
//    Element *el;
//public:
//    Sparse (int n, int m, int num) {
//        this->n = n;
//        this->m = m ;
//        this->num = num;
//        el = new Element[this->num];
//    }
//
//    ~Sparse () {
//        delete [] el;
//    }
//
//    Sparse operator+(Sparse &s);
//    Sparse operator-(Sparse &s);
//
//    friend istream & operator>>(istream &is,Sparse &s);
//    friend ostream & operator<<(ostream &os,Sparse &s);
//
//};
//
//Sparse Sparse::operator+(Sparse &s) {
//    int i,j,k;
//    if(n!=s.n || m!=s.m)
//        return Sparse(0,0,0);
//    Sparse *sum = new Sparse(n, m, num+s.num);
//
//    i=j=k=0;
//    while(i<num && j<s.num) {
//        if(el[i].i > s.el[j].i)
//            sum->el[k++] = s.el[j++];
//        else if(el[i].i < s.el[j].i)
//            sum->el[k++] = el[i++];
//        else {
//            if(el[i].j > s.el[j].j)
//                sum->el[k++] = s.el[j++];
//            else if(el[i].j < s.el[j].j)
//                sum->el[k++] = el[i++];
//            else {
//                sum->el[k] = el[i];
//                sum->el[k++].x = el[i++].x + s.el[j++].x;
//            }
//        }
//    }
//    for(;i<num;i++) sum->el[k++]= el[i];
//    for(;j<s.num;j++) sum->el[k++]= s.el[j];
//    sum->num = k;
//
//    return *sum;
//}
//
//Sparse Sparse::operator-(Sparse &s) {
//    int i,j,k;
//    if(n!=s.n || m!=s.m)
//        return Sparse(0,0,0);
//    Sparse *sum = new Sparse(n, m, num+s.num);
//
//    i=j=k=0;
//    while(i<num && j<s.num) {
//        if(el[i].i > s.el[j].i)
//            sum->el[k++] = s.el[j++];
//        else if(el[i].i < s.el[j].i)
//            sum->el[k++] = el[i++];
//        else {
//            if(el[i].j > s.el[j].j)
//                sum->el[k++] = s.el[j++];
//            else if(el[i].j < s.el[j].j)
//                sum->el[k++] = el[i++];
//            else {
//                sum->el[k] = el[i];
//                sum->el[k++].x = el[i++].x - s.el[j++].x;
//            }
//        }
//    }
//    for(;i<num;i++) sum->el[k++]= el[i];
//    for(;j<s.num;j++) sum->el[k++]= s.el[j];
//    sum->num = k;
//
//    return *sum;
//
//
//}
//
//istream & operator>>(istream &is, Sparse &s) {
//    cout<<"Enter all elements: "<<endl;
//    for(int i=0;i<s.num;i++)
//        cin>>s.el[i].i>>s.el[i].j>>s.el[i].x;
//    cout<<endl;
//    return is;
//}
//
//ostream & operator<<(ostream &os,Sparse &s) {
//    int k=0;
//    for(int i=0;i<s.n;i++){
//        for(int j=0;j<s.m;j++){
//            if(s.el[k].i==i && s.el[k].j==j)
//                cout<<s.el[k++].x<<" ";
//            else
//                cout<<0<<" ";
//        }
//        cout<<endl;
//    }
//    cout<<endl;
//    return os;
//}
//
//
//int main() {
//    Sparse s1(5,5,5);
//    Sparse s2(5,5,5);
//
//    cin>>s1;
//    cin>>s2;
//
//    Sparse s = s1 - s2;
//
//    cout<<"First Matrix"<<endl<<s1;
//    cout<<"Second Matxrix"<<endl<<s2;
//    cout<<"min"<<endl<<s;
//
//    return 0;
//}

//Polynomial

#include<iostream>
using namespace std;

class Term {
public:
    int coef;
    int exp;
};

class Polynomial {
private:
    int n;
    Term *pol;
public:
    Polynomial(){}
    Polynomial(int n) {
        this->n=n;
        pol = new Term[this->n];
    }
    ~Polynomial () {
        delete []pol;
    }
    
    void create () {
        cout<<"Enter Terms"<<endl;
        for(int i=0;i<n;i++) {
            cin>>pol[i].coef>>pol[i].exp;
        }
    }
    void display () {
        for(int i=0;i<n;i++)
            cout<<pol[i].coef<<"x"<<pol[i].exp<<"+";
        cout<<endl;
    }
    
    Polynomial *add(Polynomial &p) {
        int i,j,k;
        Polynomial *sum = new Polynomial(n+p.n);
        
        i=j=k=0;
        while(i<n && j<p.n) {
            if(pol[i].exp > p.pol[j].exp)
                sum->pol[k++] = pol[i++];
            else if(pol[i].exp < p.pol[j].exp)
                sum->pol[k++] = p.pol[j++];
            else{
                sum->pol[k].exp= pol[i].exp;
                sum->pol[k++].coef = pol[i++].coef + p.pol[j++].coef;
            }
        }
        for(;i<n;i++) sum->pol[k++] = pol[i];
        for(;j<p.n;j++) sum->pol[k++] = p.pol[j];
        sum->n = k;
        
        return sum;
    }
    
};

int main() {
    int n; cout<<"Enter Numbers of Terms: "; cin>>n;
    
    Polynomial p1(n);
    Polynomial p2(n);
    Polynomial *p3;
    
    p1.create();
    cout<<endl;
    p2.create();
    cout<<endl;
    cout<<"p1"<<endl;
    p1.display();
    cout<<endl;
    cout<<"p2"<<endl;
    p2.display();
    cout<<endl;
    
    p3 = p1.add(p2);
    cout<<"sum"<<endl;
    p3->display();
    
    
    
    return 0;
}
