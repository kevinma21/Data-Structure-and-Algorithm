//
//  main.cpp
//  array
//
//  Created by kevin pratama on 10/12/22.
//

#include <iostream>
using namespace std;

struct Array {
    int *A;
    int size;
    int length;
};

void Display(struct Array arr){
    for(int i=0;i<arr.length;i++)
        cout<<arr.A[i]<<" ";
    cout<<endl;
}

void Append(struct Array * arr, int x){
    if(arr->length < arr->size)
        arr->A[arr->length++] = x;
}

void Insert(struct Array *arr, int index, int x){
    if(arr->length >= 0 && index <= arr->length)
        for(int i=arr->length;i>index;i--)
            arr->A[i] = arr->A[i-1];
        arr->A[index] = x;
        arr->length++;
}

int Delete(struct Array *arr, int index){
    int x = arr->A[index];
    if(index >= 0 && index < arr->length)
        for(int i=index;i<arr->length-1;i++)
            arr->A[i] = arr->A[i+1];
        arr->length--;
        return x;
}

void Swap(int* x, int* y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearch(struct Array * arr, int x){
    for(int i=0; i<arr->length;i++)
        if(x == arr->A[i]) {
            Swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    return -1;
}

// binary search with itterative
int BinarySearch(struct Array arr, int key){
    int l,m,h;
    l = 0;
    h = arr.length;
    while(l<=h){
        m = (l+h)/2;
        if(key == arr.A[m])
            return m;
        else if(key > arr.A[m])
            l = m + 1;
        else
            h = m - 1;
    }
    return -1;
}

//binary search with recursion func
int RBinarySearch(int a[], int l, int h, int key){
    int m;
    if(l<=h)
    {
        m = (l+h)/2;
        if(m == key)
            return m;
        else if(key > a[m])
            return RBinarySearch(a, l, m+1, key);
        else
            return RBinarySearch(a, m-1, h, key);
    }

    return -1;
}

int Get(struct Array arr, int index){
    if(index >= 0 && index < arr.length){
        return arr.A[index];
    }
    return -1;
}

void Set(struct Array* arr, int index, int x){
    if(index >= 0 && index < arr->length){
        arr->A[index] = x;
    }
}

int Max(struct Array arr){
    int max = arr.A[0];
    for(int i=1;i<arr.length;i++){
        if(max < arr.A[i]) max = arr.A[i];
    }
    return max;
}

int Min(struct Array arr){
    int min = arr.A[0];
    for(int i=1;i<arr.length;i++){
        if(min > arr.A[i]) min = arr.A[i];
    }
    return min;
}

int Sum(struct Array arr){
    int sum = arr.A[0];
    for(int i=1;i<arr.length;i++){
        sum += arr.A[i];
    }
    return sum;
}

float Avarege(struct Array arr){
    return (float)Sum(arr)/arr.length;
}

// with auxillary array
void Reverse1(struct Array *arr){
    int* B;
    B = new int[arr->length];
    for(int i=arr->length-1, j=0; i>=0; i--,j++){
        B[j] = arr->A[i];
    }
    for(int i=0;i<arr->length;i++){
        arr->A[i] = B[i];
    }
    delete []B;
}

// without auxillary array
void Reverse2(struct Array *arr){
    for(int i=0,j=arr->length;i<j;i++,i--){
        Swap(&arr->A[i], &arr->A[j]);
    }
}

void LeftShift(struct Array *arr){
    for(int i=0;i<arr->length-1;i++){
        arr->A[i] = arr->A[i+1];
    }
    arr->length--;
}

void RightShift(struct Array *arr){
    for(int i=arr->length-1;i>=0;i--){
        arr->A[i] = arr->A[i-1];
    }
    arr->A[0] = 0;
}

void LeftRotation(struct Array *arr){
    int temp = arr->A[0];
    for(int i=0;i<arr->length-1;i++){
        arr->A[i] = arr->A[i+1];
    }
    arr->A[arr->length-1] = temp;

}

void RightRotation(struct Array *arr){
    int temp = arr->A[arr->length-1];
    for(int i = arr->length-1;i>=0;i--){
        arr->A[i] = arr->A[i-1];
    }
    arr->A[0] = temp;

}

void InsertSort(struct Array *arr, int x){
    int i = arr->length-1;
    if(arr->length==arr->size) return;
    while(i>=0 && arr->A[i]>x){
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length++;
}

int IsSorted(struct Array arr){
    for(int i=0;i<arr.length-1;i++){
        if(arr.A[i] > arr.A[i+1]) return 0;
    }
    return 1;
}

void ReArrange(struct Array *arr){
    int i = 0;
    int j = arr->length-1;
    while(i<j){
        while(arr->A[i] < 0)i++;
        while(arr->A[j] >= 0)j--;

        if(i<j)Swap(&arr->A[i], &arr->A[j]);
    }
}

struct Array *Merge(struct Array *arr1, struct Array *arr2){
    struct Array *arr3;
    arr3 = new Array[arr1->length + arr2->length];

    int i=0,j=0,k=0;

    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i] < arr2->A[j]) arr3->A[k++] = arr1->A[i++];
        else arr3->A[k++] = arr2->A[j++];
    }

    while(i<arr1->length) arr3->A[k++] = arr1->A[i++];
    while(j<arr2->length) arr3->A[k++] = arr2->A[j++];

    arr3->length = arr1->length + arr2->length;

    return arr3;
}

