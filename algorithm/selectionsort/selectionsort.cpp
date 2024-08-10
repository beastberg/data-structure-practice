#include<iostream>
using namespace std;
void swap(int *x,int *y){
   int temp =*x;
   *x=*y;
   *y=temp;
}

void selectionSort(int A[],int n){
 for(int i=0;i<n-1;i++){
       int j=i;
       int k=i;

       while(j<n){
        if(A[j]<A[k])
           k=j;
        j++;
       }
    swap(&A[i],&A[k]);
 }
}
int main(){
    int A[]={3,7,9,10,6,5,12,4,11,2};
    int n=10;
    selectionSort(A,n);

    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}