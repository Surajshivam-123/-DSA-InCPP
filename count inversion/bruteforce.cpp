#include<iostream>
using namespace std;
int main(){
    int arr[]={6,3,5,2,7};
    int c=0;
    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            if(arr[i]>arr[j])
                c++;
        }
    }
    cout<<c<<endl;
}