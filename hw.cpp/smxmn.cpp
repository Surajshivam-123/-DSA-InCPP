#include<iostream>
using namespace std;
int main(){
    int max=INT16_MIN,min=INT16_MAX;
    int maxi,mini;
    int don[5];
    for(int i=0;i<5;i++){
        cin>>don[i];
        if(don[i]>=max){
            max=don[i];
            maxi=i;
        }
        if(don[i]<=min){
            min=don[i];
            mini=i;
        }
    }
    swap(don[maxi],don[mini]);
    cout<<"after swpping";
    for(int i=0;i<5;i++){
        cout<<don[i]<<endl;
    }
    return 0;
    
}