struct Array *Union(struct Array *arr1, struct Array *arr2){
    struct Array *arr3;
    arr3 = new Array[arr1->length + arr2->length];

    int i=0,j=0,k=0;

    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i] < arr2->A[j]) arr3->A[k++] = arr1->A[i++];
        else if(arr1->A[i] > arr2->A[j]) arr3->A[k++] = arr2->A[j++];
        else {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    while(i<arr1->length) arr3->A[k++] = arr1->A[i++];
    while(j<arr2->length) arr3->A[k++] = arr2->A[j++];

    arr3->length = k;
    return arr3;
}

struct Array *Intersection(struct Array *arr1, struct Array *arr2){
    struct Array *arr3;
    arr3 = new Array[arr1->length + arr2->length];

    int i=0,j=0,k=0;

    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i] < arr2->A[j]) i++;
        else if(arr1->A[i] > arr2->A[j]) j++;
        else {
            arr3->A[k++] = arr1->A[i++];
        }
    }

    arr3->length = k;
    return arr3;
}

struct Array *Diffrence(struct Array *arr1, struct Array *arr2){
    struct Array *arr3;
    arr3 = new Array[arr1->length + arr2->length];

    int i=0,j=0,k=0;

    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i] < arr2->A[j]) arr3->A[k++] = arr1->A[i++];
        else if(arr1->A[i] > arr2->A[j]) j++;
        else {
            i++;
            j++;
        }
    }
    while(i<arr1->length) arr3->A[k++] = arr1->A[i++];

    arr3->length = k;
    return arr3;
}

int main() {
    // insert code here...
    struct Array arr;
    int ch;
    int x, index;

    cout<<"Enter size of Array "; cin>>arr.size;
    arr.A = new int[arr.size];
    arr.length = 0;

    do {
        cout<<"\n\nMenu\n";
        cout<<"1. Insert\n";
        cout<<"2. Delete\n";
        cout<<"3. Search\n";
        cout<<"4. Sum\n";
        cout<<"5. Display\n";
        cout<<"6.Exit\n";

        cout<<"Enter Your Choice "; cin>>ch;

        switch(ch) {
            case 1: cout<<"Enter an element and an index ";
                cin>>x>>index;
                Insert(&arr, index, x);
                break;
            case 2: cout<<"Enter an index ";
                cin>>index;
                Delete(&arr, index);
                cout<<"Deleted element is "<<endl;
                break;
            case 3: cout<<"Enter an element ";
                cin>>x>>x;
                LinearSearch(&arr, x);
                cout<<"Element Index "<<endl;
                break;
            case 4: cout<<"Sum Element is "<<Sum(arr)<<endl;
                break;
            case 5: Display(arr);
        }
    } while(ch< 6);


    return 0;
}

