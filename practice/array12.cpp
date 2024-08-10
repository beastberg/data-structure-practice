#include<iostream>
using namespace std;
class Array{
    private:
    int length;
    int size;
    int *A;
    void swap(int *x,int *y);

    public:
    Array(){
        size=10;
        length=0;
        A=new int [size];
    }

    Array(int sz){
        this->size=sz;
        int length=0;
        A = new int[size];
    }
    ~Array(){
        delete []A;
    }

    void Display();
    void Append(int x);
    void Insert(int index,int x);
    int  Delete(int index);
    int  LinearSearch(int Key);
    int  BinarySearch(int Key);
    int  Get(int index);
    void Set(int index,int x);
    int  Max();
    int  Min();
    int  Sum();
    float Avg();
    void Reverse();
    void Reverse2();
    void InsertSort(int x);
    bool isSorted();
    void Rearrange();
    Array* Merge(Array arr2);
    Array* Union(Array arr2);
    Array* Diff(Array arr2);
    Array* Inter(Array arr2);
};
void Array::Display(){
    int i;
    cout<<"the element in arrays are ";
    for(i=0;i<length;i++){
        cout<<A[i]<<" ";
    }
}

void Array::Append(int x){
    A[length++]=x;
}

void Array::Insert(int index,int x){
    if(index<0 && index>length)
       return;
    
   if(length<size){
     for(int i=length;i<index;i--){
        A[1+i]=A[i];   
    }
    A[index]=x;
   }
}

int Array::Delete(int index){
  if(index>=0 || index<length){
    int num=A[index];
    for(int i=index;i<length-1;i++){
        A[i]=A[i+1];
    }
    length--;
    return num;
  }
  return 0;
  
}

void Array ::swap(int *x,int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y = temp;
}

int Array::LinearSearch(int key){
    for(int i=0;i<length;i++){
        if(key==A[i]);
        return i;
        swap(&A[0],&A[i]);
    }
    return 0;
}

int Array :: BinarySearch(int key){
    int low=0;
    int high=length-1;

    int mid=(low+high)/2;
    while(low<=high){
        if(A[mid]==key)
            return mid;
        else if(A[mid]<key){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return false;
}

int Array::Get(int index){
    if(index>=0 && index<length){
        return A[index];
    }
    return -1;
}
void Array::Set(int index,int x){
    if(index>=0 && index<length)
        A[index]=x;
}

int Array::Max(){
    int max=A[0];
    for(int i=1;i<length;i++){
        if(A[i]>max)
           max=A[i];
    }
    return max;
}

int Array::Min(){
    int min =A[0];
    for(int i=1;i<length;i++){
        if(A[i]<min)
            min=A[i];
    }
    return min;
}
int Array::Sum(){
    int s=0;
    for(int i=0;i<length;i++){
        s+=A[i];
    }
    return s;
}
float Array::Avg(){
    return (float) Sum()/length;
}
void Array::Reverse(){
    int *B;
   int i,j;
   B=new int[length];
   for(i=length-1,j=0;i>=0;i--,j++){
    B[j]=A[i];
   }
   for(i=0;i<length;i++){
    A[i]=B[i];
   }
}

void Array::Reverse2(){
    int i,j;
    for(i=0,j=length-1;i<j;i++,j--){
        swap(&A[i],&A[j]); 
    }
}

void Array::InsertSort(int x){//only for sorted array
int i = length-1;
if(length==size){
    return;
}
while(i>=0 && A[i]>x){
    A[i+1]= A[i];
    i--;
}
A[i+1]=x;
length++;

}

bool Array :: isSorted(){
    int i;
    for(i=0;i<length;i++){
        if(A[i]>A[i+1])
           return 0;
    }
    return 1;
}

void Array:: Rearrange(){
    int i,j;
    i=0;
    j=length-1;

    while(i<j){
        while(A[i]<0)i++;
        while(A[j]>=0)j--;
        if(i<j){
            swap(&A[i],&A[j]);
        }
    }
}

Array* Array ::Merge(Array arr2){
    int i,j,k;
    i=j=k=0;
    Array *arr3 =new Array(length +arr2.length);
    while(i<length && j<arr2.length){
        if(A[i]<arr2.A[j])
           arr3->A[k++]=A[i++];
        else 
           arr3->A[k++]=arr2.A[j++];
    }
    while(i<length){
        arr3->A[k++]=A[i++];
    }
    while(j<arr2.length){
        arr3->A[k++]=arr2.A[j++];
    }
    arr3->length=length+arr2.length;
    return arr3;

}

Array* Array::Union(Array arr2){
    int i,j,k;
    i=j=k=0;
    Array *arr3 = new Array(length + arr2.length);

    while(i<length && j<arr2.length){
        if(A[i]<arr2.A[j]){
            arr3->A[k++]=A[i++];
        }
        else if(arr2.A[j]<A[i]){
            arr3->A[k++]=arr2.A[j++];
        }
        else{
            arr3->A[k++]=A[i++];
            j++;
        }
    }
    while(i<length){
        arr3->A[k++]=A[i++];
    }
    while(j<arr2.length){
        arr3->A[k++]=arr2.A[j++];
    }
    arr3->length=length+arr2.length;
    return arr3;
}

Array* Array::Inter(Array arr2){
    int i,j,k;
    i=j=k=0;
    Array *arr3 = new Array(length +arr2.length);
    while(i<length && j<arr2.length){
        if(A[i]<arr2.A[j]){
            i++;
        }
        else if(arr2.A[j]<A[i]){
            j++;
        }
        else if(A[i]== arr2.A[j]){
            arr3->A[k++]=A[i];
            j++;
        }
    }
    arr3->length=k;
    return arr3;

}
Array* Array::Diff(Array arr2){
    int i,j,k;
    i=j=k=0;

    Array *arr3 =new Array(length +arr2.length);
    while(i<length && j<arr2.length){
        if(A[i]<arr2.A[j])
           arr3->A[k++]=A[i++];
        else if(arr2.A[j]<A[i])
           j++;
        else{
            i++;
            j++;
        }
    }
    while(i<length){
        arr3->A[k++]=A[i++];
    }

    arr3->length=k;
    return arr3;
}



int main(){

    Array arr1(10);
    arr1.Append(1);
    arr1.Append(3);
    arr1.Append(5);
    arr1.Append(7);

    Array arr2(10);
    arr2.Append(2);
    arr2.Append(3);
    arr2.Append(6);
    arr2.Append(7);

    cout << "Array 1: ";
    arr1.Display();
    cout << endl;
    
    cout << "Array 2: ";
    arr2.Display();
    cout << endl;

    // Merge the arrays
    Array *arr3 = arr1.Merge(arr2);
    cout << "Merged Array: ";
    arr3->Display();
    cout << endl;

    
    
    return 0;
}