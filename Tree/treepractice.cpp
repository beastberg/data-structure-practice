#include <iostream>
#include <queue>
#include <stack>
using namespace std;
class Node{
    public:
    Node * left;
    int data;
    Node * right;
    Node(){};
    Node(int data);
};

Node::Node(int data){
    left=nullptr;
    this->data=data;
    right=nullptr;
}

class Tree{
    private:
    Node * root;
    public:
    Tree();
    void createTree();
    void preOrder(Node * p);
    void preOrder(){
        preOrder(root);
    }
     void inOrder(Node * p);
    void inOrder(){
        inOrder(root);
    }
     void postOrder(Node * p);
    void postOrder(){
        postOrder(root);
    }
     void levelOrder(Node * p);
    void levelOrder(){
        levelOrder(root);
    }

     int Height(Node *p);
    int Height(){
        Height(root);
    }
    int Sum(Node *p);
    int Sum(){
        Sum(root);
    }

    int degree2(Node *p);
    int degree2(){
        (root);
    }
    int count(Node *);
    int count(){
        count(root);
    }
    void iterativePreorder(Node *p);
    void iterativePreorder(){
        iterativePreorder(root);
    }
    
    void iterativeInorder(Node *p);
    void iterativeInorder(){
        iterativeInorder(root);
    }

    void iterativePostorder(Node *p);
    void iterativePostorder(){
        iterativePostorder(root);
    }
    Node * generateFromTraveral(int inorder[],int preorder[], int inStart,int inEnd);

};


Tree::Tree(){
    root=nullptr;
}
void Tree::createTree(){
    int x;
    cout<<"enter the value of root"<< endl;
    cin>>x;
    root=new Node;
    root->data=x;
    root->left=nullptr;
    root->right=nullptr;
    queue <Node *> q;
    q.push(root);
    while(!q.empty()){
        Node *p,*t;
        p = q.front();
        q.pop();
        int x;
        cout<<"enter left child of"<<p->data<<endl;
        cin>>x;
        if(x!=-1){
        t=new Node;
        t->data=x;
        t->left=nullptr;
        t->right=nullptr;
        p->left=t;
        q.push(t);
        }
        cout<<"enter right child of"<<p->data<<endl;
        cin>>x;
        if(x!=-1){
            t=new Node;
            t->data=x;
            t->left=t->right=nullptr;
            p->right=t;
            q.push(t);
        }
    }

}

void Tree :: preOrder(Node *p){
if(p){
cout<<p->data;
preOrder(p->left);
preOrder(p->right);
}
}
void Tree::inOrder(Node *p){
    if(p){
        inOrder(p->left);
        cout<<p->data;
        inOrder(p->right);
    }
}
void Tree::postOrder(Node *p){
    if(p){
        postOrder(p->left);
        postOrder(p->right);
        cout<<p->data;
    }
}


void Tree::levelOrder(Node *p){
    Node *t;
    queue<Node *>q;
    q.push(p);
    cout<<p->data;
    while(!q.empty()){
      t=q.front();
      q.pop();
      if(t->left){
        cout<<t->left->data;
        q.push(t->left);
      }
      if(t->right){
        cout<<t->right->data;
        q.push(t->right);
      }
    }
}
int Tree::Height(Node *p){
    int x,y;
    if(p){
        x=Height(p->left);
        y=Height(p->right);
        if(x>y){
            return x+1;
        }else{
            return y+1;
        }
    }
    return 0;
}

int Tree:: count(Node *p){
    int x;int y;
    if(p!=nullptr){
        x=count(p->left);
        y=count(p->right);
        return x+y+1;
    }
    return 0;
}
int Tree::Sum(Node *p){
    int x,y;
    if(p){
        x=Sum(p->left);
        y=Sum(p->right);
        return x +y + p->data;
    }
    return 0;
}
int Tree ::degree2(Node * p){
int x,y;
if(p!=nullptr){
    x=degree2(p->left);
    y=degree2(p->right);
    if(p->left && p->right){
        return x+y+1;
    }
    else{
        return x+y;
    }
}
return 0; 
}

void Tree::iterativePreorder(Node *p){
    stack<Node *>stk;
    while(p!=nullptr || stk.empty()){
        if(p!=nullptr){
            cout<<p->data<<" "<<endl;
            stk.push(p);
            p=p->left;
        }
        else{
            p=stk.top();
            stk.pop();
            p=p->right;
        }
    }cout<<endl;
}
void Tree::iterativeInorder(Node *p){
    stack<Node *>stk;
    while(p!=nullptr || stk.empty()){
        if(p!=nullptr){
            stk.emplace(p);
            p=p->left;
        }
        else{
            p=stk.top();
            stk.pop();
            cout<<p->data <<" "<<endl;
            p=p->right;
        }
    }
    cout<<endl;

}

void Tree ::iterativePostorder(Node *p){
    stack<long int>stk;
    long int temp;
    while(p!=nullptr || !stk.empty()){
        if(p!=nullptr){
            stk.push( int(p));
            p=p->left;
        }
        else{
            temp=stk.top();
            stk.pop();
            if(temp>0){
             stk.push(-1*temp);
             ((Node *)temp)->right;
            }
            else{
            cout<<((Node*)(-1*temp))->data;
            p=nullptr;
            }
        }
    }

}
int searchInorder (int inArray[],int inStart,int inEnd,int data ){
    for(int i=inStart;i<=inEnd;i++){
        if(inArray[i]== data){
            return i;
        }
    }
    return -1;
}

Node * Tree::generateFromTraveral(int *inorder,int *preorder,int inStart,int inEnd){
    static int preIndex =0;
    if(inStart >inEnd){
     return nullptr;  // if index of a i is greater than size -1    
    }
    Node * node =new Node(preorder[preIndex++]);
    if(inStart==inEnd){
        return node;
    }

    int splitIndex =searchInorder(inorder,inStart,inEnd,node->data);
    node->left=generateFromTraveral(inorder,preorder,inStart,splitIndex-1);
    node->right=generateFromTraveral(inorder,preorder,splitIndex+1,inEnd);

    return node;
    
}
int main() {

    
    Tree bt;
 
    int preorder[] = {8, 3, 12, 4, 9, 7, 5, 10, 6, 2};
    int inorder[] = {12, 9, 4, 7, 3, 8, 10, 5, 2, 6};
 
    int size = sizeof(inorder)/sizeof(inorder[0]);
 
    Node* T = bt.generateFromTraveral(inorder, preorder, 0, size-1);
 
    cout << "Preorder: " << flush;
    bt.preOrder(T);
    cout << endl;
 
    cout << "Inorder: " << flush;
    bt.inOrder(T);
    cout << endl;
 
    cout << "Height: " << bt.Height(T) << endl;
    cout << "Count: " << bt.count(T) << endl;
    cout << "Sum: " << bt.Sum(T) << endl;
    cout << "# of degree 2 nodes: " << bt.degree2(T) << endl;
    
    return 0;
}