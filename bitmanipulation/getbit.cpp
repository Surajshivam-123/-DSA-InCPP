#include<iostream>
using namespace std;
//   3210
//n=(0101)2=(5)10
//suppose we need to get bit at position 2 which is 1 in this case
int getbit(int n,int pos){
    return((n&(1<<pos)!=0));
}
//suppose we wnt to set bit(make that pos 1) at pos 1;
//0101->0111
int setbit(int n,int pos){
    return (n|(1<<pos));
}
//clearbit(make that pos 0)
//0101->0001
int clearbit(int n,int pos){
    return(n&(~(1<<pos)));
}
//update bit(1 or 0)->1.Clear bit 2.Set or clear bit
int main(){
    cout<<getbit(5,2)<<endl;
    cout<<setbit(5,1)<<endl;
    cout<<clearbit(5,2)<<endl;
}