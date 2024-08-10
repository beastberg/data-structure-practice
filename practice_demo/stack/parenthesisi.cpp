#include <iostream>
#include <cstring>
using namespace std;

class  Stack{
    private:
    char *A;
    int size;
    int top;
    public:
    Stack(){
        size=10;
        top=-1;
        A=new char[10];
    }

    Stack(int size){//parameterised constructor
    this->size=size;
    this->top=-1;
    this->A=new char[this->size];
    }

    void push(char x);
    char pop();
    int peek(int index);
    int isEmpty();
    int isFull();
    void Display(); 
    int stacktop(); 
    int balanced();
};

void Stack:: push(char x){
    if(isFull()){
        cout<<"stack Overflow";
    }else{
        top++;
        A[top]=x;
    }
}

char Stack ::pop(){
    char x=1;
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
    char x=1;
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

bool parenthiesis(string exp){
   Stack st(exp.length());

   for(int i=0;i<exp.length();i++){
    if(exp[i]=='('){
        st.push('(');
    }
    else if (exp[i]==')'){
        if(st.isEmpty()){
            return 0;
        }
        else{
            st.pop();
        }
    }
   }
   return st.isEmpty()?1:0;
}


int main() {
 string b = "((a+b)*(c-d))";
    cout << parenthiesis(b) << endl;
    return 0;
}