#include<iostream>
using namespace std;

void duplicate(char *s){
    int ht[26]={0};

    for(int i=0;s[i]!='\0';i++){
        ht[s[i]-97]++;//increment the count for corresponding letter
    }

    for(int i=0;i<26;i++){
        if(ht[i]>1){
            cout<<ht[i]<<" "<<char(i+'a')<<endl;
        }
    }
}

int main(){
    char s[]="findiffiiing";
    duplicate(s);
    return 0;
}