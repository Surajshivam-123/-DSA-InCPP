#include<iostream>
using namespace std;
int main(){
    int don[5];
    int sum=0,pro=1,a;
    for(int i=0;i<5;i++){
        cin>>a;
        don[i]=a;
    }
    for(int i=0;i<5;i++){
        sum+=don[i];
        pro*=don[i];
    }
    cout<<"sum="<<sum<<endl<<"Product="<<pro;
    return 0;
}