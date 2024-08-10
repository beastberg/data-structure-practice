#include<iostream>
using namespace std;

class Element{
    public:
    //public are accessed directly
    int i; //row number
    int j;//column number
    int x;

};
class Sparse{
    private:
       int m;//Dimension of sparse -number of rows
       int n;//Dimension of sparse -number of cols
       int num;//number of non zero element
       Element * ele;//pointer to ELEMENT object    

    public:

    // we will not write a default constructor
    Sparse(int m,int n,int num){
        this->m=m;
        this->n=n;
        this->num=num;
        ele=new Element[this->num];
    }
    ~Sparse(){
        delete []ele;
    } 

    void read(){
        cout<<"Enter non -zero element"<<endl;
        for(int i=0;i<num;i++)
           cin>>ele[i].i>>ele[i].j>>ele[i].x;
    }

    void Display(){
        int k=0;// for iterating over the element array in heap
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(ele[k].i==i && ele[k].j==j)
                    cout<<ele[k++].x<<" ";
                else
                    cout<<"0 ";
            }
        }
    }
};

int main(){
    Sparse s1(5,5,5);
    s1.read();
    s1.Display();
    return 0;
}