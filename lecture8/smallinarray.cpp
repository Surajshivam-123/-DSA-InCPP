#include<iostream>
using namespace std;
int main(){
    int array[10]={12,-17,56,45,56};
    int sm=INT64_MIN,bg=INT64_MAX;
    for(int i=0;i<10;i++){
        // if(array[i]<=sm){
        //     sm=array[i];
        // 
        // OR
        sm=min(array[i],sm);//gives min of two input values
        bg=max(array[i],bg);//gives max of two values
    }
    
    cout<<sm<<endl;
    cout<<bg;
    return 0;
}