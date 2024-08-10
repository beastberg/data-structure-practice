#include<iostream>
using namespace std;
// diagonal Matrix in c

struct Matrix{
    int *A; // this will point to a id array in heap
    int n;// they are square means we need value for them
};

void Set(struct Matrix *m,int i,int j,int x){
    if(i==j){
        m->A[i-1]=x;
    }
}
int Get(struct Matrix m,int i,int j){
    if(i==j)
       return m.A[i-1];
    else
       return 0;
}

void Display(struct Matrix m){
    for(int i=0;i<m.n;i++){
        for(int j=0;j<m.n;j++){
            if(i==j)
                cout<<m.A[i];
            else 
                cout<<"0";
                
        }
        cout<<endl;
    }
}
int main(){
    struct Matrix m;
    m.n=4;
    m.A=new int[m.n];
    Set(&m,1,1,1);
    Set(&m,2,2,9);
    Set(&m,3,3,9);
    Set(&m,4,4,4);
    cout<<"The value from get function : "<<Get(m,3,3);
    Display(m);
    free(m.A);
    return 0;
}