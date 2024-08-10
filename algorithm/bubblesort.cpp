#include<iostream>
using namespace std;

void swap(int *x,int*y){
  int temp=*x;
  *x=*y;
  *y=temp;
}
void bubbleSort(int A[],int n){
    int flag;// this is done to ake it more adaptive;
    for(int i=0;i<n-1;i++){
        flag=0;
        for(int j=0;j<n-1-i;j++){
            if(A[j]>A[j+1]){
                swap(&A[j],&A[j+1]);
                flag=1;
            }
        }
           if (flag == 0) { // If no swaps were made, the array is already sorted
            break;
        }
    }

 

}
int main(){
    int A[]={8,5,7,3,2};
    bubbleSort(A,5);
    for(int i=0;i<5;i++){
        cout<<A[i];
    }
    return 0;
}