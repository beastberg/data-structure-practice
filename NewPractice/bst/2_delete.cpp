

#include<iostream>
#include<stack>
#define MAX_INT 2147483647
using namespace std;
class Node{
    public:
    Node* left;
    int data;
    Node* right;
    Node(int val):data(val),left{nullptr},right{nullptr}{}
    Node():data(0),left{nullptr},right{nullptr}{}
};

class BST{
    private:
    Node* root;
    public:
    BST(){root=nullptr;};
    Node* Search(Node* t,int key);
    Node* Rsearch(Node* t,int key);
    void  Insert(int key);
    Node* Rinsert(Node*p,int key);
    int   height(Node *p);
    Node* Inpre(Node* p);
    Node* Insucc(Node* p);
    Node* Delete(Node* p,int key);
    void  createFromPreorder(int *pre,int n);
    void Inorder(Node* p);
    Node* getRoot( ){return root;}
};


Node* BST::Search(Node* t,int key){
while(t!=nullptr){
    if(key==t->data)
        return t;
    else if(key<t->data)
        t=t->left;
    else
        t=t->right;
}
return nullptr;
}

Node* BST::Rsearch(Node* t,int key){
    if(t==nullptr)
        return nullptr;
    if(t->data==key)
        return t;
    else if(key<t->data)
        return Rsearch(t->left, key);
    else
      return  Rsearch(t->right, key);
}

void BST::Insert(int key){
    Node* p;
    Node* r;
    Node* t=root;
    if(t==nullptr){
        t=new Node(key);
        root=t;
        return;
    }

    while(t!=nullptr){
        
        r=t;//this is called the previous pointer
        if(key==t->data)
            return;
        else if(key<t->data)
            t=t->left;
        else
            t=t->right;
        
    }

    p=new Node(key);
    if(p->data<r->data)
        r->left=p;
    else
        r->right=p;
}

Node* BST:: Rinsert(Node* p,int key){
    Node *t;
    if(p==nullptr){
      t=new Node(key);
      if(root==nullptr){
        root=t;
      }
      return t;
    }
    if(key<p->data)
      p->left=Rinsert(p->left,key);
    else if(key>p->data)
      p->right=Rinsert(p->right,key);
    
    return p;// to cover all path
}

int BST::height(Node* p){
    if(p){
        int x=0,y=0;
        x=height(p->left);
        y=height(p->right);
        
        return x>y?x+1:y+1;
    }
    return 0;
}

Node* BST:: Inpre(Node* p){
    while(p && p->right)
        p=p->right;
    return p;
}

Node* BST:: Insucc(Node* p){
    while(p && p->left)
        p=p->left;
    return p;
}
Node* BST :: Delete(Node* p,int key){
    Node* q;
    if(p==nullptr)
        return nullptr;
    
    if(!(p->left) && !(p->right)){
        if(p==root)
           root=nullptr;
        delete p;
        return nullptr;
    }

    if(key<p->data)
        p->left=Delete(p->left,key);
    else if(key>p->data)
        p->right=Delete(p->right,key);
    else{
        if(height(p->left)>height(p->right)){
                q=Inpre(p->left);
                p->data=q->data;
                p->left=Delete(p->left,q->data);
        }

        else{
            q=Insucc(p->right);
            p->data=q->data;
            p->right=Delete(p->right,q->data);
        }
    }
       
    return p;
        
}

void BST::createFromPreorder(int* pre,int n){
    //first create root NOde
    int i=0;
    root=new Node(pre[i++]);

    //iterative step
    Node* t;
    Node* p=root;
    stack <Node*> stk;
    while(i<n){
        if(pre[i]<p->data){
            t=new Node(pre[i++]);
            p->left=t;
            stk.push(p);
            p=t;
        }
        else{
            //right sub tree case
            if(pre[i]>p->data && pre[i]<(stk.empty()?MAX_INT:(stk.top())->data)){
                t=new Node(pre[i++]);
                p->right=t;
                p=t;
            }
            else{
                p=stk.top();
                stk.pop();
            }
        }
    }
}

void BST:: Inorder(Node* p){
    if(p){
        Inorder(p->left);
        cout<<p->data<<" ";
        Inorder(p->right);
    }

}




int main(){
    BST bst;
    int keys[] = {30, 20, 10, 40, 50}; // Example set of keys to insert
    int n = sizeof(keys) / sizeof(keys[0]); // Number of keys

    for (int i = 0; i < n; i++) {
        bst.Rinsert(bst.getRoot(), keys[i]);
    }

    bst.Inorder(bst.getRoot()); // To print and check if tree is created as expected
    cout << endl;
    bst.Delete(bst.getRoot(),40);
    bst.Inorder(bst.getRoot());
    return 0;
}