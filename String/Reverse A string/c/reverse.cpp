#include<iostream>
using namespace std;
char * reverseString(char *s){
    int i,j;
    //increment i till it point to "\0"
    for(i=0;s[i]!='\0';i++){}//now i point to null

    char *aux=new char[i+1]; // +1 for inluding null character
    i--; // 0 9 8 7 6 \0
         //         i   
    for(j=0;i>=0;j++,i--){
        aux[j]=s[i];
    }

    aux[j]='\0';
    return aux;
}
int main(){
    char s[]="ankit7890";
    char *a=reverseString(s);
    for(int i=0;a[i]!='\0';i++){
        cout<<a[i];
    }
    
    return 0;
}