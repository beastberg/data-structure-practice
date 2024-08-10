#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(): data(0), next(nullptr) {}
    Node(int val): data(val), next(nullptr) {}
};

class circularLL {
private:
    Node* head;
public:
    circularLL(): head(nullptr) {}
    void create(int A[], int n);
    void Display(Node* h);
    void recursiveDisplay(Node* h);
    Node* getHead() {
        return head;
    }
};

void circularLL::create(int A[], int n) {
    if (n == 0) return; // handle empty array case

    Node* t;
    Node* last;
    head = new Node(A[0]);
    head->next = head; // circular linked list

    last = head;

    for (int i = 1; i < n; i++) {
        t = new Node(A[i]);
        t->next = head; // insert new node before the head
        last->next = t; // link last node to the new node
        last = t; // update last node
    }
}

void circularLL::Display(Node* h) {
    if (h == nullptr) return;
    Node* start = h;
    do {
        cout << h->data << " ";
        h = h->next;
    } while (h != start);
    cout << endl;
}

void circularLL::recursiveDisplay(Node* h) {
    if (h == nullptr) return;
    static Node* start = nullptr;
    if (start == nullptr) start = h; // initialize start pointer

    if (h != start || start == nullptr) { // base case to terminate recursion
        cout << h->data << " ";
        recursiveDisplay(h->next);
    }
}

int main() {
    int A[] = {2, 3, 4, 5, 6};
    circularLL ll;
    ll.create(A, 5);
    cout << "Display using Display method: ";
    ll.Display(ll.getHead());
    cout << "Display using recursiveDisplay method: ";
    ll.recursiveDisplay(ll.getHead());
    cout << endl;
   
    cout<<"hello world";
    cout<<123<<endl;
    
    return 0;
}
