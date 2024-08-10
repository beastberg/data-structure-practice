#include<iostream>
using namespace std;

bool validateString(string s){
    for(int i=0;i<s.length();i++){
        if(!(s[i]>='a' && s[i]<='z')&&
        !(s[i]>='A' && s[i]<='Z')&&
        !(s[i]>='0' && s[i]<='9')){
            return false;
        }

    }
    return true;
}

int main(){
    string s="ANKIT&&malik";
    cout<<s<<endl;
    if(validateString(s)){
        cout<<"String is valid"<<endl;
    }else{
        cout<<"string is not valid"<<endl;
    }
    s[5]='1';
    s[6]='7';
        
    cout<<s<<endl;
    if(validateString(s)){
        cout<<"String is valid"<<endl;
    }else{
        cout<<"string is not valid"<<endl;
    }


    return 0;
}