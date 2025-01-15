#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
};

class Sorts {
private:
    int *arr;
    int n;
    Node **Bins;
    Node **BinRadix;
    void Swap(int *a, int *b);
public:
    Sorts (int *arr, int n) {
        this->arr = new int;
        this->arr = arr;
        this->n = n;
        
        
        BinRadix = new Node*[10];
        Bins = new Node*[FindMax()+1];
    }
    
    void Display();
    void BubleSort();
    void InsertionSort();
    void SelectionSort();
    void QuickSort(int l, int h);
    void IMergeSort();
    void RMergeSort(int l, int h);
    void CountSort();
    void BinSort();
    void RadixSort();
    void ShellSort();
    
    void Merge(int l, int mid, int h);
    void Insert(int x);
    void InsertRadix(int x, int n);
    int DeleteRadix(int x);
    int Delete(int x);
    int FindMax();
    int Partition(int l, int h);
    int CountMax(int x);
    
};

void Sorts:: Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Sorts:: Display() {
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int Sorts:: FindMax() {
    int max = INT_MIN;
    for(int i=0;i<n;i++) {
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}

void Sorts:: BubleSort() {
    int flag;
    for(int i=0;i<n-1;i++) {
        flag = 0;
        for(int j=0;j<n-i-1;j++)
            if(arr[j] > arr[j+1]) {
                Swap(&arr[j], &arr[j+1]);
                flag = 1;
            }
        if(!flag)
            break;
    }
}

void Sorts:: InsertionSort() {
    int i,j,x;
    for(i=1;i<n;i++) {
        j = i - 1;
        x = arr[i];
        
        while(j > -1 && arr[j] > x) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = x;
    }
}

void Sorts:: SelectionSort() {
    int i,j,k;
    for(i=0;i<n-1;i++) {
        for(j=k=i;j<n;j++)
            if(arr[k]>arr[j])
                k = j;
        Swap(&arr[i], &arr[k]);
    }
}

//this partition is finding sorted position of an element
int Sorts:: Partition(int l, int h) {
    int pivot = arr[l];
    int i=l,j=h;
    
    do {
        do{i++;}while(arr[i]<=pivot);
        do{j--;}while(arr[j]>pivot);
        
        if(i<j) Swap(&arr[i], &arr[j]);
    } while(i<j);
    Swap(&arr[l], &arr[j]);
    return j;
}

void Sorts:: QuickSort(int l, int h) {
    int j;
    if(l<h) {
        j = Partition(l, h);
        QuickSort(l, j);
        QuickSort(j+1, h);
    }
}

void Sorts:: Merge(int l, int mid, int h) {
    int i,j,k;
    i=l;j=mid+1;k=l;
    int temp[h+1];
    
    while(i<=mid && j<=h) {
        if(arr[i]<arr[j])
            temp[k++]=arr[i++];
        else
            temp[k++]=arr[j++];
    }
    
    // for remaining elements in both arrays
    for(;i<=mid;i++)
        temp[k++] = arr[i];
    for(;j<=h;j++)
        temp[k++] = arr[j];
    
    //for copying from temp array to original array
    for(i=l;i<=h;i++) {
        arr[i] = temp[i];
    }
}

void Sorts:: IMergeSort() {
    int p,l,h,mid,i;
    
    for(p=2;p<=n;p=p*2) {
        for(i=0;i+p-1<=n;i=i+p) {
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            Merge(l, mid, h);
        }
        if(n-i>p/2) {
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            Merge(l, mid, h);
        }
    }
    if(p/2<n)
        Merge(0, p/2-1, n-1);
}

void Sorts:: RMergeSort(int l, int h) {
    int mid;
    if(l<h) {
        mid = (l+h)/2;
        RMergeSort(l, mid);
        RMergeSort(mid+1, h);
        Merge(l, mid, h);
    }
}

void Sorts:: CountSort() {
    int i,j,max;
    max = FindMax();
    int *c;
    c = new int[max+1];
    
    // make all lists bacome 0
    for(i=0;i<max+1;i++)
        c[i] = 0;
    
    for(i=0;i<n;i++) {
        c[arr[i]]++;
    }
    
    i = 0; j = 0;
    while(i < max + 1) {
        if(c[i]>0) {
            arr[j++] = i;
            c[i]--;
        } else
            i++;
    }
}

void Sorts:: Insert(int x) {
    Node * temp = new Node;
    temp->data = x;
    temp->next = nullptr;
    
    if(Bins[x]==nullptr) {
        Bins[x] = temp;
    } else {
        Node *p = Bins[x];
        while(p->next!=nullptr) {
            p=p->next;
        }
        p->next = temp;
    }
}

int Sorts:: Delete(int x) {
    int val;
    Node *p = Bins[x];
    Bins[x] = p->next;
    val = p->data;
    delete p;
    return val;
}

void Sorts:: BinSort() {
    int i,j,max;
    max = FindMax() + 1;
    
    for(i=0;i<max;i++)
        Bins[i] = nullptr;
    
    for(i=0;i<n;i++)
        Insert(arr[i]);
    
    i = 0; j =0;
    while(i<max) {
        while(Bins[i]!=nullptr) {
            arr[j++] = Delete(i);
        }
        i++;
    }
}

void Sorts:: InsertRadix(int x, int n) {
    Node * temp = new Node;
    temp->data = x;
    temp->next = nullptr;
    
    if(BinRadix[n]==nullptr) {
        BinRadix[n] = temp;
    } else {
        Node *p = BinRadix[n];
        while(p->next!=nullptr) {
            p=p->next;
        }
        p->next = temp;
    }
}

int Sorts:: DeleteRadix(int x) {
    int val;
    Node *p = BinRadix[x];
    BinRadix[x] = p->next;
    val = p->data;
    delete p;
    return val;
}

int Sorts:: CountMax(int x) {
    int n = 0;
    while(x > 0) {
        x/=10;
        n++;
    }
    return n;
}

void Sorts:: RadixSort() {
    int i,j,max,d=1;
    max = CountMax(FindMax());
    
    for(i=0;i<10;i++)
        BinRadix[i] = nullptr;
    
    for(int p=1;p<=max;p++) {
        for(i=0;i<n;i++)
            InsertRadix(arr[i], (arr[i]/d)%10);
        
        i=j=0;
        while(i<n) {
            while(BinRadix[i]!=nullptr) {
                arr[j++] = DeleteRadix(i);
            }
            i++;
        }
        d = d * 10;
    }
}

void Sorts:: ShellSort() {
    int i,j,gap,temp;
    for(gap=n/2;gap>=1;gap/=2) {
        for(i=gap;i<n;i++) {
            temp = arr[i];
            j = i-gap;
            while(j>=0 && arr[j]>temp) {
                arr[j+gap] =  arr[j];
                j -= gap;
            }
            arr[j+gap] = temp;
        }
    }
}

int main() {
    int arr[] = {11,13,7,12,16,9,24,5,10,3};
    int n = 10;

    Sorts obj(arr, n);
    
    obj.ShellSort();
    obj.Display();
    
    return 0;
}

