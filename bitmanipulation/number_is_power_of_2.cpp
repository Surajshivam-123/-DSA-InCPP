#include<iostream>
using namespace std;
//n=(6)10=(0110)2
//n-1=(5)10=(0101)2
//n=(8)10=(1000)2
//n-1=(7)10=(0111)2
//n & n-1 has same bits except the rightmost set bit
bool powerof2(int x){
    //cornercases x=0
    return x&& !(x & (x-1));
}
//to decrease any number by 1 flip the rightmost bits upto 1st bit==1

int main(){
    cout<<powerof2(1024)<<endl;
}