#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * next;
};

class Stack{
private:
Node * top ;
public:
   Stack (){top = NULL;}
   void push(int x);
   int pop();
   void Display();
};

void Stack:: push(int x){
    Node *t=new Node;
    if(t==NULL){// THIS means we cannot allocate memeory in heap it is full
        cout<<"stack is full";
    }
    else{
        t->data=x;
        t->next=top;
        top=t;

    }

}
int Stack :: pop(){
    int x=-1;
    if(top==NULL){
        cout<<"Stack is empty"<<endl;
    }else{
        x=top->data;
        Node *t=top;
        top=top->next;
        delete t;
    }
    return x;
}

void Stack::Display(){
    Node *p=top;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main() {

    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.Display();
    return 0;
}