#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
}*first; //create a global header

void create(int A[],int n){
    int i;
    struct Node *t,*last;
    first=new Node;
    first->data=A[0];
    first->next=NULL;
    last=first; //last pointer will initailly point at the first pointer and 
                //move next when a new node is added
    for(int i=1;i<n;i++){
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }

}

void Display(struct Node *p){ //p is created in stack
//using it new enter the heap and access the first Node
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
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
int main() {
     int A[]={3,5,7,10,15};
    create(A,5);
   
    Display(first);
    cout<<countNode(first);
    return 0;
}