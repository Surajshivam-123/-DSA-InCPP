#include<iostream>
#include<vector>
using namespace std;
void bubblesort(int arr[],int n){//O(n*n)
    int t;
    bool isswap=0;
    for(int i=0;i<n-1;i++){
        for(int j=1;j<n;j++){
            if(arr[j-1]>arr[j]){
               swap(arr[j-1],arr[j]);
               isswap=1;
            }
        }
    }
    if(isswap==0){
        return;
    }
}
void selectionsort(int arr[],int n){
    int t;
    for(int i=0;i<n-1;i++){
        int mine=i;
      for(int j=i+1;j<n;j++){
        if(arr[mine]>arr[j]){
            mine=j;
        }
      }
      t=arr[i];
      arr[i]=arr[mine];
      arr[mine]=t;
    }
}
void insertionsort(int arr[],int n){
    for(int i=1;i<n;i++){
        int curr=arr[i];
        int prev=i-1;
        while(prev>=0 && arr[prev]>curr){
            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1]=curr;
        
    }
}
int main(){
    int sur[]={4,5,9,1,4,9,2,5,6};
    insertionsort(sur,9);
  for(int i=0;i<9;i++){
    cout<<sur[i]<<" ";
  }
    return 0;
}