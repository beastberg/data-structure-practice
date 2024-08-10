// #include <iostream>
// using namespace std;

// struct rectangle{
//      int length;
//      int breadth;
// };
// int main() {
//     struct rectangle r={10,20};
//     struct rectangle *p = &r;
//     (*p).length=15;
//     (*p).breadth=30;
//     cout<<r.length *r.breadth;




//     return 0;
// }

//exp2

// #include <iostream>
// using namespace std;

// struct rectangle{
//     int length;
//     int breadth;
// };


// int main() {
//     struct rectangle *p;
//     p=new rectangle;
//     p->length=10;
//     p->breadth=20;

//     cout<<p->length *p->breadth;

//     return 0;
// }

#include <iostream>
using namespace std;

struct rectangle{
    int length;
    int breadth;
};

int main() {
 struct rectangle r={10,20};
 r.length=10;
 r.breadth=20;

 struct rectangle *p=&r;
 cout<<p->length;
 cout<<p->breadth;


    return 0;
}