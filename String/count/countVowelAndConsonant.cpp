#include<iostream>
using namespace std;

int countVowel(char *s){
    int CountV=0;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='a'|| s[i]=='e'|| s[i]=='i'|| s[i]=='o'|| s[i]=='u'
        || s[i]=='A'|| s[i]=='E'|| s[i]=='I'|| s[i]=='O'|| s[i]=='U' )
           CountV++;
    }
    return CountV;
}

int countConsonant(char *s){
    int countAlpha=0;
    for(int i=0;s[i]!='\0';i++){
        if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')){
           countAlpha++;
        }
    }
    return countAlpha - countVowel(s);
}
int countWord(char *s){
    int countW=0;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]==' ' && s[i-1]!=' '){
            countW++;
        }
    }
    return ++countW;
}

int main(){

    char s[]="How Are  you";
    cout<<"Number of vowel : "<<countVowel(s)<<endl;
    cout<<"number of consonant : "<<countConsonant(s)<<endl;
    cout<<"number of word : "<<countWord(s);
    
    return 0;
}