#include<iostream>
using namespace std;

int stringLength(char *s){
    int i=0;
    while(s[i]!='\0'){
        i++;
    }
    return i;
}

int main(){
    char s[]={65,68,'c',68,69,'\0'};
    cout<<"String Length "<<stringLength(s)<<endl;

    return 0;
}