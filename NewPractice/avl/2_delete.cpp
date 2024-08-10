#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    int bf;
    Node* left;
    Node* right;
    Node():data(0),bf(0),left(nullptr),right(nullptr){}
    Node(int val):data(val),bf(0),left(nullptr),right(nullptr){}
};

class AVL{
    private:
    Node* root;
    public:

    AVL():root(nullptr){}

    Node*  InsertNode(Node* p,int key);
    void   Insert(int key);

    Node*  DeleteNode(Node* p,int key);
    void   Delete(int key);

    void   Inorder(){Inorder(root);}
    void   Inorder(Node* p);

    Node*  llRotation(Node* p);
    Node*  rrRotation(Node* p);
    Node*  lrRotation(Node* p);
    Node*  rlRotation(Node* p);

    int    Height(Node* p);
    Node*  InPre(Node* p);
    Node*  InSucc(Node* p);
    Node*  Search(int key);
    bool   ValidateAVL(Node* p);
    bool   IsBalanced(Node* p);
    Node*  Root(){return root;}



};

void AVL::Inorder(Node* p){
    if(p){
        Inorder(p->left);
        cout<<p->data<<" ";
        Inorder(p->right);
    }
}

Node* AVL::Search(int key){
    Node* t=root;
    while(t!=nullptr){
        if(t->data==key)
            return t;
        else if(key<t->data)
            t=t->left;
        else 
            t=t->right;
    }
    return nullptr;
}

void AVL::Insert(int key){
    root=InsertNode(root,key);
}

void AVL::Delete(int key){
    root=DeleteNode(root,key);
}

Node* AVL::InPre(Node* p){
    while(p && p->right){
        p=p->right;
    }
    return p;
}

Node* AVL::InSucc(Node* p){
    while(p && p->left){
        p=p->left;
    }
    return p;
}

int AVL::Height(Node* p){
    if(p){
        int x=0,y=0;
        x=Height(p->left);
        y=Height(p->right);

        return x>y?x+1:y+1;
    }
    return 0;
}

Node* AVL:: llRotation(Node* p){
    int lbf,rbf; // left balancing factor
    Node* pl=p->left;

    pl->bf=0;
    p->left=pl->right;
    pl->right=p;

    lbf=Height(p->left)+1;
    rbf=Height(p->right)+1;
    p->bf=lbf-rbf;

    if(p==root)
        root=pl;
    
    return pl;
}

Node* AVL::rrRotation(Node* p){
    int lbf,rbf;
    Node* pr=p->right;

    pr->bf=0;
    p->right=pr->left;
    pr->left=p;
    
    lbf=Height(p->left)+1;
    rbf=Height(p->right)+1;
    p->bf=lbf-rbf;

    if(p==root)
       root=pr;
    
    return pr;
}

Node* AVL::lrRotation(Node* p){
    
    Node* pl=p->left;
    Node* plr=pl->right;
   
    plr->bf=0;
    p->left=plr->right;
    pl->right=plr->left;
    plr->left=pl;
    plr->right=p;

    p->bf=(Height(p->left)+1)-(Height(p->right)+1);
    pl->bf=(Height(pl->left)+1)-(Height(pl->right)+1);

    if(p==root)
      root=plr;

    return plr;
}

Node* AVL::rlRotation(Node* p){
   
    Node* pr=p->right;
    Node* prl=pr->left;

    prl->bf=0;
    pr->left=prl->left;
    p->right=prl->left;
    prl->left=p;
    prl->right=pr;
   
    p->bf=(Height(p->left)+1)-(Height(p->right)+1);
    pr->bf=(Height(pr->left)+1)-(Height(pr->right)+1);

   if(p==root)
       root=prl;

    return prl;
  
}

Node* AVL::InsertNode(Node* p,int key){
    Node* t;
    int lbf,rbf;
    if(p==nullptr){
        t=new Node(key);
        return t;
    }

    if(key<p->data)
        p->left=InsertNode(p->left,key);
    else if(key>p->data){
        p->right=InsertNode(p->right,key);
    }
    
    p->bf=(Height(p->left)+1)-(Height(p->right)+1);
   

    if(p->bf==2 && p->left->bf==1)
        return llRotation(p);
    
    if(p->bf==2 && p->left->bf==-1)
        return lrRotation(p);
    
    if(p->bf==-2 && p->right->bf==-1)
        return  rrRotation(p);

    if(p->bf==-2&& p->right->bf==1)
        return rlRotation(p);

    return p;


}

Node* AVL::DeleteNode(Node* p,int key){
    Node *q;
    if(p==nullptr)
        return nullptr;
    if(p->left==nullptr && p->right==nullptr){
        if(p==root)
           root=nullptr;
        delete p;
        return nullptr;
    }
    if(key<p->data)
        p->left=DeleteNode(p->left,key);
    else if(key>p->data)
        p->right=DeleteNode(p->right,key);

    else{
        if((p->left && Height(p->left))>(p->right && Height(p->right))){
            q=InPre(p->left);
            p->data=q->data;
            p->left=DeleteNode(p->left,p->data);
        }
        else{
            q=InSucc(p->right);
            p->data=q->data;
            p->right=DeleteNode(p->right,p->data);
        }
    }

    p->bf=(Height(p->left)+1)-(Height(p->right)+1);
    
    if(p->bf==2 && p->left->bf==1)
        return llRotation(p);
    if(p->bf==2 && p->left->bf==-1)
        return lrRotation(p);
    if(p->bf==-2 && p->left->bf==1)
        return rlRotation(p);
    if(p->bf==-2 && p->left->bf==-1)
        return rrRotation(p);

    return p;
}

bool AVL::IsBalanced(Node* p){
    if(p == nullptr) return true;
    int leftHeight = Height(p->left);
    int rightHeight = Height(p->right);
    return abs(leftHeight - rightHeight) <= 1 && IsBalanced(p->left) && IsBalanced(p->right);
}

bool AVL::ValidateAVL(Node* p){
    if(p == nullptr) return true;
    int balanceFactor = Height(p->left) - Height(p->right);
    return abs(balanceFactor) <= 1 && ValidateAVL(p->left) && ValidateAVL(p->right);
}


int main(){

    AVL avl;
    avl.Insert(30);
    avl.Insert(40);
    avl.Insert(50);
    avl.Insert(10);
    avl.Insert(5);
    avl.Insert(35);

    cout << "Inorder Traversal: ";
    avl.Inorder();
    cout << endl;

    cout << "Is Balanced: " << (avl.IsBalanced(avl.Root()) ? "Yes" : "No") << endl;
    cout << "Validate AVL: " << (avl.ValidateAVL(avl.Root()) ? "Yes" : "No") << endl;

    avl.Delete(10);
    avl.Delete(30);

    cout << "Inorder Traversal after Deletion: ";
    avl.Inorder();
    cout << endl;

    cout << "Is Balanced: " << (avl.IsBalanced(avl.Root()) ? "Yes" : "No") << endl;
    cout << "Validate AVL: " << (avl.ValidateAVL(avl.Root()) ? "Yes" : "No") << endl;

    return 0;
}