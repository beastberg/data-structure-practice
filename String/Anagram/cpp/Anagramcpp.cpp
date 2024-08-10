#include<iostream>
#include <unordered_map>
using namespace std;


bool isAnagram(string s1,string s2){
        if(s1.length() !=s2.length())
           return false;

        unordered_map<char,int> count;
        for(char x: s1){
            count[x]++;
        }
        for(char x : s2){
            count[x]--;
            if(count[x]<0) return false;
        }
        for(const auto& x :count){
            if(x.second!=0) return false;
        }
        return true;
    }
int main(){
     
    string s1 = "ankitmalik";
    string s2 = "ankit";
    if (isAnagram(s1, s2)) std::cout << "is Anagram" << std::endl;
    else cout << "is NOT Anagram" << std::endl;

    string s3 = "madam";
    string s4 = "aadmm";
    if (isAnagram(s3, s4)) std::cout << "is Anagram" << std::endl;
    else cout << "is NOT Anagram" << std::endl; 

    return 0;
}