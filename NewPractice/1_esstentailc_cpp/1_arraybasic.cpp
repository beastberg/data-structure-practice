//example 1

// #include<iostream>
// using namespace std;

// int main(){
//     int A[5]={2,4,6,8,10};
//     for(int i=0;i<5;i++){
//         cout<<A[i]<<" ";
//     }    
//     return 0;
// }

// example 2

// #include<iostream>
// using namespace std;
// int main(){
//     int A[5];
//     A[0]=12;
//     A[1]=14;
//     A[2]=16;
//     cout<<"The size of array is "<<sizeof(A)<<endl;
//     cout<<A[1]<<endl;
//     return 0;
// }

//example 3

// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cout<<"please enter the size of array"<<endl;
//     cin>>n;

//     int a[n];
//     a[0]=1;
//     cout<<sizeof(a)<<endl;

//     int b[10]={2,3,4,5,6,7,8,9};
//     cout<<sizeof(b)<<endl;

//     cout<<b[8]<<endl;
//     cout<<b[9]<<endl;
//     cout<<b[10]<<endl;// this will garbage value

//     for(int i=0;i<10;i++){
//         cout<<b[i]<<endl;
//     }

//     for(int x:a){
//         cout<<x<<endl;
//     }

//     return 0;
// }

//example 4

// #include<iostream>
// using namespace std;
// int main(){
//     int a[]={2,4};

//     for(int x:a){ // this is a for each loop
//         cout<<x<<endl;
//     }

//     int A[10]={2,3};
//     cout<<A[3]<<endl;
//     return 0;
// }