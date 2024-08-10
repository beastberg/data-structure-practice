// #include<iostream>
// using namespace std;
// int fun(int n){
//     static int x=0;// x retain its value accros all its function call
//         if(n>0){
//         x++;
//         return fun(n-1)+x;
//     }
//     return 0;
// }
// int main(){
//     int a=5;
//     cout<<fun(a)<<endl;
//     return 0;
// }

// tail recursion
// in tail recursion the function call is the last statement
// #include<iostream>
// using namespace std;
// void fun(int n){
//     if(n>0){
//         cout<<n;
//         fun(n-1);
//     }
// }

// void fun1(int n){
//     while(n>0){
//         cout<<n;
//         n--;
//     }
// }
// int main(){
//     fun(3);
//     fun1(3);
//     return 0;
// }

// head recursion
//first statement is the function call

// #include<iostream>
// using namespace std;
// void fun(int n){
//     if(n>0){
//         fun(n-1);
//         cout<<n<<" ";
//     }
// }

// void fun1(int n){
//     int i=1;
//     while(i<=n){
//         cout<<i<<" ";
//         i++;
//     }
// }
// int main(){
//     fun(3);
//     cout<<endl;
//     fun1(3);
//     return 0;
// }

//tree recursion -> in this we have multiple function in a single scope

// #include<iostream>
// using namespace std;
// void fun(int n){
// if(n>0){
//     cout<<n<<" ";
//     fun(n-1);
//     fun(n-1);
// }
// }
// int main(){
//     fun(3);
//     return 0;
// }

//indirect recursion circular calls to each other multiple times

// #include<iostream>
// using namespace std;

// void fun_A(int n);// this is important (called forward declaration)
// void fun_B(int n);

// void fun_A(int n){
//     if(n>0){
//         cout<<n<<" ";
//         fun_B(n-1);
//     }
// }

// void fun_B(int n){
//     if(n>1){
//         cout<<n<<" ";
//         fun_A(n/2);
//     }
// }

// int main(){
//     fun_A(20);
//     return 0;
// }

// nested recursion
// recursive call takes recursive call as a parameter
// #include<iostream>
// using namespace std;
// int fun(int n){
//     if(n>100){
//         return n-10;
//     }
//     else 
//        return fun(fun(n+11));
// }
// int main(){
//     cout<<fun(95);
//     return 0;
// }

//sum of first n natural  number

// #include<iostream>
// using namespace std;
// int sum(int n){
//     if(n==0)
//        return 0;
//     else
//        return sum(n-1)+n;
// }
// int main(){

//     cout<<sum(3);
    
//     return 0;
// }

//factorial of a number

// #include<iostream>
// using namespace std;
// int fact(int n){
//     if(n==0){
//         return 1;
//     }
//     else 
//         return fact(n-1)*n;
// }
// int main(){
//     cout<<fact(5);
//     return 0;
// }


//power using recursion

#include<iostream>
using namespace std;

// int pow(int m,int n){
//     if(n==0){
//         return 1;
//     }
//     return  pow(m,n-1)*m;
// }

int power(int m,int n){
    if(n==0)
       return 1;
    if(n%2==0)
       return power(m*m,n/2);
    else
       return m*power(m*m,(n-1)/2);
}
int main(){
    //cout<<pow(2,5);
    cout<<power(2,5);
    
    return 0;
}