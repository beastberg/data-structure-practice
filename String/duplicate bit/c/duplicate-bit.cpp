#include<iostream>
using namespace std;
//function works only for lower case aplhabet

//similar to hashing using array
//need 26 bits ,so acquire 32 bits

void duplicate(char *s){
uint32_t H=0; //initalised 32 bits to 0

for(int i=0;s[i]!='\0';i++){
    uint32_t x=1;
    x=x<<(s[i]-97);//moving x to appropriate place

    // we can mask these changes
    if(H & x)// if H and x is greater than 0
       cout<<s[i]<<" is a duplicate"<<endl;
    else
       H=H|x;
}

}

int main(){
    char s[]="ankitankit";
    duplicate(s);

    return 0;
}