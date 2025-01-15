#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5};
    cout<<arr<<endl;
    cout<<&arr[0]<<endl;
    cout<<*arr<<endl;
    cout<<*(arr+1)<<endl;//arr[1]
    cout<<*(arr+2)<<endl;//arr[2]
    int b=10;
    //arr=&b;//shows error because array pointer is constant 
}