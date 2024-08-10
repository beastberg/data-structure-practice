#include <iostream>
#include <math.h>
using namespace std;

struct Node{
    struct Node *left;
    int data;
    int bf;
    struct Node *right;
}*root=nullptr; // THIS IS  A WAY TO CREATE GLOBAL POINTER IN C

int height(struct Node *p){
    int x=0,y=0;
    if(!p)
       return 0;
    x=height(p->left);
    y=height(p->right);
    return x>y?x+1:y+1;
}

void Insert(int key){
    struct Node *t=root;
    struct Node *r=nullptr,*p;
    if(root==nullptr){
        p=new Node;
        p->data=key;
        p->bf=0;
        p->left=p->right=nullptr;
        root=p;
        return;
    }

    while(t!=nullptr){
        r=t;// this is done to maintain a previous node pointer
        if(key<t->data)
            t=t->left;
        else if(key>t->data)
             t=t->right;
        else
            return ;
    }
    p=new Node;
    p->data=key;
    p->left=p->right=nullptr;

    if(key<r->data)
       r->left=p;
    else 
       r->right=p;
}

struct Node * llRotation(struct Node *p){
  int lbf,rbf;
  struct Node *pl=p->left;
  pl->bf=0;
  p->left=pl->right;
  pl->right=p;
  lbf=height(p->left)+1;
  rbf=height(p->right)+1;
  if(p==root)
    root=pl;
  return pl;

}

struct Node *lrRotation(struct Node *p){
    int lbf,rbf;
    struct Node *pl=p->left;
    struct Node *plr=pl->right;
    plr->bf=0;
    p->left=plr->right;
    pl->right=plr->left;

    plr->left=pl;
    plr->right=p;
 
   lbf=height(p->left)+1;
   rbf=height(p->right)+1;
   p->bf=lbf-rbf;

   lbf=height(pl->left)+1;
   rbf=height(pl->right)+1;

   pl->bf=lbf-rbf;
   if(p==root)
       root=plr;
    
   return plr;


}

struct Node *rrRotation(struct Node *p){
    int lbf,rbf;
    struct Node *pr=p->right;
    pr->bf=0;
    p->right=pr->left;
    pr->left=p;

    lbf=height(p->left)+1;
    rbf=height(p->right)+1;

    p->bf=lbf-rbf;
    if(p==root)
       root=pr;
    return pr;

}

struct Node *rlRotation(struct Node *p){
    int lbf,rbf;
    struct Node *pr=p->right;
    struct Node *prl=pr->left;

    prl->bf=0;

    p->right=prl->left;
    pr->left=prl->right;

    prl->right=pr;
    prl->left=p;
    
    lbf=height(p->left)+1;
    rbf=height(p->right)+1;
    p->bf=lbf-rbf;

    lbf=height(pr->left)+1;
    rbf=height(pr->right)+1;

    pr->bf=lbf-rbf;
    if(p==root)
      root=prl;
    return prl;


}

struct Node *rInsert(struct Node *p,int key){
    struct Node *t;
    int lbf,rbf;
    if(p==nullptr){
        t=new Node;
        t->data=key;
        t->bf=0;
        t->left=t->right=nullptr;
        return t;
    }
    if(key<p->data)
      p->left=rInsert(p->left,key);
    else if(key>p->data)
      p->right=rInsert(p->right,key);
    
    lbf=height(p->left)+1;
    rbf=height(p->right)+1;
    p->bf=lbf-rbf;

    if(p->bf==2 && p->left->bf==1)
       return llRotation(p);
    if(p->bf==2 && p->left->bf==-1)
       return lrRotation(p);
    if(p->bf==-2 && p->right->bf==-1)
       return rrRotation(p);
    if(p->bf==-2 && p->right->bf==1)
       return rlRotation(p);
    
    return p;

}
void Inorder(struct Node *p){
    if(p){
        Inorder(p->left);
        cout<<" "<<p->data;
        Inorder(p->right);
    }
}

struct Node * search(int key){
    struct Node *t=root;
    while(t!=NULL){
        if(key==t->data)
           return t;
        else if(key<t->data){
            t=t->left;
        }
        else 
            t=t->right;
    }
    return nullptr;
}
int main() {

    struct Node * temp;
    Insert(30);
    rInsert(root,50);
    rInsert(root,40);
    rInsert(root,20);
    rInsert(root,10);
    rInsert(root,42);
    rInsert(root,46);

    Inorder(root);
    cout<<endl;

    temp = search(2);
    if(temp!=nullptr)
       cout<<"eleemnt found is "<<temp->data;
    else 
       cout<<"element is not found";

    return 0;
} 