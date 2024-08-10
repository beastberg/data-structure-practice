#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * next;
};
class stack {
    private:
      Node * top;
    public:
       stack();
       void push(int x);
       int pop();
       void display();
       int peek(int pos);
       bool isEmpty();
       int isFull();
       int stacktop();
       
       
};

stack:: stack(){
    top=nullptr;
}



void stack::push(int x){
    Node * t=new Node;
    if(t==NULL){
        cout<<"  the stack is full" <<endl;
    }
    
        
        else{
            t->data=x;
            t->next=top;
            top=t;
        }
    
}
int stack:: peek(int pos){
    Node *p=top;// this is a second pointer to top position
    int x=-1;
    int i=0;
    while(i<pos-1 && p!=NULL){
        p=p->next;
        i++;
    }
   if(p!=NULL){
        return x=p->data;
   } 

   return x;
}

int stack :: pop(){
    Node *p;
    int x=-1;
    if(isEmpty()){
        cout<<"the stack is empty";
    }
    p=top;
    top=top->next;
    x=p->data;
    delete p;
    return x;
}

void stack:: display(){
    Node *p = top;
    if(top==nullptr){
        cout<<"there is nothing to display"<<endl;
    }
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;

    }
}

int stack:: stacktop(){
    if(top){
        return top->data;
    }
    return -1;
}

int stack::isFull(){
    Node *t=new Node;
    
    int r=t?1:0;
    delete t;
    return r;
}
bool stack :: isEmpty(){
return top?0:1;
}

int main() {
    int choice;
    int x;
    int pos;
    stack st;

    do{
        cout<<" 1  create a stack"<<endl;
        cout<<" 2 push to satck"<<endl;
        cout<<" 3 pop out of the stack"<<endl;
        cout<<" 4 stack display"<<endl;
        cout<<" 5 stack peek"<<endl;
        cout<<" 6 stack top"<<endl;
        cout<<" 7 stack empty"<<endl;
        cout<<" 8 stack full "<<endl;
        cout<<" 9 exit "<<endl;
    
        cin>>choice;
        switch(choice){
            case 1:
            cout<<"stack is created please give other function"<<endl;
            break;

            case 2:
            cout <<" push to stack , enter element"<<endl;
            cin>>x;
            st.push(x);
            break;

            case 3:
            cout<< " the poped element is "<<st.pop()<<endl;
            break;

            case 4:
            cout<<"the element of stack are ";
            st.display();
            break;

            case 5:
            cout<<"enter the position to peek element ";
            cin>>pos;
            cout<<"the peeked element id  "<<st.peek(pos);
            break;

            case 6:
            cout<<"the top element is "<<st.stacktop();
            break;

            case 7:
            cout<<"stack empty for not"<<st.isEmpty();
            break;
            case 8:
            cout<<"stack is full or not "<<st.isFull();
            break;

            case 9:
            cout<<"exit the loop";
            break;

            default :
            cout<<" invalid input,please fuck off"<<endl;
            break;



        }

    }while(choice !=9);
    
    
    return 0;
}