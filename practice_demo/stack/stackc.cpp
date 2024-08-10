#include <iostream>
using namespace std;
struct stack{
int top;
int size;
int *S;
};

void create(struct stack *st){
    st->top=-1;
    int x;
    cout<<"enter the size of stack";
    cin>>x;
    st->size=x;
    st->S=new int[st->size];
}

bool isEmpty(stack *s){
    if(s->top==-1){
       return true;
    }
    return false;
}
bool isFull(stack *s){
    if(s->top==s->size-1){
        cout<<"stack overflow";
        return 1;
    }
    return 0;
    
}

void push(struct stack *st,int x){
    if(isFull(st)){
          cout<<"stack is  full"    ;
    }
    else{
        st->top++;
        st->S[st->top]=x;
    }
}

int pop(struct stack *st){
    int x=-1;
    if(isEmpty(st)){
       cout<<" stack is empty";
    }
    x=st->S[st->top];
    st->top--;
    return x;


}
int peek(stack st,int pos){
    int x=-1;
    if(st.top-pos +1<0){
        cout<<" invalid pos";
    }
    else{
        x=st.S[st.top-pos+1];
    }
    return x;

}void display(struct stack st){
    for(int i=st.top;i>=0;i--){
        cout<<st.S[i]<<" ";
    }
    cout<<endl;
}

int main() {
    struct stack st;
    int choice;int pos;
    int x;
    do{
        cout<<" 1 -> create stack "<<endl;;
        cout<<" 2 -> push to stack"<<endl;;
        cout<<" 3 -> pop stack"<<endl;
        cout<<" 4 -> peek stack"<<endl;
        cout<<" 5 -> diplay the element of stack"<<endl;
        cout<<" 6 -> exit"<<endl;
        cout<<"Enter your choice: ";
        cin>> choice;

        switch(choice){
            case 1:
            cout<<"please create and initalise the stack: ";
            create(&st);
            break;

            case 2:
            cout<<"please push item to stack: ";
            cin>> x;
            push(&st,x);
            break;

            case 3:
            cout<<"poped item from stack";
            cout<<pop(&st);
            break;

            case 4:
            cout<<"enter the postion you want to see ";
            cin>>pos;
            cout<<"your element is :"<<peek(st,pos)<<endl;
            break;
            
            case 5:
            cout<<" the element of the stack are ";
            display(st);
            break;


            case 6:
            cout<<"EXITING PROGRAM ";

            default:
            cout<<"invalid choice! please enter a valid input";
        }

    }while(choice !=6);
     
return 0;
}

