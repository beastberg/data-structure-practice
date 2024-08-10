#include<iostream>
using namespace std;
// A string is valid if it consist of alphabet and number only

int validateString(char *s){
    for(int i=0;s[i]!='\0';i++){
        if(!(s[i]>='a' && s[i]<='z')&&
           !(s[i]>='A' && s[i]<='Z')&&
           !(s[i]>='0' && s[i]<='9')){
            return 0;
           }
    }

    return 1;
}
int main(){
    //use double quotes for string
    char s[]="Ankit%%malik";
    if(validateString(s)){
        cout<<"the string is valid"<<endl;
    }
    else{
        cout<<"galat string hai pagal"<<endl;
    }

    //replace string char 
    s[5]='1';
    s[6]='1';
    
    cout<<s<<endl;

    if(validateString(s)){
        cout<<"the string is valid"<<endl;
    }
    else{
        cout<<"galat string hai pagal"<<endl;
    }

    return 0;
}