// #include <iostream>
// using namespace std;

// class Queue{
//     private :
//     int size;
//     int front;
//     int rear;
//     int *Q; // this is the array
//     public:
//     Queue(int size);// this is the size
//     ~Queue();//this is the deconstructor
//     bool isFull();
//     bool isEmpty();
//     void enqueue(int x);
//     int dequeue();
//     void display();

// };

// Queue :: Queue(int size){
//     this->size=size;
//     front=-1;rear=-1;
//     Q=new int[size];//assign the queue the address of
// }

// Queue::~Queue(){
//     delete []Q;
// }

// bool Queue::isEmpty(){
//     if(front == rear){
//         return true;
//     }
//     return false;
// }

// bool Queue::isFull(){
//     if(rear==size-1){
//         return true;
//     }
//     return false;
// }

// void Queue::enqueue(int x){
//     if(isFull()){
//         cout<<"Queue Overflow"<<endl;
//     }
//     else{
//         rear++;
//         Q[rear]=x;
//     }
// }

// int Queue::dequeue(){
//     int x=-1;
//     if(isEmpty()){
//         cout<<"the queue is empty"<<endl;
//     }
//     else{
//     front++;             //queue  -1 0 1 2 3 4 5
//     x=Q[front];          //        f
//     }                   //        -> f
//     return x;
// }

// void Queue :: display(){
//     for(int i=front+1;i<=rear;i++){ // deleted element will not be shown
//         cout<<Q[i]<<flush;
//         if(i<rear){
//             cout<<"<-"<<flush;
//         }
//     }
//     cout<<endl;
// }

// int main() {

//     int A[] = {1, 3, 5, 7, 9};
 
//     Queue q(sizeof(A)/sizeof(A[0]));
 
//     // Enqueue
//     for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
//         q.enqueue(A[i]);
//     }
 
//     // Display
//     q.display();
 
//     // Overflow
//     q.enqueue(10);
 
//     // Dequeue
//     for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
//         q.dequeue();
//     }
 
//     // Underflow
//     q.dequeue();
//     return 0;
// }

#include <iostream>
using namespace std;
class Queue{
    private:
    int size;
    int front;
    int rear;
    int *Q;
    public:
    Queue(int size);
    ~Queue();
    bool isEmpty();
    bool isFull();
    void enqueue(int x);
    int   dequeue();
    void display();
};

Queue::Queue(int size){
    this->size=size;// to remove ambiguity
    rear=-1;// can be directly accessed
    front=-1;
    Q=new int[size];
}

bool Queue::isEmpty(){
    if(rear=front){
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

void Queue :: enqueue(int x){
    if(isFull()){
        cout<<"sorry queue is full";
    }
}
int main() {
    return 0;
}