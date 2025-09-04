#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n,rem,res=0,p=0;
    cin>>n;//37
    while(n!=0){//100101
        rem=n%2;// 37 18 9 4 2 1
        n/=2;  
        res+=rem*pow(10,p);
        cout<<rem*pow(10,p)<<endl;
        p++;
    }
    cout<<endl;
    cout<<res;
    return 0;
} 
