//
//  main.cpp
//  matrices
//
//  Created by kevin pratama on 29/12/22.
//

#include<iostream>
using namespace std;

class Diagonal {
private:
    int *arr;
    int n;
public:
//    constructor
    Diagonal() {
        n = 2;
        arr = new int[n];
    }
    Diagonal(int n) {
        this->n = n;
        arr = new int[this->n];
    }
//    distructor
    ~Diagonal() {
        delete []arr;
    }
    
//set up an element
    void Set(int i, int j, int x) {
        if(i==j) arr[i-1] = x;
    }
//get an element in array
    int Get(int i, int j) {
        if(i==j) return arr[i-1];
        return 0;
    }
//display entire element
    void Display() {
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) cout<<arr[i]<<" ";
                else cout<<0<<" ";
            }
            cout<<endl;
        }
    }
    
};

class LowTriangle {
private:
    int *arr;
    int n;
public:
    LowTriangle() {
        n = 2;
        arr = new int[n*(n-1)/2+ n-1];
    }
    LowTriangle(int n) {
        this->n = n;
        arr = new int[this->n*(this->n-1)/2];
    }
    ~LowTriangle() {
        delete []arr;
    }
    
    void Set(int i, int j, int x) {
        if(i>=j) arr[i*(i-1)/2+j-1] = x;
    }
    
    int Get(int i, int j) {
        if(i>=j) return arr[i*(i-1)/2+j-1];
        return 0;
    }
    
    int GetDimensions() {return n;}
    
    void Display() {
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i>=j) cout<<arr[i*(i-1)/2+j-1]<<" ";
                else cout<<0<<" ";
            }
            cout<<endl;
        }
    }
};

class UpperTriangle {
private:
    int *arr;
    int n;
public:
    UpperTriangle () {
        n = 2;
        arr = new int[n*(n+1)/2];
    }
    UpperTriangle (int n) {
        this->n = n;
        arr = new int[this->n*(this->n+1)/2];
    }
    ~UpperTriangle (){
        delete []arr;
    }
    
    void Set(int i, int j, int x) {
        if(i<=j)
            arr[n*(i-1)-((i-1)*(i-2)/2)]=x;
    }
    
    int Get(int i, int j){
        if(i <= j) return arr[n*(i-1)-((i-2)*(i-1)/2)+(j-i)];
        return 0;
    }
    
    void Display(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i<=j) cout<<arr[n*(i-1)-((i-2)*(i-1)/2)+(j-i)]<<" ";
                else cout<<0<<" ";
            }
            cout<<endl;
        }
    }
    
};

class symmetric {
private:
    int *arr;
    int n;
public:
    symmetric() {
        n = 2;
        arr = new int[n*(n-1)/2+ n-1];
    }
    symmetric(int n) {
        this->n = n;
        arr = new int[this->n*(this->n-1)/2];
    }
    ~symmetric() {
        delete []arr;
    }
    
    void Set(int i, int j, int x) {
        if(i>=j) arr[i*(i-1)/2+j-1] = x;
    }
    
    int Get(int i, int j) {
        if(i>=j) return arr[i*(i-1)/2+j-1];
        else return arr[j*(j-1)/2+i-1];
    }
    
    int GetDimensions() {return n;}
    
    void Display() {
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i>=j) cout<<arr[i*(i-1)/2+j-1]<<" ";
                else cout<<arr[j*(j-1)/2+i-1]<<" ";
            }
            cout<<endl;
        }
    }
    
};

class TriDiagonal {
private:
    int *arr;
    int n;
public:
    TriDiagonal (int n){
        this->n = n;
        arr = new int[3 * this->n - 2];
    }
    ~TriDiagonal () {
        delete []arr;
    }
    void Set(int i, int j, int x) {
        if((i-j) == 1) arr[i - 1]=x;
        else if((i-j)== 0) arr[n-1 + i-1]=x;
        else if((i-j) == -1) arr[n-1 * n + i-1]=x;
    }
    
    void Display () {
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if((i-j) == 1) cout<<arr[i - 1]<<" ";
                else if((i-j)== 0) cout<<arr[n-1 + i-1]<<" ";
                else if((i-j) == -1) cout<<arr[n-1 * n + i-1]<<" ";
                else cout<<0<<" ";
            }
            cout<<endl;
        }
    }
    
};

class Toepliz {
private:
    int *arr;
    int n;
public:
    Toepliz (int n) {
        this->n = n;
        arr = new int[n+n-1];
    }
    ~Toepliz() {
        delete []arr;
    }
    
    void Set (int i, int j, int x) {
        if(i<=j) arr[j-i]=x;
        else if(i>j) arr[n+i-j-1]=x;
    }
    
    void Display (){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i<=j) cout<<arr[j-i]<<" ";
                else if(i>j) cout<<arr[n+i-j-1]<<" ";
            }
            cout<<endl;
        }
    }

};

int main() {
    int d; cout<<"Enter Demensions: "; cin>>d;
    Toepliz m(d);
    
    int i,j,x;
    cout<<"Enter all elements: "<<endl;
    for(i=1;i<=d;i++){
        for(j=1;j<=d;j++){
            cin>>x;
            m.Set(i, j, x);
        }
    }
    cout<<endl;
    m.Display();
    cout<<endl;
    
    return 0;
}



