#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter number ";
    cin>>n;
    
    int c=0;
    while(n!=1){
        bool flag=0;
        for(int i=2;i<n;i++){
            if(n%i==0){
                flag=1;
            }
        }
        if(flag==0 || n==2){
            c++;
        }
        n--;
    }
    cout<<"Number of prime="<<c;
}