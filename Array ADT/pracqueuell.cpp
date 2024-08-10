#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue();
    ~Queue();
    void enqueue(int x);
    int dequeue();
    bool isEmpty();
    void Display();
};

Queue::Queue() {
    front = nullptr;
    rear = nullptr;
}

void Queue::enqueue(int x) {
    Node* t = new Node;
    if (t == nullptr) {
        cout << "Queue overflow" << endl;
    } else {
        t->data = x;
        t->next = nullptr;
        if (front == nullptr) {
            front = t;
            rear = t;
        } else {
            rear->next = t;
            rear = t;
        }
    }
}

int Queue::dequeue() {
    int x = -1;
    Node* p;
    if (isEmpty()) {
        cout << "Queue underflow" << endl;
    } else {
        p = front;
        front = front->next;
        x = p->data;
        delete p;
    }
    return x;
}

bool Queue::isEmpty() {
    return front == nullptr;
}

Queue::~Queue() {
    Node* p = front;
    while (front) {
        front = front->next;
        delete p;
        p = front;
    }
}

void Queue::Display() {
    Node* p = front;
    while (p) {
        cout << p->data << flush;
        p = p->next;
        if (p != nullptr) {
            cout << "->" << flush;
        }
    }
    cout << endl;
}

int main() {
    int A[] = {1, 2, 3, 4, 5, 6};
    Queue q;
    int s = sizeof(A) / sizeof(A[0]);
    for (int i = 0; i < s; i++) {
        q.enqueue(A[i]);
    }
    q.Display();

    for (int i = 0; i < s; i++) {
        q.dequeue();
    }

    q.dequeue();
    q.Display();
    return 0;
}
