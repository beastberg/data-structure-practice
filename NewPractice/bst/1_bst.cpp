// #include<iostream>
// using namespace std;

// class Node{
//     public:
//     Node* left;
//     int data;
//     Node* right;
// };

// class BST{
//     private:
//     Node* root;

//     public:
//     BST(){root=nullptr;}
//     Node* getRoot(){return root;}
//     void Insert(int key);
//     void Inorder(Node* p);
//     Node* Search(int key);

// };

// void BST::Insert(int key){
//     Node* t=root;
//     Node* p;
//     Node* r;

//     if(root==nullptr){
//         p=new Node;
//         p->data=key;
//         p->left=nullptr;
//         p->right=nullptr;
//         root=p;
//         return;
//     }

//     while(t!=nullptr){
//         r=t;
//         if(key<t->data){
//             t=t->left;
//         }
//         else if(key>t->data){
//             t=t->right;
//         }
//         else{
//             return ;
//         }
//     }

//     p=new Node;
//     p->data=key;
//     p->left=nullptr;
//     p->right=nullptr;

//     if(key<r->data){
//         r->left=p;
//     }
//     else{
//         r->right=p;
//     }

//     //now t points at null
// }

// void BST::Inorder(Node* p){
//     if(p){
//         Inorder(p->left);
//         cout<<p->data<<" "<<flush;
//         Inorder(p->right);
//     }
// } 

// Node* BST:: Search(int key){
//     Node* t=root;
//     while(t!=nullptr){
//         if(key==t->data){
//             return t;
//         }
//         else if(key<t->data){
//             t=t->left;
//         }
//         else{
//             t=t->right;
//         }
//     }
//     return nullptr;
// }
// int main(){
//       BST bst;
 
//     // Insert
//     bst.Insert(10);
//     bst.Insert(5);
//     bst.Insert(20);
//     bst.Insert(8);
//     bst.Insert(30);
 
//     // Inorder traversal
//     bst.Inorder(bst.getRoot());
//     cout << endl;
 
//     // Search
//     Node* temp = bst.Search(30);
//     if (temp != nullptr){
//         cout << temp->data << endl;
//     } else {
//         cout << "Element not found" << endl;
//     }
 
//     return 0;
// }

#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
};

class BST{
    private:
    Node* root;
    public:
    BST(){root=nullptr;}
    void Insert(int key);
    Node* Search(int key);
    void  inorder(Node *p);
    Node* getRoot(){ return root;}

};
void BST::Insert(int key){
    Node* p;
    Node* t =root;
    Node* r;
    if(t==nullptr){
        p=new Node;
        p->data=key;
        p->left=nullptr;
        p->right=nullptr;
        root=p;
        return;
    }

    while(t!=nullptr){
        r=t;
        if(key==t->data)
            return;
        else if(key<t->data)
            t=t->left;
        else
            t=t->right;
    }

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

void BST::inorder(Node* p){
    if(p){
        inorder(p->left);
        cout<<p->data<<" ";
        inorder(p->right);
    }
}

Node* BST::Search(int key){
 Node* t=root;
 
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
int main(){

    BST bst;
    bst.Insert(10);
    bst.Insert(5);
    bst.Insert(20);
    bst.Insert(8);
    bst.Insert(30);

    bst.inorder(bst.getRoot());
    cout<<endl;
    cout<<"type a element to be searched"<<endl;
    // int x;
    // cin>>x;

    Node* t= bst.Search(6);
    if(t!=nullptr)
        cout<<"t->data"<<endl;
    else
        cout<<"didn,t find the element"<<endl;
    

    return 0;
}

