// #include <iostream>
// using namespace std;

// int main() {
//     int a =10;
//     int *p;
//     p=&a;
//     cout<<a<<endl;
//     cout<<p<<endl;// this will give the address the a 
//     cout<<*p<<endl; // deferencing 
//     cout<<&a<<endl;

//     if(p=&a){
//         cout<<"sahi hai";
//     }
//     return 0;
// }


//second exp

// #include <iostream>
// using namespace std;

// int main() {
//     int *p;
//     p=new int[5];
//     p[0]=1;
//     p[1]=2;
//     p[3]=3;
//     p[4]=4;

//     for(int i=0;i<5;i++){
//         cout<<p[i]<<" ";
//     }

//     return 0;
// }


//this is third exp

// #include <iostream>
// using namespace std;

// int main(){

//     int A[]={1,2,3,4,5};
//     int *p;

//     p=&A[0];//this can also be written as p=a;

//     cout<<&A[0]<<endl;

//     cout<<p<<endl;

//     cout<<*p;

//     cout<<endl;

//     for(int i=0;i<5;i++){
//         cout<<p[i];
//     }

//     return 0;
// }

#include <iostream>
using namespace std;

int main() {
    int a=10;
    int &r=a;
    cout<<a;
    r++;
    cout<<a;

    return 0;
}