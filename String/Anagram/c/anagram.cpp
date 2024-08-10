// Input: str1 = “listen”  str2 = “silent”
// Output: “Anagram”
// Explanation: All characters of “listen” and “silent” are the same.

// Input: str1 = “gram”  str2 = “arm”
// Output: “Not Anagram”

#include<iostream>
using namespace std;
int isAnagram(char *s1,char *s2){
    int H[26]={0}; //array hashing

    for(int i=0;s1[i]!='\0';i++){
        H[s1[i]-'a']++;  //H[i]++ = increment value
    }

    for(int i=0;s2[i]!='\0';i++){
        H[s2[i]-97]--;
        if(H[s2[i]-97]<0) //H[i]-- =decrement
           return 0;
    }

    for(int i=0;i<26;i++){
        if(H[i]>0)    //checking if H[i]>0
          return 0;
    }
    
    return 1;
}

int main(){
    
    char s1[]="silent";
    char s2[]="listen";
    if(isAnagram(s1,s2))
        cout<<" this is a anagram"<<endl;
    else
        cout<<"this is not a anagram"<<endl;
    return 0;
}