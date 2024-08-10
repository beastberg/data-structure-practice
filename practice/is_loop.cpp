#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node():data(0),next(nullptr){};
    Node(int data):data(data),next(nullptr){};
    
};
class linkedlist{
    private:
    Node* first;
    public:
    linkedlist();
    linkedlist(int A[],int n);
    ~linkedlist();
    int Length();
    void Insert(int index,int x);
    int Delete(int index);
    int maxElement;
    int totalSum;
    void display();
    bool loop();
    void createLoop(int pos1,int pos2);

};

linkedlist::linkedlist(){
    first=nullptr;
}
linkedlist::linkedlist(int A[],int n){
    Node *t,*last;
    int i=0;
    first=new Node;
    first->data=A[0];
    first->next=nullptr;
    last =first;
    for(int i=1;i<n;i++){
        t=new Node(A[i]);
        last->next=t;
        last=t;
    }
}
linkedlist::~linkedlist(){
    Node* p=first;
    while(p){
        first=first->next;
        delete p;
        p=first;
    }
}
int linkedlist::Length(){
    Node *p=first;
    int len=0;
    while(p){
        len++;
        p=p->next;
    }
    return len;
}
void linkedlist::Insert(int index,int x){
    Node*t,*p=first;
    if(index<=0||index>Length())
       return ;
    t=new Node(x);
    
    if(index==1){
        t->next=first;
        first=t;
    }
    else{
        for(int i=0;i<index-2;i++)
          p=p->next;    
        t->next=p->next;
        p->next=t;  
    }
    
}
void linkedlist::display(){
    Node* p =first;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
}
int linkedlist::Delete(int index){
    Node *q,*p=nullptr;
    int val;
    if(index<=0||index>Length())
       return -1;
    if(index==1){
     p=first;
     first=first->next;
     val=p->data;
     delete p;
     
    }
    else{
        p=first;
        for(int i=0;i<index-2;i++){
            p=p->next;
        }
        q=p->next;
        val=q->data;
        p->next=q->next;
        delete q;

    }
    return val;
}
bool linkedlist::loop(){
    Node *p,*q=first;
    p=q;
    while(q!=nullptr && q->next!=nullptr){
        p=p->next;
        q=q->next->next;
        if(p==q)
          return true;
    }
    return false;
}
void linkedlist::createLoop(int pos1,int pos2){
    if(!first) return;
    Node *t1,*t2=first;
    t1=t2; 
    for(int i=0;t1 && i<pos1;i++){
        t1=t1->next;
    }
     for(int i=0;t2 && i<pos2;i++){
        t2=t2->next;
    }
    if(t2){
        t2->next=t1;
    }

}


int main(){
    int A[] = {10, 20, 30, 40, 50};
    linkedlist list(A, 5);
    
    list.display();
    // Creating a loop for testing
    list.createLoop(2, 4);
    
    if (list.loop()) {
        cout << "Loop detected" << endl;
    } else {
        cout << "No loop detected" << endl;
    }
    return 0;
}