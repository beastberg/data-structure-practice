#include <iostream>
#include<stack>
using namespace std;

class Queue{
    private:
    stack<int> s1;
    stack <int> s2;
    public:
    Queue(){};
    ~Queue(){};
    void enqueue(int x);
    int dequeue();
};
void Queue::enqueue(int x){
    s1.push(x);
}

int Queue::dequeue(){
    int x=-1;
    if(s2.empty()){
        if(s1.empty()){
            cout<<"queue underflow"<<endl;
            return x;
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        
    }
    x=s2.top();
    s2.pop();
    return x;

}

int main() {

    int A[]={1,2,3,4,5,6,7};
    int size=sizeof(A)/sizeof(A[0]);
    Queue q;
    for(int i=0;i<size;i++){
    q.enqueue(A[i]);
    }

    for(int i=0;i<size;i++){
        cout<<q.dequeue()<<" ";
    }
    return 0;
}