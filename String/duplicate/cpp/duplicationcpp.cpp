#include<iostream>
using namespace std;

void duplicate(string s){
    int ht[26]={0};

    for(int i=0;i<s.length();i++){
        ht[s[i]-97]++;
    }

    for(int i=0;i<26;i++){
        if(ht[i]>1){
            cout<<ht[i]<<" "<<char(i+'a')<<endl;
        }
    }
}

int main(){

    string s="findiffiiing";
    duplicate(s);
    
    return 0;
}