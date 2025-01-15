#include<iostream>
using namespace std;
int main(){
    int n=5;
    int array[5]={1,2,3,4,5};
    //Subarray is subset of array
    for(int st=0;st<n;st++){
        for(int end=st;end<n;end++){
            cout<<'{';
            for(int i=st;i<=end;i++){
                cout<<array[i]<<',';
            }
            cout<<'}'<<endl;
        }
    }
}