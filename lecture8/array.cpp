#include<iostream>
using namespace std;
int main(){
    int array[100]={20,30,40,50,60,70};
    double price[]={98.67,78,90.00,95.5};
    cout<<array[5]<<endl;
     array[1]=100;
     array[99]=200;
     cout<<array[1]<<endl;
     cout<<array[99]<<endl;
     cout<<array[100]<<endl;//no value given
     cout<<array[45]<<endl;
     
return 0;
}