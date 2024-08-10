#include<iostream>
using namespace std;

struct Array{
    int A[10];
    int size;
};
// MAX - Given an array (either unsorted or sorted), finds the max element


void FindDup(struct Array arr){
    int lastDuplicate=0;
    for(int i=0;i<arr.size-1;i++){
        if(arr.A[i]==arr.A[i+1]  && arr.A[i]!=lastDuplicate){
            cout<<arr.A[i]<<" ";
            lastDuplicate=arr.A[i];
        }
    }
    cout<<endl;
}



int main(){
      struct Array arr = {{1,2,2,2,3,3,3,4,5,6}, 10};
    
      FindDup(arr);
    
    return 0;
}