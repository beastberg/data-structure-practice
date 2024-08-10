// #include <iostream>
// #include <queue>
// using namespace std;

// class Node{
//     public:
//     Node * left;
//     int data;
//     Node * right;
// };

// class Tree{
//     private:
//     Node * root;//this is pointer to node

//     public:
//     Tree(){root=NULL;}
//     void CreateTree();
//     void Inorder(Node *p);
// };

// void Tree::CreateTree(){
//     Node *p,*t;
//     int x;
//     queue<Node *> q;
//     cout<<"enter the root value ";
//     cin>>x;
//     root=new Node;
//     root->data=x;
//     root->right=root->left=nullptr;
//     q.push(root);

//     while(!q.empty()){
//       p=q.front();
//       q.pop();
//       cout<<"enter the left child of "<<p->data<<" ";
//       cin>>x;
//       if(x!=-1){
//         t=new Node;
//         t->data=x;
//         t->left=t->right=NULL;
//         p->left=t;
//         q.push(t);
//       }

//       cout<<"enter the right child of "<<p->data<<" ";
//       cin>>x;
//       if(x!=-1){
//         t=new Node;
//         p->right=t;
//         t->data=x;
//         t->left=t->right=nullptr;
//         q.push(t);
//       }
//     }



// }
// void Tree::Inorder(Node * p){
    
//     if(p){
//         Inorder(p->left);
//         cout<<p->data<<" ";
//         Inorder(p->right);
//     }
// }

// int main() {
//     Tree t;
//     t.CreateTree();
//     t.Inorder(t.root)
    
//     return 0;
// }

#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    Node* left;
    int data;
    Node* right;

    Node(int data) : left(nullptr), data(data), right(nullptr) {} // Constructor for efficient initialization
};

class Tree {
private:
    Node* root;

public:
    Tree() : root(nullptr) {} // Constructor to maintain root initialization

    void CreateTree();
    void Inorder(Node* p);
    void Inorder(){
        Inorder(root);
    }
};

void Tree::CreateTree() {
    Node* p, *t;
    int x;
    queue<Node*> q;

    cout << "Enter the root value: ";
    cin >> x;

    root = new Node(x); // Use constructor for clean initialization
    q.push(root);

    while (!q.empty()) {
        p = q.front();
        q.pop();

        cout << "Enter the left child of " << p->data << ": ";
        cin >> x;

        if (x != -1) {
            t = new Node(x); // Use constructor for clean initialization
            p->left = t;
            q.push(t);
        }

        cout << "Enter the right child of " << p->data << ": ";
        cin >> x;

        if (x != -1) {
            t = new Node(x); // Use constructor for clean initialization
            p->right = t;
            q.push(t);
        }
    }
}

void Tree::Inorder(Node* p) {
    if (p) {
        Inorder(p->left);
        cout << p->data << " ";
        Inorder(p->right);
    }
}

int main() {
    Tree t;
    t.CreateTree();
    t.Inorder( );

    return 0;
}
