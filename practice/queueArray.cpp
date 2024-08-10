#include<iostream>
using namespace std;

class Queue{
    private:
    
    int size;
    int front;
    int rear;
    int * Q;
    
    public:
    Queue(int size);
    ~Queue();
    bool isFull();
    bool isEmpty();
    void enqueue(int x);
    int dequeue();
    void display();

};

Queue::Queue(int size){
    this->size=size;
    front=-1;
    rear=-1;
    Q=new int[size];
}

Queue::~Queue(){
    delete [] Q;
}

bool Queue::isEmpty(){
    if(front==rear){
        return true;
    }
    return false;
}
bool Queue::isFull(){
   if(rear==size-1){
    return true;
   }
   return false;
   
}

void Queue::enqueue(int x){
    if(isFull()){
        cout<<"Queue overflow"<<endl;
    }
    else{
        rear++;
        Q[rear]=x;
    }

}

int Queue::dequeue(){
    int x =-1;
    if(isEmpty()){
        cout<<"Queue underflow"<<endl;
    }
    else{
        front++;
        x=Q[front];
    }
    return x;
}

void Queue::display(){ // front is the oldest element 
    for(int i=front+1;i<=rear;i++){//-1+1=0
        cout<<Q[i]<<flush;
        if(i<rear){
            cout<<"->"<<flush;
        }
    }
    cout<<endl;
}

int main(){
 
int A[]={1,3,5,7,9,11};
int size = sizeof(A)/sizeof(A[0]);
Queue q(size);

//enqueue
for(int i=0;i<size;i++){
    q.enqueue(A[i]);
}
//display
q.display();

//oveflow
//q.enqueue(10);

//deque
for(int i=0;i<size;i++){
    q.dequeue();
}
q.display();

// //underflow
q.dequeue();

    return 0;
}