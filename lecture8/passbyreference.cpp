#include<iostream>
using namespace std;
void changearray(int array[],int size){
    for(int i=0;i<size;i++){
        array[i]=2*array[i];
    }
    cout<<"In function"<<endl;
    for(int i=0;i<size;i++){
       cout<<array[i]<<endl;
    }
}
int main(){
int suraj[10]={1,2,3,4,5,6,7,8,9,0};
int size=10;
changearray(suraj,10);
cout<<"IN main";
for(int i=0;i<size;i++){
       cout<<suraj[i]<<endl;
}
return 0;
}//If we change array in function then change also reflect under main function