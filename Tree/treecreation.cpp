#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
    Node* left;
    int data;
    Node* right;
};

class Tree{
    private:
    Node * root;
    public:
    Tree();// this is the tree constructor
    //~Tree();
    void createTree();
    void preorder(Node *p);
    void preorder(){
        preorder(root);
    };
    void levelOrder(Node *p);
    void levelOrder(){
        levelOrder(root);
    }
   
    void levelOrder(Node *p);
    void levelOrder(){
        levelOrder(root);
    }

};
Tree::Tree(){
    root=nullptr;
}

void Tree::createTree(){
    Node* p;
    Node* t;
    int x;
    queue<Node *>q;
    root=new Node;
    cout<<"enter root data "<<endl;
    cin>>x;
    root->data=x;
    root->left=nullptr;
    root->right=nullptr;
    q.push(root);

    while(!q.empty()){
        p=q.front();
        q.pop();
        cout<<"enter the left child of "<<p->data<<": "<<endl;
        cin>>x;
        if(x!=-1){
            t=new Node;
            t->data=x;
            t->left=nullptr;
            t->right=nullptr;
            p->left=t;
            q.push(t);
        }
        cout<<"enter the roght child of "<<p->data<<": "<<endl;
        cin>>x;
        if(x!=-1){
            t=new Node;
            t->data=x;
            t->left=nullptr;
            t->right=nullptr;
            p->right=t;
            q.push(t);
        }

    }

}
void Tree ::preorder (Node *p){
    if(p){//check if p exist or not 
    
    cout<<p->data<<", ";
    preorder(p->left);
    preorder(p->right);
    }   
}

void Tree::levelOrder(Node *p){
    queue<Node* >q;
    cout<<root->data<<", ";
    q.push(root);

    while(!q.empty()){
        p=q.front();
        q.pop();
        if(p->left){
            cout<<p->left->data<<", ";
            q.push(p->left);
        }
        if(p->right){
            cout<<p->right->data<<", ";
            q.push(p->right);
        }
    }


}

int main() {
    Tree bt;
    bt.createTree();
    cout<<"preorder"<<endl;
    bt.preorder();
    cout<<"levelorder"<<endl;
    bt.levelOrder();
    return 0;
}