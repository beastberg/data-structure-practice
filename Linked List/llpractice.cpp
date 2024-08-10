#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * next;
};
class ll{
    private:
    Node * first;
    public:
    ll(){first=nullptr;}
    ll(int A[],int n);
    ~ll();

    void display();
    void insert(int index,int x);
    int deletell(int index);
    int length();

};

ll::ll(int A[],int n){
    Node *last,*t;
    int i=0;
    first =new Node;
    first->data=A[0];
    first->next=nullptr;
    last=first;
    for(int i=1;i<n;i++){
        t=new Node;
        t->data=A[i];
        t->next=nullptr;
        last->next=t;
        last=t;
    }
}
ll::~ll(){
    Node *p=first;
    while(first){
        first=first->next;
        delete p;
        p=first;
    }
}

void ll:: display(){
    Node *p=first;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int ll ::length(){
    Node *p=first;
    int len=0;
    while(p){
        len++;
        p=p->next;
        return len;
    }
}
void ll::insert(int index,int x){
    Node *t,*p=first;
    if(index<0||index>length()){
        return;
    }
    t=new Node;
    t->data=x;
    t->next=nullptr;
    if(index==0){
        t->next=first;
        first=t;
    }else{
        for(int i=0;i<index-1;i++)
          p=p->next;
        t->next=p->next;
        p->next=t;
    }
}

int ll::deletell(int index){
    Node *p,*q=nullptr;
    int x=-1;
    if(index<1||index>length())
        return -1;
    else if(index==1){
        p=first;
        first=first->next;
        x=p->data;
        delete p;
    }
    else {
        p=first;
        for(int i=0;i<index-1;i++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        delete p;
    }
    return x;
}

int main() {
  int A[]={1,2,3,4,5};
 ll l(A,5);
 l.insert(3,10);
 l.display();
    return 0;
}