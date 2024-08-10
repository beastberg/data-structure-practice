#include<iostream>
using namespace std;

int isSameString(char * s1,char *s2){
    for(int i=0;s1[i]!='\0' ||s2[i]!='\0';i++){
        if(s1[i]!=s2[i])
            return 0;
    }
    return 1;
}

// example of palindrome madam
int isPalindrome(char *s){
    int i=0,j=0;

    //Increment 'j' till it point to element "\0"

    for(j=0;s[j]!='\0';j++){}
    j--;

    while(i<j){
        if(s[i]!=s[j])
            return 0;
        i++;
        j--;

    }
    return 1;
    
}


int main(){
    char s1[]="Ankit123321";
    char s2[]="Ankit12332";

    cout<<s1<<" "<<s2<<endl;
    if(isSameString(s1,s2)){
        cout<<"String are same"<<endl;
    }
    else{
        cout<<"String are not same"<<endl;
    }
    

    char s3[]="ma444am";

    cout<<s3<<endl;
    if(isPalindrome(s3)){
        cout<<"String is palindrome"<<endl;
    }
    else{
        cout<<"String is not palindrome"<<endl;
    }
    return 0;
    
}
