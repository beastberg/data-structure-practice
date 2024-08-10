// #include<iostream>
// using namespace std;
// int main(){
//     int a=10;
//     int *p;
//     p=&a;

//     cout<<a<<endl;
//     cout<<p<<endl;
//     cout<<*p<<endl;
//     return 0;
// }

// referece

// #include<iostream>
// using namespace std;
// int main(){
//     int a=10;
//     int &r=a; // this is the refernece statement an alias
//     cout<<a<<endl;
//     a++;
//     cout<<r<<endl;
//     return 0;
// }

// pointer and array
//  #include<iostream>
//  using namespace std;
//  int main(){
//      int a[5]={2,4,6,8,10};

//     int *p;
//     p=a; // it means p is pointing to first address of the array
//     cout<<a<<endl;
//     cout<<&a[0]<<endl;
//     cout<<*p<<endl;// this deference the first index
//     for(int i=0;i<5;i++){
//         cout<<p[i]<<endl;
//     }

//     return 0;
// }

// size of pointer is independent of its data type

// #include<iostream>
// using namespace std;
// int main(){
//     int *p1;
//     float *f1;
//     cout<<sizeof(p1)<<endl;
//     cout<<sizeof(f1)<<endl;
//     return 0;
// }

// create memory in heap and deleteing it

// #include<iostream>
// using namespace std;
// int main(){
//     int *p;
//     p=new int[5]; //this will return the  address in heap

//     p[0]=11; p[1]=12; p[2]=13; p[3]=14; p[4]=15;
//     for(int i=0;i<5;i++){
//         cout<<p[i]<< " ";
//     }

//     delete []p;
//     return 0;
// }

// #include<iostream>
// using namespace std;
// int main(){
//     int a=10;
//     int &r=a;
//     int b=30;
//     r=b;
//     cout<<a<<" "<<b;
//     return 0;
// }

// pointer to the structure

// #include<iostream>
// using namespace std;
// class rectangle{
//     public:
//     int length;
//     int breadth;
//     rectangle(int l,int b){
//         this->length=l;
//         this->breadth=b;
//     }
// };
// int main(){
//     rectangle *p;
//     rectangle *r= new rectangle(10,5);
//     cout<<r->length*r->breadth<<" ";
//     p=r;
//     (*p).length=20;
//     cout<<r->length*r->breadth;

//     return 0;
// }

// function
// #include<iostream>
// using namespace std;
// int add(int a,int b){
//     int c;
//     c=a+b;
//     return c;
// }
// int main(){
//     int x,y,z;
//     x=10;
//     y=5;
//     z=add(x,y);
//     cout<<"the sum is "<<z;
//     return 0;
// }

// swap function
// #include<iostream>
// using namespace std;
// void swap(int *x,int *y){
//     int temp=*x;
//     *x=*y;
//     *y=temp;
// }
// int main(){
//     int a,b;
//     a=10;
//     b=20;
//     cout<<a<<" "<<b<<endl;
//     swap(&a,&b);
//     cout<<a<<" "<<b<<endl;
//     return 0;
// }

// swap by reference

// #include <iostream>
// using namespace std;
// void swap(int &x, int &y)
// {
//     int temp = x;
//     x = y;
//     y = temp;
// }
// int main()
// {
//     int a, b;
//     a = 10;
//     b = 20;
//     cout << a << " " << b << endl;
//     swap(a, b);
//     cout << a << " " << b << endl;

//     return 0;
// }

//passing array as an pointer   

// #include<iostream>
// using namespace std;
// void fun(int A[],int n){
//     for(int i=0;i<n;i++){
//         cout<<A[i]<<" ";
//     }
// }
// int main(){
//     int A[5]={2,4,6,8,10};
//     fun(A,5);
//     return 0;
// }

//function returning array
// #include<iostream>
// using namespace std;
// int* fun(int n){
//     int *p;
//     p=new int [n];
//     return p;
// }
// int main(){
//     int *A;
//     A=fun(5);
    
//     return 0;
// }


//structure as parameter
// #include<iostream>
// using namespace std;
// struct rectangle{
//     int length;
//     int breadth;
// };
// int area(struct rectangle &r){
//     r.length++;
//     return r.length*r.breadth;
// }
// int main(){
//     struct rectangle r={10,5};
//     cout<<area(r)<<endl;
//     return 0;
// }

