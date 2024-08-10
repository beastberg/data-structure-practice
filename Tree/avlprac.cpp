#include <iostream>
#include <math.h>
using namespace std;

struct Node {
    struct Node *left;
    int data;
    int bf;
    struct Node *right;
}*root=nullptr;

int height(struct Node *p){
    int x=0,y=0;
    if(!p)
       return 0;
    x=height(p->left);
    y=height(p->right);
    return x>y? x+1:y+1;
}

void Insert(int key){
    struct Node *t=root;
    struct Node *r=nullptr,*p;

    if(root=nullptr){
        p=new Node;
        p->data=key;
        p->bf=0;
        p->left=p->right=NULL;
        return ;
    }
    while(t!=nullptr){
        r=t;
        if(key<t->data)
           t=t->left;
        else if(key>t->data)
           t=t->right;
        else 
            return;
    }
    p=new Node;
    p->data=key;
    p->left=p->right=nullptr;

    if(key<r->data)
       r->left=p;
    else 
       r->right=p;
}


struct Node *llRotation(struct Node *p){
    int lbf,rbf;
    struct Node *pl=p->left;
    pl->bf=0;
    p->left=pl->right;
    pl->right=p;
    lbf=height(p->left)+1;
    rbf=height(p->right)+1;
    p->bf=lbf-rbf;

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
    pr->bf;
    p->right=p->left;
    pr->left=p;
    lbf=height(p->left)+1;
    rbf=height(p->right)+1;
    p->bf=lbf-rbf;

    if(p==root)
       root=pr;
    return pr;
    
}


int main() {
    return 0;
}