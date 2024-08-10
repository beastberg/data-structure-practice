#include<iostream>
using namespace std;

 class LowerTriangular{
    private:
    int *A;
    int n;

    public:
        LowerTriangular(){
            n=2;
            A=new int[n*(n+1)/2];
        }
        LowerTriangular(int n){
            this->n=n;
            A=new int[n*(n+1)/2];
        }
        ~LowerTriangular(){
            delete []A;
        }
        void Set(int i,int j,int x);
        int Get(int i,int j);
        void Display();

 };

 void LowerTriangular::Set(int i ,int j,int x){
    if(i>=j)
          //A[i*(i-1)/2+j-1]=x;
          A[n*(j-1)-(j-2)*(j-1)/2+i-j]=x;
 }

 int LowerTriangular::Get(int i,int j){
    if(i>=j)
        //return A[i*(i-1)/2+j-1]
        return A[n*(j-1)-(j-2)*(j+1)/2+i-j];
    else
         return 0;
 }

 void LowerTriangular::Display(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            // if(i==j) cout<<A[i*(i-1)/2+j-1]<" ";
            if(i==j) cout<<A[n*(j-1)-(j-2)*(j-1)/2+i-j]<<" ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
 }
int main(){
    
    int d;
    cout<<"enter the dimension: ";
    cin>>d;

    LowerTriangular lt(d);

    int x;
    cout<<"enter all element "<<endl;

    for(int i=1;i<=d;i++){
        for(int j=1;j<=d;j++){
            cin>>x;
            lt.Set(i,j,x);
        }
    }
    cout << endl;
    
    lt.Display();

    return 0;
}