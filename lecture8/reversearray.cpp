#include<iostream>
using namespace std;
int main(){
    int ap[]={12,13,14,15,16,17,18};
    int start=0,end=6;
    while(start<=end){
        swap(ap[start],ap[end]);
        start++;end--;

    }
    for(int i=0;i<7;i++){
        cout<<ap[i]<<endl;
    }
    return 0;
}