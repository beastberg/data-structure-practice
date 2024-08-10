// #include<iostream>
// using namespace std;
// void Insert(int A[],int n){
//     int   i=n,temp;
//     temp=A[i];
//     while(i>1 && temp>A[i/2]){
//         A[i]=A[i/2];
//         i=i/2;
//     }
//     A[i]=temp;
// }
// int main(){
//     int H[]={0,14,15,5,20,30,8,40};
//     int i;
//     for(i=2;i<=7;i++)
//         Insert(H,i);
//     for(int x:H)
//         cout<<x<<" ";
//     return 0;
// }

// #include<iostream>
// #include<vector>
// #include<cmath>
// using namespace std;

// class MaxHeap{
//     private:
//     vector<int> heap;
//     void heapify(int index){
//         while(index>0){
//             int parentIndex=(index-1)/2;
//             if(heap[index]>heap[parentIndex]){
//                 swap(heap[index],heap[parentIndex]);
//                 index=parentIndex;
//             }
//             else{
//                 break;
//             }
//         }
//     }
//     public:
//     void insert(int element){
//         heap.push_back(element);
//         heapify(heap.size()-1);
//     }

//     void display(){
//         for(int i=0;i<heap.size();i++){
//             cout<<heap[i]<<" ";
//         }
//         cout<<endl;
//     }

// };
// int main(){
//     MaxHeap maxHeap;
    
//     maxHeap.insert(10);
//     maxHeap.insert(20);
//     maxHeap.insert(5);
//     maxHeap.insert(30);
//     maxHeap.insert(15);
//     maxHeap.insert(35);

//     cout << "Heap elements after insertions: ";
//     maxHeap.display();
//     return 0;
// }


#include<iostream>
#include<vector>
using namespace std;

class maxHeap{
    private:
    vector<int > heap;
    void swap(int i,int j){
        int temp=heap[i];
        heap[i]=heap[j];
        heap[j]=temp;
    }

    void heapifyDown(int i){
        int n=heap.size();
        int j=2*i+1;
        while(j<n-1){
            
        }
    }
};
int main(){
    
    return 0;
}