// #include<iostream>
// using namespace std;
// void fun(int n){
//     if(n>0){
//         fun(n-1);
//         cout<<n<<" ";
//     }
// }
// int main(){
//     int x=3;
//     fun(x);
//     return 0;
// }

// returning comnbiantion in solution
#include<iostream>
using namespace std;
int fun(int n){
    if(n>0){
        return fun(n-1)+n;
    }
    return 0;
}
int main(){
    int a=5;
    cout<<fun(a);
    return 0;
}