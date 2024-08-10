#include<iostream>
using namespace std;
// assumptionn first element is already sorted
void InsertionSort(int A[],int n){
for(int i=1;i<n;i++){
    int j=i-1;
    int x=A[i];

    while(j>-1 && A[j]>x){
        A[j+1]=A[j];
        j--;
    }
    A[j+1]=x;
}
}
int main(){
    int A[]={8,5,7,3,2};
    InsertionSort(A,5);
    for(int i=0;i<5;i++){
        cout<<A[i];
    }
    return 0;
}