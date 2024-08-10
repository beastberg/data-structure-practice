#include<iostream>
using namespace std;

void reverseString(string &s){
   char j;
   char i;
   for( j=0;j!=s.length();j++){}
   cout<<j<<endl;
   j--;

   char temp;
   for(int i=0;i<j;i++,j--){
    //swap
    temp=s[i];
    s[i]=s[j];
    s[j]=temp;
   }


   
}

//second method

string Reverse2(string &s){
    int n =s.length();
    // imp-> created a string with length 5 
    // and initialised with null character
    string aux(n,'\0');
    for(int  i=0;i<n;i++){
        aux[i]=s[n-1-i];
    } 
    return aux;
}

int main(){
 string s = "ankit";

    // First method
    // reverseString(s);
    // cout << "Reversed (in-place): " << s << endl;

    // Second method
    string a = Reverse2(s);
    cout << "Reversed (new string): " << a << endl;
    return 0;
}