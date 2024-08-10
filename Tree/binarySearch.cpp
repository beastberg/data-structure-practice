#include <iostream>
using namespace std;

class Node{
    public:
    Node * left;
    int data;
    Node * right;
};
class BST{
    private:
    Node *root;
    public:
    BST(){root=nullptr;}
    void Insert(int Key);
    void Inorder(Node *p);
    Node* search(int key);
    Node *getRoot(){return root;}
};
void BST::Insert(int key){
    Node *t=root;
    Node *p;
    Node *r;

    //if root is empty
    if(root==nullptr){
        p=new Node;
        p->data=key;
        p->left=nullptr;
        p->right=nullptr;
        root=p;
        return;
    }
    while(t!=nullptr){
        r=t;
        if(key<t->data){
            t=t->left;
        }else if(key>t->data){
            t=t->right;
        }else{
            return;
        }
    }
    //now t pointat null and r point at insert location
    p=new Node;
    p->data=key;
    p->left=nullptr;
    p->right=nullptr;

    if(key<r->data){
        r->left=p;
    }
    else{
        r->right=p;
    }
}
void BST ::Inorder(Node*p){
    if(p){
        Inorder(p->left);
        cout<<p->data<<" "<<endl;
        Inorder(p->right);
    }
}

Node* BST::search(int key){
    Node* t=root;
    while(t!=nullptr){
        if(key==t->data){
            return t;
        }else if(key<t->data){
            t=t->left;
        }
        else{
            t=t->right;
        }
    }
    return nullptr;
}
Node * BST :: rSearch(Node *p,int key){
    if(p==nullptr){
        return nullptr;
    }
    if(key==p->data){
        return p;
    }
    else if(key<p->data){
        return rSearch(p->left,key);
    }
    else{
        return rSearch(p->right,key);
    }
}
Node * BST::Delete(Node *p,int key){
    Node *q;
    if(p==nullptr){
        return nullptr;
    }
    if(p->left==nullptr && p->right==nullptr){
        if(p==root){
            root=nullptr;
        }
        delete p;
        return nullptr;
    }
    if(key<p->data){
        p->left=delete(p->left,key);
    }
    else if(key>p->data){
        p->right=delete(p->right,key);        
    }
    else{
        if(height(p->left)>height(p->right)){
            q=InPre(p->left);
            p->data=q->data;
            p->left=delete(p->left,q->data);
        }
        else{
            q=InSucc(p->right);
            p->data=q->data;
            p->right=delete(p->right,q->data);
        }
    }
    return p;
}

int BST:: height(Node *p){
    int x;
    int y;
    if(p==nullptr){
        return 0;
    }
    x=height(p->left);
    y=height(p->right);
    return x>y?x+1:y+1;
}

Node *BST ::Inpre(Node *p){
    while(p && p->right !=nullptr){
        p=p->right;
    }
    return p;
}
Node *BST ::InSucc(Node *p){
    while(p && p->left !=nullptr){
        p=p->left;
    }
    return p;
}
void BST ::createFromPreorder(int *pre,int n){
    //create a node
    int i=0;
    root=new Node;
    root->data=pre[i++];
    root->left=nullptr;
    root->right=nullptr;
    //iterative step
    Node * t;
    Node *p=root;
    stack<Node *>stk;
    while(i<n){
        //l
    }
}

int main() {

     BST bst;
 
    // Insert
    bst.Insert(10);
    bst.Insert(5);
    bst.Insert(20);
    bst.Insert(8);
    bst.Insert(30);
 
    // Inorder traversal
    bst.Inorder(bst.getRoot());
    cout << endl;
 
    // Search
    Node* temp = bst.search(2);
    if (temp != nullptr){
        cout << temp->data << endl;
    } else {
        cout << "Element not found" << endl;
    }
 
    return 0;

}