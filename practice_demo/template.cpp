// #include <iostream>
// using namespace std;

// class rectangle{
//     private:
// int length;
// int breadth;

// public:

// rectangle(){length,breadth=1;}
// rectangle(int l,int b);//parameterised constructor
// int area();
// int perimeter();
// int getLength(){
//     return length;
// }
// void setLength(int l){
// length=l;
// }
// ~rectangle();// this is deconstructor
// };
// // return_type class_name :: fucntion (){ }
// rectangle::rectangle(int l,int b){
//     length=l;
//     breadth=b;
// }
// int rectangle::area(){
//     return length* breadth;
// }

// int rectangle::perimeter(){
//     return 2*(length+breadth);
// }
// rectangle::~rectangle(){}


// int main() {
//     rectangle r(10,5);
//     cout<<r.area()<<endl;
//     cout<<r.perimeter()<<endl;
//     r.setLength(20);
//     cout<<r.getLength()<<endl;
//     return 0;
// }

// template class in  c++

#include <iostream>
using namespace std;

template <class T>
class arithmetic{
    private:
    T a ;
    T b;
    public:
    arithmetic(T a,T b); // this is the constructor
    T add();
    T sub();
};

template <class T>
arithmetic<T>:: arithmetic(T a, T b){
    this ->a =a;
    this->b=b;

}

template <class T>
T arithmetic<T>:: add(){
    T c;
    c=a+b;
    return c;
}

template <class T>
T arithmetic<T>::sub(){
    T c;
    c=a-b;
    return c;
}


int main() {
    arithmetic <int > arith(10,5);
    cout<<arith.add()<<endl;
    cout<<arith.sub()<<endl;
    return 0;
}