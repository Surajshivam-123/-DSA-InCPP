#include<iostream>
using namespace std;
int main(){
  int a=5;
  cout<<&a<<endl; //print address of "a" 
  int* ptr=&a;
  cout<<ptr<<endl;//print address of "a"
  int** ptr2=&ptr;
  cout<<ptr2<<endl;//print address of "ptr"
  cout<<*(&a)<<endl;//print value stored in memory address
  cout<<*ptr<<endl;
  cout<<**ptr2<<endl;
  //increment and decrement in pointer
  cout<<ptr<<endl;
  ptr++;//4 is added to ptr
  cout<<ptr<<endl;
  ptr--;
  cout<<ptr<<endl;
//Subtract two pointer
int *ptr3=ptr+2;//if ptr=100 then ptr3=108
cout<<ptr3-ptr;
//comparison
cout<<(ptr!=ptr3);
}