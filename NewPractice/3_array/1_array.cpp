// #include<iostream>
// using namespace std;
// int main(){
//     int A[]={2,4,6,8,10};
//     cout<<A[2]<<endl;
//     cout<<0[A]<<endl;
//     cout<<*(A)<<endl; ////deference the array 
//     return 0;
// }


// #include<iostream>
// using namespace std;
// int main(){
//     int A[5];
//     int *p;
//     p=new int[5];

//     p[0]=2; p[1]=4; p[2]=6; p[3]=8; p[4]=10;

//     int *q=new int[10];

//     for(int i=0;i<5;i++){
//         q[i]=p[i];
//     }
//     delete []p;
//     p=q;
//     q=nullptr;    

//     return 0;
// }

#include<iostream>
using namespace std;
int main(){
    
    int* A[3];
    A[0]=new int[4];
    A[1]=new int[4];
    A[2]=new int[4];

    A[1][3]=13;

    return 0;
}