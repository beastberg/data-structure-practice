#include <iostream>
using namespace std;
struct card {
    int face;
    int shape;
    int color;
};

int main() {
    struct card deck [52]= {// array of struct 
        {1,1,0},
        {1,0,1}
    };
    cout<<deck[0].face;
    
    return 0;
}