// call by address
// #include<iostream>
// using namespace std;
// struct rectangle{
//     int length;
//     int breadth;
// };
// void changeLength(struct rectangle *p,int l){
//     p->length=l;
// }
// int main(){
//     struct rectangle r={10,5};
//     changeLength(&r,20);
//     cout<<r.length;
//     return 0;
// }


// #include<iostream>
// using namespace std;
// struct rectangle {
//     int length;
//     int breadth;
// };

// void fun(struct rectangle *rt){
//     rt->length=20;
//     cout<<"length"<<rt->length;
// }
// int main(){
//     struct rectangle r={10,5};
//     cout<<"length"<<r.length<<endl;
//     fun(&r);
    
//     return 0;
// }

// #include<iostream>
// using namespace std;
// template <class T> // THIS IS A GENERIC DATA TYPE
// class arithmatic{
//     private:
//     T a;
//     T b;
//     public:
//     arithmatic(T a,T b);
//     T add();
//     T sub();
// };
// template <class T>
// arithmatic <T>::arithmatic(T a,T b){
//     this->a=a;
//     this->b=b;
// }
// template<class T>
// T arithmatic<T>:: add(){
//     T c;
//     c=a+b;
//     return c;
// }
// template<class T>
// T arithmatic<T>:: sub(){
//     T c;
//     c=a-b;
//     return c;
// }
// int main(){
//  arithmatic<int> ar(10,5);
//  cout<<ar.add();
//  arithmatic<float> ar1(1.5,1.6);
//  cout<<ar1.add();   
//  return 0;
// }


// #include<iostream>
// using namespace std;
// template <class T>
// class arithmatic{
//     private:
//     T a;
//     T b;
//     public:
//     arithmatic(T a,T b);
//     T add();
//     T sub();
// };
// template<class T>
// arithmatic <T>:: arithmatic(T a, T b){
//     this->a =a;
//     this-> b=b;
// }
// template <class T>
// T arithmatic<T>::add(){
//     T c;
//     c=a+b;
//     return c;
// }
// template <class T>
// T arithmatic<T>::sub(){
//     T c;
//     c=a-b;
//     return c;
// }
// int main(){
//     arithmatic<int> arr(10,7);
//     cout<<arr.add();
    
//     return 0;
// }

// #include<iostream>
// using namespace std;
// struct rectangle{
//     int length;
//     int breadth;
// };
// struct rectangle * fun(){
//     struct rectangle *p;
//     p=new rectangle;
//     p->length=100;
//     p->breadth=50;
//     return p;
// }
// int main(){
//     struct rectangle *r;
//     r=fun();
//     cout<<"length is "<<r->length<<" breadth is "<<r->breadth;
//     return 0;
// }

// structure and function

// #include<iostream>
// using namespace std;
// struct rectangle{
//     int length;
//     int breadth;
// };
// void initialise(struct rectangle *r,int l,int b){
//     r->length=l;
//     r->breadth=b;
// }
// int area(struct rectangle r){// this will create its own copy in memory
//     return r.length * r.breadth;
// }
// void changeLength(struct rectangle *r,int l){
//     r->length=l;
// }
// int main(){
//     struct rectangle p;
//     initialise(&p,10,20);// r-> will point to the address of p
//     cout<<area(p)<<endl;;
//     changeLength(&p,100);
//     cout<<area(p);
    
//     return 0;
// }

// #include<iostream>
// using namespace std;
// class rectangle{
//     private:
//     int length;
//     int breadth;
//     public:
//     rectangle(int l,int b);
//     void changeLength(int l);
//     void area();
// };
// rectangle::rectangle(int l,int b){
//     this->length=l;
//     this->breadth=b;
// }
// void  rectangle::area(){
//     cout<<"area is "<<length*breadth<<endl;// we can always access the private data via function of class
// }

// void rectangle::changeLength(int l){
//     this->length=l;
// }
// int main(){
//     rectangle r(10,25);
//     r.area();
//     r.changeLength(100);
//     r.area(); 
//     return 0;
// }

#include<iostream>
using namespace std;
class rectangle{
    private:
    int length;
    int breadth;
    public:
    rectangle(){length=breadth=1;}
    rectangle(int l,int b):length(l),breadth(b){}
    int area();
    int perimeter();
    int getLength(){
        return length;
    }
    void setLength(int l){this->length=l;}
    ~rectangle();
};
int rectangle::area(){
    return length*breadth;
}
int rectangle :: perimeter(){
    return 2*(length+breadth);
}
int main(){
    
    return 0;
}