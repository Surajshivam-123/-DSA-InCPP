#include<bits/stdc++.h>
using namespace std;
//DIVIDE AND CONQUER ALGORITHM
// 1,Divided the array till we get single element (through middle)
// 2,merge smaller parts to create sorted array
// EXAMPLE
// arr[]={12,31,35,8,32,17}
// division [12,31,35] ,   | [8,32,17]
//          [12,31], |[35] |[8,32],|[17]
//          [12]|[31]|,[35]| [8],  |[32]
void merge(vector<int>&arr,int st,int mid,int end){//O(n)
    vector<int>t;
    int i=st,j=mid+1;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            t.push_back(arr[i]);
            i++;
        }
        else{
            t.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        t.push_back(arr[i]);
            i++;
    }
    while(j<=end){
        t.push_back(arr[j]);
            j++;
    }
    for(int i=0;i<t.size();i++){
        arr[st+i]=t[i];
    }
}
void mergesort(vector<int>&arr,int st,int end){//O(n*logn)
    if(st<end){
    int mid=st+(end-st)/2;
    mergesort(arr,st,mid);
    mergesort(arr,mid+1,end);
    merge(arr,st,mid,end);
    }
}
int main(){
    vector<int>v={5,3,7,2,8,9};
    mergesort(v,0,v.size()-1);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}