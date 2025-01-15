#include<iostream>
using namespace std;
int p=10;
void fun(){
    cout<<p<<endl;
}
int main(){
    {
        int x=10;
    }
    fun();
    cout<<p;
  //  cout<<x;//it will show error
    return 0;
}