#include<iostream>
#include<vector>
using namespace std;
//TC->Average/Practical case-O(nlogn)
//Worst case->O(n**2)
//SC->O(1)
int partition(int s,int e,int arr[]){
    int idx=s-1;
    int pivot=arr[e];
    for(int i=s;i<e;i++){
        if(arr[i]<=pivot){
            idx++;
            swap(arr[idx],arr[i]);
        }
    }
    idx++;
    swap(arr[e],arr[idx]);
    return idx;
}
void quicksort(int s,int e,int arr[]){
    if(s>=e)
        return;
    int pividx=partition(s,e,arr);
    quicksort(s,pividx-1,arr);
    quicksort(pividx+1,e,arr);
}
int main(){
int arr[]={8,7,6,5,4,3,2,1};
    quicksort(0,7,arr);
    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }
}