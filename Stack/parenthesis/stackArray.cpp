#include<iostream>
using namespace std;

class Stack{
    private:
    
    int size; //
    int top;
    int *S;
    
    public:
    Stack(int size);
    ~Stack();
    void push(int x);
    int pop();
    int peek(int index);
    int isFull();
    int isEmpty();
    void display();
    int stackTop();

};
Stack:: Stack(int size){
    this->size=size;// teeno private to scope ko khatam karo
    top=-1;
    S=new int[size];
}

Stack::~Stack(){
    delete [] S;
}

int Stack::isFull(){
    if(top==size-1){
        return 1;
    }
    return 0;
}

int Stack::isEmpty(){
    if(top==-1){
        return 1;
    }
    return 0;
}
void Stack::push(int x){
    if(isFull()){
        cout<<"Stack overflow"<<endl;
    }
    else{
         top++;
         S[top]=x;
    }
}

int Stack ::pop(){
    int x;
    if(isEmpty()){
        cout<<"Stack underflow"<<endl;
    }
    else{
        x=S[top];
        top--;
    }
}

void Stack::display(){
    for(int i=top;i>=0;i--){
        cout<<S[i]<<" | "<<flush;
    }
    cout<<endl;
}

int Stack::stackTop(){
    if(isEmpty()){
        return -1;
    }
    return S[top];
}

int Stack::peek(int index){
    int x=-1;
    if(top-index+1 <0 || top-index+1==size){
        cout<<"Invalid position";
    }
    else{
        x=S[top-index+1];
    }
    return x;
}
int main(){
    int A[] = {1, 3, 5, 7, 9};
    int size = sizeof(A) / sizeof(A[0]);

    Stack stk(size);

    for (int i = 0; i < size; i++) {
        stk.push(A[i]);
    }
    stk.display();

    
    return 0;
}