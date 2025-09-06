#include<iostream>
using namespace std;
void changeA(int* ptr){//pass by reference using pointers
    *ptr=20;
}
void changea(int &b){//pass by reference using alias
    b=40;
}
int main(){
    int a=10;
    changeA(&a);
    cout<<a<<endl;
    changea(a);
    cout<<a<<endl;
}