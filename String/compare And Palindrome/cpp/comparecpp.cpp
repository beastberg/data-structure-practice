#include<iostream>
using namespace std;

bool isSameString(string s1, string s2){
    if(s1.length() !=s2.length()){
        return 0;
    }

    for(int i=0;i<s1.length();i++){
        if(s1[i]!=s2[i])
            return 0;
    }
    return 1;
}

bool isPalindrome(string s){
    int i=0,j;
    j=s.length()-1;

    while(i<j){
        if(s[i]!=s[j]){
            return 0;
        }
        i++;
        j--;
    }
    return 1;

}

int main(){

    string s1="Ankit123";
    string s2="Ankit";

    cout<<s1<<" "<<s2<<endl;
    if(isSameString(s1,s2)){
        cout<<"String are same"<<endl;
    } 
    else{
        cout<<"Strings are different"<<endl;
    }
    
    string s3="ankna";
    cout<<s3<<endl;
    if(isPalindrome(s3)){
        cout<<"String is Palindrome"<<endl;
    } 
    else{
        cout<<"String is not a palindrome"<<endl;
    }
    return 0;
}