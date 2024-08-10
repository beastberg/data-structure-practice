#include <iostream>
using namespace std;

class  Stack{
    private:
    int *A;
    int size;
    int top;
    public:
    Stack(){
        size=10;
        top=-1;
        A=new int[10];
    }

    Stack(int size){//parameterised constructor
    this->size=size;
    this->top=-1;
    this->A=new int[this->size];
    }

    void push(int x);
    int pop();
    int peek(int index);
    int isEmpty();
    int isFull();
    void Display(); 
    int stacktop(); 
};

void Stack:: push(int x){
    if(isFull()){
        cout<<"stack Overflow";
    }else{
        top++;
        A[top]=x;
    }
}

int Stack ::pop(){
    int x=-1;
    if(isEmpty()){
        cout<<"stack underflow";
    }
    else{
        x=A[top];
        top--;
    }
    return x;
}

int Stack :: peek(int index){
    int x=-1;
    if(top-index+1<0){
        cout<<"Invalid index"<<endl;                //5 ->this is first index
    }else{                                          //4 ->this is second index
        x=A[top-index+1];//this is a top down markdown
    }
    return x;
}

int Stack :: stacktop(){
    if(isEmpty()){
        return -1;
    return A[top];
    }
}
int Stack :: isFull(){
    return top==size-1;
}

int Stack ::isEmpty(){
    return top==-1;
}
void Stack ::Display(){
    for(int i=top;i>=0;i--){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int main() {
    Stack st(6);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.Display();
    cout<<st.isFull();
    cout<<endl;
    cout<<st.peek(2);
    return 0;
}