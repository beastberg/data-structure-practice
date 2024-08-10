//this is for only cpp
#include<iostream>
using namespace std;
void upperCase(string &s){
    for(int i=0;s[i]!='\0';i++){
        if(s[i]>=97 && s[i]<=122)
           s[i]-=32;
    }
}
void changeCase(string &s){
    for(int i=0;s[i]!='\0';i++){
        if(s[i]>=97 && s[i]<='z')
            s[i]-=32;
        else if(s[i]>='A' && s[i]<=90)
             s[i]+=32;
    }
}
int stringLength(string s){
    int i=0;
    while(s[i]!='\0'){
        i++;
    }
    return i;
}
int main(){
    
    string s="No money 5% PrOBLEM";
    string s2="ABcDE7";
    upperCase(s);
    cout<<"Upper case element "<<s<<endl;

    changeCase(s2);
    cout<<"change case element "<<s2<<endl;
    cout<<"String Length "<<stringLength(s)<<endl;

    


    return 0;
}

// this id done for c

#include<iostream>
using namespace std;
void upperCase(char *s){
    for(int i=0;s[i]!='\0';i++){
        if(s[i]>=97 && s[i]<=122)
           s[i]-=32;
    }
}
void changeCase(char *s){
    for(int i=0;s[i]!='\0';i++){
        if(s[i]>=97 && s[i]<='z')
            s[i]-=32;
        else if(s[i]>='A' && s[i]<=90)
             s[i]+=32;
    }
}
int stringLength(char *s){
    int i=0;
    while(s[i]!='\0'){
        i++;
    }
    return i;
}
int main(){
    
    char s[]="No money 5% PrOBLEM";
    char s2[]="ABcDE7";
    upperCase(s);
    cout<<"Upper case element "<<s<<endl;

    changeCase(s2);
    cout<<"change case element "<<s2<<endl;
    cout<<"String Length "<<stringLength(s)<<endl;

    


    return 0;
}