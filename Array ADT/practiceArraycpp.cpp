#include<iostream>
using namespace std;

class Array{
    private:
    int *A;
    int size;
    int length;
    void Swap(int *x,int *y);

    public:
    Array(){
        size=10;
        length=0;
        A=new int[size];
    }
    Array(int sz){
        this->size=sz;
        length=0;
        A=new int[size];
        
    }
    ~Array(){
        delete []A;
    }
    
    void Display();
    void Append(int x);
    void Insert(int index,int x);
    int Delete (int index);
    int LinearSearch(int key);
    int BinartSearch(int key);
    int Get (int index);
    void Set(int index);
    int Max();
    int Min();
    int Sum();
    float Avg();
    void Reverse();
    void Reverse2();
    void insertSort(int x);
    int isSorted();
    void Rearrange();
    Array* Merge(Array arr2);
    Array* Union(Array arr2);
    Array* Diff(Array arr2);
    Array* Intersect(Array arr2);

};

void Array::Display(){
    int i;
    for(i=0;i<length;i++){
        cout<<A[i]<<" ";
    } 
}

void Array ::Append(int x){
if (length<size)
{
   A[length++]=x;
}
}

void Array::Insert(int index,int x){
    int i;
    if(index>=0 && index<=length){
        for(i=length;i>index;i--){
            A[i]=A[i-1];
        }
        A[index]=x;
        length++;
    }
}

int Array::Delete(int index){
    int x=0;
    int i;
    if(index>=0 &&index<length){
        x=A[index];
        for(i=index;i<length-1;i++){
            A[i]=A[i+1];
        }
        length--;
        return x;
    }
    return 0;
}

void Array::Swap(int *x,int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}




int main(){
    
    return 0;
}