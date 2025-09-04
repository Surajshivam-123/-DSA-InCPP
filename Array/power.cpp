#include<iostream>
using namespace std;
// Core Idea: Binary Representation of Exponent

// Every integer exponent 
// 𝑛
// n can be expressed in binary form.
// Example:
// 13=(1101)2​=2^3+2^2+2^0
// x^13=x^8⋅x^4⋅x^1
// Instead of multiplying 13 times, we just compute powers of 2 by repeated squaring and multiply only the necessary ones.
double power(double x,int n){
    if(n==0) return 1.0;
    if(x==0) return 0.0;
    if(x==1) return 1.0;
    if(x==-1 && n%2==0) return 1.0;
    if(x==-1 && n%2!=0) return -1.0;
    
    long binform=n;
    if(n<0){
        x=1/x;
        binform=-binform;
    }
    double ans=1;
    while(binform>0){
        if(binform%2==1){//rightmost digit is 1 and we can multiply to ans
            ans*=x;
        }
        x*=x;
        binform/=2;
    }
    return ans;
}
int main(){
    cout<<power(5,6);
}