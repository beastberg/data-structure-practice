#include <iostream>
using namespace std;

struct Node{
  int data;
  struct Node * next;
}*first;   // this is a way off creating global pointer

void create (int A[],int n){
int i;
struct Node *t,*last;
first=new Node;
first->data=A[0];
first->next=NULL;
last=first;

for(int i=1;i<n;i++){
    t=new Node;
    t->data=A[i];
    t->next=NULL;
    last->next=t;
    last=t;

}

}

void Display(struct Node *p){ // we have created a new node p  which will store the value of first(address)
    while(p!=NULL){
        cout<<p->data<<" ";//print data
        p=p->next;//move to netx pointer

    }
}

//write a recursive function for display
void Rdisplay(struct Node *p){
    if(p!=NULL){
        cout<<p->data;
        Rdisplay(p->next);
    }
}
void Revdisplay(struct Node *p){ // this is rcursive and reverse both
    if(p!=NULL){
        
        Revdisplay(p->next);
        cout<<p->data<<" ";
    }
}

int countNode(struct Node *p){
    if(p==NULL){
        return 0;
    }
    else{
        return countNode(p->next) +1;
    }
}

struct Node *LinearSearch(struct Node *p,int key){
    while(p!=NULL){
        if(key==p->data)
           return p;
        p=p->next;
    }
    return NULL;
}

struct Node *Rsearch(struct Node *p,int key){
    if(p==NULL)
       return NULL;
    if(key==p->data)
      return p;
    return Rsearch(p->next,key);
}
int main() {

    int A[]={3,5,7,10,15};
    create(A,5);
    struct Node *temp=Rsearch(first,15);
    if(temp)
       cout<<"key is found "<<temp->data;
    else 
       cout<<"key is not found";
    return 0;
}
// remembe to debug the program later on