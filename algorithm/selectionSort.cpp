#include<iostream>
using namespace std;

void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
void selectionSort(int A[],int n){
    int i,j,k;
    for(int i=0;i<n-1;i++){
        for(int j=k=i;j<n;j++){
              if(A[j]<A[k])
                   k=j;
        }
        swap(A[i],A[k]);
    }
}
int main(){
    int A[]={8,5,7,3,2};
    selectionSort(A,5);
    for(int i=0;i<5;i++){
        cout<<A[i];
    }
    
    return 0;
}