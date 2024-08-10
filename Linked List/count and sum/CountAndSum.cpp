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

int Rcount(struct Node *p){
    if(p!=NULL)
        return Rcount(p->next)+1;
    else 
        return 0;
}

int count(struct Node *p){
    int l=0;
    while(p){
        l++;
        p=p->next;
    }
    return l;

}
int sum(struct Node *p){
    int s=0;
    while(p!=NULL){
        s+=p->data;
        p=p->next;
    }
    return s;
}

int Rsum(struct Node *p){
    if(p==NULL){
        return 0;
    }
    else{
        return Rsum(p->next)+p->data;
    }
}

int Max(struct Node *p){
    int max =0;
    while(p){   //mean p is not null
    if(p->data>max)
        max=p->data;
    p=p->next;
    }
    return max;

}


int main() {

    int A[]={3,5,7,10,15};
    create(A,5);
    cout<<"length is "<<Rsum(first);
    cout<<"the largest element is "<<Max(first);
    return 0;
}
// remembe to debug the program later on