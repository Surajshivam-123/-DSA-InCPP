#include <iostream>
using namespace std;

int add(int x,int y){
    cout<<" hello\n";
    return x+y;
}
int sub(int x,int y){
    return x-y;
}
int mult(int x,int y){
    return x*y;
}
int mu(int x,int y,int z){
    return x*y*z;
}
int executeop(int x,int y,int(*op)(int,int)){//callback function
    return op(x,y);
}
int main() {
    int (*funptr)(int,int);
    funptr=add;
    cout<<funptr(5,6)<<endl;
    int (*operation)(int,int);
    cout<<"Multiply="<<executeop(5,6,mult)<<endl;
    cout<<"#Multiply="<<mu(5,6,mult(3,2))<<endl;

}