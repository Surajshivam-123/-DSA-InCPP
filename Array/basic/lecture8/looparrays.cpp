#include<iostream>
using namespace std;
int main(){
      int array[10]={1,2,3,4,5,6,7,8,9};
    int size;
    size=sizeof(array)/sizeof(int);
    for(int i=0;i<size;i++){
        cout<<array[i]<<endl;

    }
    return 0;
}
