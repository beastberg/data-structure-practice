#include<iostream>
#include <vector>
using namespace std;

class Element{
    public:
    int i;
    int j;
    int x;

    Element(int row=0,int col=0,int value=0):i(row),j(col),x(value){}
};

class Sparse{
    private:
    int m;
    int n;
    int num;//number of non -zero elements
    vector <Element> ele;

    public:
    Sparse(int rows=0,int cols=0,int nonZero=0):m(rows),n(cols),num(nonZero){}
    
    void create(){
        cout<<"enter the dimension"<<endl;
        cin>>m>>n;
        cout<<"Number of non -zero element: ";
        cin>>num;
        ele.resize(num);
        cout<<" Enter the non zero element (row column value)" <<cou;
        for(int i=0;i<num;i++){
            cin>>ele[i].i>> cin>>ele[i].j >>ele[i].x;
        }
    }

    void Display(){
        int k=0;// for iterating over element vector
        for(int i=0;i<m;i++){
            for(int j=0;i<n;j++){
                if(k<num && i==ele[k].i && j==ele[k].j)
                     cout<<ele[k++].x<<" ";
                else
                    cout<<"0 ";
            }
            cout<<endl;
        }
    }

    Sparse* add(Sparse& s){
        if(m !=s.m || n!=s.n)
             return nullptr;
        Sparse* sum =new Sparse(m,n);
        sum->ele.resize(num + s.num);

        int i=0,j=0,k=0;
        while(i<num && j<s.num){
            if(ele[i].i<s.ele[j].i)
               sum->ele[k++]=ele[i++];
            else if (ele[i].i>s.ele[j].i)
               sum->ele[k++] = s.ele[j++];
            else{
                if(ele[i].j<s.ele[j].j)
                   sum->ele[k++]=ele[i++];
                else if (ele[i].j >s.ele[j].j)
                    sum->ele[k++]=s.ele[j++];
                else{
                    sum->ele[k]=Element(ele[i].i,ele[i].j,ele[i].x+s.ele[j].x);
                    i++;
                    j++;
                    k++;
                }
            }
                 

        }
        while(i<num)
            sum->ele[k++]=ele[i++];
        while(j<s.num)
            sum->ele[k++]=s.ele[j++];
        sum->num=k;
        sum->ele.resize(k);

        return sum;
    }


};

int main(){
    Sparse s1, s2, *s3;
    cout << "You need to enter the dimensions for two sparse matrices\n";
    s1.create();
    s2.create();
    cout << "\n";
    s3 = s1.add(s2);
    if (s3) {
        cout << "Here is s3, which is the sum of s1 and s2\n";
        s3->Display();
        delete s3;
    } else {
        cout << "The matrices have different dimensions and cannot be added.\n";
    }
    return 0;
}