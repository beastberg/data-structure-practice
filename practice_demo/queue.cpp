// #include <iostream>
// using namespace std;

// class Node{
//     public:
//     int data;
//     Node * next;
// };

// class Queue{
//     private:
//     Node * front;
//     Node * rear;
//     public:
//     Queue();
//     ~Queue();
//     void enqueue(int x);
//     int dequeue();
//     bool isEmpty();
//     void display();

// };
// Queue::Queue(){
//     front=nullptr;
//     rear=nullptr;
// }

// void Queue::enqueue(int x){
//     Node *t=new Node;
//     if(t==nullptr){//this means heap is full
//         cout<<" queue overflow";
//     }
//     else{
//         t->data=x;
//         t->next=nullptr;
//         if(front==nullptr){
//             front=t;
//             rear=t;
//         }
//         else{
//             rear->next=t;
//             rear=t;
//         }
//     }
// }

// bool Queue:: isEmpty(){
//     if(front ==nullptr){
//         return true;
//     }
//     else{
//         return false;
//     }
// }

// int Queue::dequeue(){
//     int x=-1;
//     Node*p;
//     if(isEmpty()){
//         cout<<"Queue underflow"<<endl;
//     }
//     else{
//         p=front;
//         front = front->next;
//         x=p->data;
//         delete p;
//     }
//     return x;
// }
// Queue::~Queue(){
//     Node *p =front;
//     while(front){
//         front=front->next;
//         delete p;
//         p=front;
//     }
// }

// void Queue :: display(){
//     Node *p=front;
//     while(p){
//         cout<<p->data<<flush;
//         p=p->next;
//         if(p!=nullptr){
//             cout<<"<-"<<flush;
//         }
//     }
//     cout<<endl;
// }

// int main() {
// int A[]={1,3,5,7,9};

// Queue q;
// int size=sizeof(A)/sizeof(A[0]);
// for(int i=0;i<size;i++){
//     q.enqueue(A[i]);
// }

// q.display();

// for( int i=0;i<size;i++){
//     q.dequeue();
// }

// q.dequeue();

//     return 0;
// }

#include <iostream>
using namespace std;

struct Queue {
    int size ;
    int front ;
    int rear;
    int *Q;
};

void create(struct Queue *q,int size){
    q->size=size;
    q->front=q->rear=-1;
    q->Q=new int [size];
}

void enqueue(struct Queue *q,int s){

    if(q->rear==q->size-1){
        cout<<"queue overflow";
    }
q->rear++;
q->Q[q->rear] =s;
}

int dequeue(struct Queue *q){

    if(q->front ==q->rear){
        cout<<"queue is empty";
    }

    int x=-1;
    q->front++;
    q->Q[q->front]=x;
    return x;

}

void display(struct Queue q){
   for(int i=q.front+1;i<=q.rear;i++){
    cout<<q.Q[i]<<" ";
   }
}





int main() {

    struct Queue q;
    create(&q,5);
    enqueue(&q,1);
    enqueue(&q,2);
    enqueue(&q,3);
    enqueue(&q,4);
    enqueue(&q,5);
   
   display(q);
    return 0;
}


