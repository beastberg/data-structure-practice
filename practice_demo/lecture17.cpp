// #include <iostream>
// using namespace std;

// struct rectangle{
// int length;
// int breadth;
// };

// int area (struct rectangle &r1){
//     r1.length++;
//     return r1.length*r1.breadth;

// }

// void changeLength(struct rectangle *p,int len){
//     p->length=len;
//     cout<<p->length;
// }

// int main() {
//     struct rectangle r={9,20};
//     cout<<area(r)<<endl;

//     changeLength(&r,20);

//     return 0;
// }

//example

// #include <iostream>
// using namespace std;

// struct rectangle{
//     int length;
//     int breadth;
// };

// struct rectangle *fun(){
//     struct rectangle *p;
//     p=new rectangle;
//     p->length=10;
//     p->breadth=5;

//     return p;
// }
// int main() {

//     struct rectangle *ptr=fun();
//     cout<<"length "<<ptr->length<<endl;
//     cout<<"breadth "<<ptr->breadth<<endl;
    
//     return 0;
// }


//structure and function

#include <iostream>
using namespace std;

struct rectangle{
    int length;
    int breadth;
};

void initialise   (struct rectangle *r,int l ,int b){
    r->length=l;
    r->breadth=b;
}
int area(struct rectangle r1){
return r1.length*r1.breadth;
}

void changeLength(struct rectangle *r,int len){
    r->length=len;
}
int main() {
    struct rectangle r;
    initialise(&r,10,20);
    cout<<area(r);
    changeLength(&r,20);


    return 0;
}

