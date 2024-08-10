#include<iostream>
using namespace std;

class Queue{
    private:
   int front;
   int rear;
   int size;
   int *Q;

   public:
   
   Queue(int sz);
   ~Queue();
   void enqueue(int x);
   int dequeue();
   bool isEmpty();
   bool isFull();
};
Queue::Queue(int sz){
    this->size=sz;
    Q=new int[sz];
    front=-1;
    rear=-1;
}

Queue::~Queue(){
    delete []Q;
}

bool Queue::isEmpty(){
    if(rear==front){
        return true;
    }
    return false;
}

bool Queue::isFull(){
    if(rear=size-1){
        return true;
    }
    return false;
}

void Queue::enqueue(int x){
    if(isFull()){
        cout<<"Queue is full "<<endl;
    }
    Q[rear++]=x;

}
int Queue::dequeue(){
    if(isEmpty()){
        return 
    }
}

int main(){
    
    return 0;
}