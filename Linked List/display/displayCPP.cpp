#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LL{
private:
 Node *first;//creating a global pointer
public:
 LL(){first= NULL;}// WE HAVE DIRECT ACCESS OF FIRST POINTER
 LL(int A[],int n);//paramterised constructor
 ~LL(); // this is a contructor

//method

void Display();
void Insert(int index,int x);
int Delete(int index);
int  Length();
};

LL::LL(int A[],int n){
    Node * last,*t;
    int i=0;
    first =new Node;//new node in heap
    first->data=A[0];// assigning data to node
    first->next=NULL;//next pointer is null
    last=first;

    for(int i=1;i<n;i++){
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

LL::~LL(){
    Node *p=first;
    while (first)
    {
        first=first->next;
        delete p;
        p=first;
    }
    
}

void LL:: Display(){
    Node *p=first;
    while(p){
        cout<<p->data<<" ";
        p=p->next;

    }
    cout<<endl;
}
int LL:: Length(){
    Node *p=first;
    int len=0;
    while(p){ // this means while is true
     len++;
     p=p->next;
    }

   return len;
}
void LL:: Insert(int index,int x){
    Node *p,*t=first;
    if(index<0|| index>Length())
       return;
    t=new Node;
    t->data=x;
    t->next=NULL;

    if(index==0){
        t->next=first;
        first=t;
    }
    else{
        p=first;
        for(int i=0;i<index-1;i++)
            p=p->next;
        t->next=p->next;
        p->next=t;
    }
}

int LL :: Delete(int index){ //index ,node you want to delete
    Node *p,*q=NULL;
    int x=-1;
    if(index<1 ||index>Length())// to delete a first node we have to come a node before that
       return -1;
    if(index==1){
        p=first;
        first=first->next;
        x=p->data;
        delete p;
        
    }
    else{
        p=first;
        for(int i=0;i<index-1;i++){ 
            q=p;// to delete other node we have to come on the exact node which we want to delete
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        delete p;
    }
    return x;
}

int main()
{ 
    int A[]={1,2,3,4,5};
    LL l(A,5);
    l.Display();
    cout<<endl;
    l.Insert(4,8);
    l.Display();
    cout<<endl;
    l.Delete(1);
    l.Display();

    return 0;
}