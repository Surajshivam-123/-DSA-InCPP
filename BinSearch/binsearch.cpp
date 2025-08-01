#include<iostream>
using namespace std;
int binarysearch(int arr[],int n,int target){
    int s=0,e=n-1;
    int mid;
    while(s<=e){
        mid=(s+e)/2;
        if(target>arr[mid]){
            s=mid+1;
        }
        else if(target<arr[mid]){
            e=mid-1;
        }
        else{
            return mid;
        }
    }
    return -1;
}
//binary search using recursion
    int binarysearchr(int arr[],int st,int end,int tar){
        if(st<=end){
        int mid=st+(end-st)/2;
        if(arr[mid]<tar){
            st=++mid;
            return binarysearchr( arr,st,end,tar);
        }
        else if(arr[mid]>tar){
            end=--mid;
            return binarysearchr( arr,st,end,tar);
        }
        else 
            return mid;
        }
        return -1;
    }

int main(){
int suraj[]={-1,3,4,5,9,12};//sorted array is must
cout<<binarysearch(suraj,6,15)<<endl;
cout<<binarysearchr(suraj,0,5,15);
return 0;
}