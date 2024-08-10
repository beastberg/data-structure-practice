#include<iostream>
using namespace std;

struct Matrix{
    int *A;
    int n;
};
void Set(struct Matrix *m,int i,int j,int x){
    if(i>=j)
       //m->A[i*(i-1)/2+j-1]=x; for row major mapping
       m->A[m->n*(j-1)+(j-2)*(j-1)/2 + i-j]=x; //fro column major

}
int Get(struct Matrix m,int i,int j){
    if(i>=j)
    // return m.A[i*(i-1)/2+j-1] for row major
        return m.A[m.n*(j-1)+(j-2)*(j-1)/2+i-j]; // fro column major mapping
    return 0;
}

void Display(struct Matrix m){
    for(int i=1;i<=m.n;i++){
        for(int j=1;j<=m.n;j++){
            if(i==j)
            //cout<<m.A[i*(i-1)/2+j-1] for row mapping
                cout<<m.A[m.n*(j-1)+(j-2)*(j-1)/2+i-j]<<" ";
            else
                 cout<<"0 ";
            
        }
        cout<<endl;
    }
}


int main(){
    struct Matrix m;
    int x;

    cout<<"Please enter the dimension "<<endl;
    cin>>m.n;

    m.A=new int[(m.n)*(m.n+1)/2];
    cout<<"Enter all element"<<endl;
    for(int i=1;i<=m.n;i++){
        for(int j=1;j<m.n;j++){
            cin >> x;
            Set(&m,i,j,x);
        }
    }
    cout<<endl;
    Display(m);

    return 0;
}