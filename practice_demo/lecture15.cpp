//array is alaways passed as a pointer 
//we can  modifiy array
// modification is always done by address


// #include <iostream>
// using namespace std;

// void fun(int A[],int n){
//     int i;
//     for(int i=0;i<n;i++){
//         cout<<A[i]<<" ";
//     }
// }

// int main() {
//     int A[5]={1,2,3,4,5};
//     fun(A,5);// this ts the method call for the function
//     return 0;
// }


// #include <iostream>
// using namespace std;

// int* fun(int n){
//     int *p;
//     p=new int[n];
//     return p;
// }
// int main() {
//     int *a;
//     a=fun(5);
//     for(int i=0;i<5;i++){ // this will garbage value
//         cout<<a[i]<<" ";
//     }
//     return 0;
// }

//next exp

#include <iostream>
using namespace std;

int * fun(int size){
    int *p;
    p=new int[size];
    for(int i=0;i<size;i++){
        p[i]=i+1;
    }

    return p;
}

int main() {
    int *A,sz=5;
    A=fun(sz);
    for(int i=0;i<sz;i++){
        cout<<A[i]<<" ";
    }
    return 0;
}