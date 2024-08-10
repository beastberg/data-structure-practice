//example 1
// #include<iostream>
// using namespace std;
// // create a structure

// struct rectangle{
//     int length;
//     int breadth;
// };
// int main(){
//   struct rectangle r={10,5};
//   //use dot operator to access member of struct
//   cout<<"the area of rectangle is "<<r.length * r.breadth<<" "<<endl;  
//     return 0;
// }

//example 2

// #include<iostream>
// using namespace std;
// struct student{
//     int roll;
//     string name;
//     string dept;
// };

// int main(){
//   struct  student s;
//   cout<<sizeof(s)<<endl;
//   s.dept='sce';
    
//     return 0;
// }

#include<iostream>
using namespace std;
struct card{
    int face;
    int shape;
    int color;
};
int main(){

    struct card deck[52]={{1,0,0}};
    cout<<deck[0].face<<endl;
    
    return 0;
}