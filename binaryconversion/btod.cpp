#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n,rem,res=0,p=0;
    cin>>n;//42
    while(n!=0){//0 1 0 1 0 1//101010
        rem=n%10;// 42 21 10 5 2 1
        n/=10;  
        res=res+rem*pow(2,p);
        p++;
    }
    cout<<res;
    return 0;
}