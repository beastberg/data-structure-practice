#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node() :data(0),left(nullptr),right(nullptr){}
    Node(int val):data(val),left(nullptr),right(nullptr){}
};

class Queue{
    private:
    int size;
    int front;
    int rear;
    Node* *Q;

    public:
    Queue(int size);
    ~Queue();
    bool isEmpty();
    bool isFull();
    void enqueue(Node* x);
    Node* dequeue();
};

Queue::Queue(int size){
    this->size=size;
    front=-1;
    rear=-1;
    Q=new Node*[size];
}

Queue::~Queue(){
    delete []Q;
}

bool Queue::isEmpty(){
    return rear==front;
}

bool Queue::isFull(){
    return rear==size-1;
}

void Queue::enqueue(Node *x){
    if(isFull()){
        cout<<"queue overflow"<<endl;
    }
    else{
        rear++;
        Q[rear]=x;
    }
}

Node* Queue::dequeue(){
    Node* x=nullptr;
    if(isEmpty()){
        cout<<"queue underflow"<<endl;
    }
    else{
        front++;
        x=Q[front];
    }
    return x;
}

class Tree{
    private:
    Node* root;

    public:
    Tree(){root=nullptr;}
    void createTree();
    void preorder(){preorder(root);}
    void preorder(Node *p);
};

void Tree::createTree(){
    Node *p;
    Node *t;
    int x;
    Queue q(20);
    root=new Node;
    cout<<"enter the value of the root: ";
    cin>>x;
    root->data=x;
    q.enqueue(root);

    while(!q.isEmpty()){
        p=q.dequeue();


        cout << "Enter the left child of " << p->data << " (-1 for no child): ";
        cin >> x;
        if (x != -1) {
            t = new Node(x);
            p->left = t;
            q.enqueue(t);
        }

        cout << "Enter the right child of " << p->data << " (-1 for no child): ";
        cin >> x;
        if (x != -1) {
            t = new Node(x);
            p->right = t;
            q.enqueue(t);
        }

    }
}

void Tree::preorder(Node* p) {
    if (p) {
        cout << p->data << " " << flush;
        preorder(p->left);
        preorder(p->right);
    }
}

int main(){
    Tree t;
    t.createTree();

    cout << "Preorder traversal: ";
    t.preorder();
    return 0;
}