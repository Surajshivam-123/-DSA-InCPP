#include<iostream>
#include<math.h>
using namespace std;
int main(){//32=2^5
    int n,rem,bin=0,p=0;
    cin>>n;
    while(n!=0){
        rem=n%2;
        bin=bin+rem*pow(10,p);
        n/=2;

        p++;
    }
    cout<<bin;
    int ma,c;
    while(bin!=0){
        ma=bin%10;
        
    }
    return 0;
}
