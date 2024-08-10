#include <iostream>
using namespace std;


class rectangle{
    private:
    int length;
    int breadth;

    public:
    rectangle(int l,int b){
        length=l;
        breadth=b;
    }

    int area(){
        return length *breadth;
    }

    void changeLength(int l){
    length=l;}
};

int main() {

    rectangle r(10,5);
    cout<<r.area();
    r.changeLength(20);
    cout<<r.area();

    return 0;
}