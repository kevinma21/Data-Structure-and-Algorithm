//#include<iostream>
//using namespace std;
//
//class Stack {
//private:
//    int size;
//    int top;
//    int *S;
//public:
//    Stack(int size);
//    ~Stack();
//    
//    void Display();
//    void Push(char x);
//    char Pop();
//    int Peek(int index);
//    int IsEmpty();
//    int IsFull();
//    int StackTop();
//    int IsBalanced(char *a);
//};
//
//Stack:: Stack(int size) {
//    this->size = size;
//    S = new int[this->size];
//    top = -1;
//}
//
//Stack:: ~Stack() {
//    delete []S;
//}
//
//void Stack:: Display() {
//    for(int i=top;i>=0;i--)
//        cout<< S[i] << " ";
//    cout<<endl;
//}
//
//void Stack:: Push(char x) {
//    if(top==size-1){
//        cout<<"Stack overflow"<<endl;
//    } else {
//        top++;
//        S[top] = x;
//    }
//}
//
//char Stack:: Pop() {
//    char x = -1;
//    if(top==-1) cout<<"Stack underflow"<<endl;
//    else {
//        x=S[top--];
//    }
//    return x;
//}
//
//int Stack:: Peek(int index) {
//    int x=-1;
//    if(top-index+1<0){
//        cout<<"Invalid Index"<<endl;
//    } else {
//        x = S[top-index+1];
//    }
//    return x;
//}
//
//
//int Stack:: IsEmpty() {
//    return top==-1 ? 1 : 0;
//}
//
//int Stack:: IsFull() {
//    return top==size-1;
//}
//
//int Stack:: StackTop() {
//    return IsEmpty() ? -1 : S[top];
//}
//
///*
// code on below is for parenthesis matching.
// example code like this:
//    char exp[] = "((a+b)*(c-d))";
//    st.IsBalanced(exp) ? cout<<"Parenthesis"<<endl : cout<<"Not Parenthesis"<<endl;
//*/
//int Stack:: IsBalanced(char *exp) {
//    for(int i=0;exp[i]!='\0';i++){
//        if(exp[i]=='(') Push(exp[i]);
//        else if (exp[i]==')'){
//            if(IsEmpty()) return 0;
//            else Pop();
//        }
//    }
//    return IsEmpty() ? 1 : 0;
//}
//
//int main() {
////    int size; cout<<"Input Size of Stack: "; cin>>size;
//    
//    Stack st(5);
//    
//    
//    
//    return 0;
//}
