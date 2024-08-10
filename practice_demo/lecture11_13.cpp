// #include <iostream>
// using namespace std;

// // return_type fun_name(variable_type parameter){
//     //return x
// //}

// int add(int a,int b){ 
//     int c;
//     return c=a+b;

// };

// int main() {
//     int x,y,z;
//     x=10;
//     y=5;
//     z=add(x,y);//actual parameter
//     cout<<z;
//     return 0;
// }


// this is second experiment
// #include <iostream>
// using namespace std;

// void swap(int x,int y){
//     int temp=x;
//     x=y;
//     y=temp;
// }
// void swap1(int *x,int *y){

//  int temp=*x;
//  *x=*y;
//  *y=temp;

// }
// void swap2(int &x,int &y){
//     int temp =x;
//     x=y;
//     y=temp;
// }
// int main() {

//     int a,b;
//     a=10;
//     b=20;
//     swap(a,b);
//     cout<<a<<" "<<b<<" this is noraml function "<<endl;
//     swap1(&a,&b);
//     cout<<a<<" "<<b<<" this is by address"<<endl;
//     swap2(a,b);
//     cout<<a<<" "<<b<<" this is by reference "<<endl;
    
//     return 0;
// } 

#include <iostream>
using namespace std;
 
void add(int a,int b){
    cout<<a++<<" ";
    cout<<b++;
}
void add1(int *a,int *b){
    ++*a;
    ++*b;
    
}

int main() {

    int x=10;int y=10;
    cout<<x << " "<<y<<endl;
    add(x,y);
    cout<<endl;

    add1(&x,&y);
    cout<<x<<y;


    
    return 0;
}