#include<bits/stdc++.h>
using namespace std;
/*TC->O(2^n)(work done in each call*number of call)
    or to be precise->O(1.618)^n)
  SC->O(n)(depth*memory occupied in each level) */
int fibo(int n){
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    return fibo(n-1)+fibo(n-2);
}
//check if array is sorted
bool issort(vector<int>a,int n){//TC->O(n)
    if(n==1){
        return 1;
    }
        return issort(a,n-1)&(a[n-1]>=a[n-2]);
}
int binarysearch(vector<int>a,int target,int l,int h){
    int mid=(l+h)/2;
    if(l<=h){
    if(a[mid]==target){
        return mid;
    }
    else if(a[mid]>=target){
        binarysearch(a,target,l,mid-1);
    }
    else{
        binarysearch(a,target,mid+1,h);
    }
    }
    return -1;
}
//Print all subsets
void printsubsets(vector<int>&arr,vector<int>&ans,int i){//TC->O(2^n*n)
    if(i==arr.size()){
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return;
    }
    //include
    ans.push_back(arr[i]);
    printsubsets(arr,ans,i+1);
    //exclude
    ans.pop_back();
    printsubsets(arr,ans,i+1);
}
int main(){
    // for(int i=1;i<10;i++){
    //     cout<<fibo(i)<<endl;
    // }
vector<int>arr={4,6,7,8};
    // cout<<binarysearch(a,9,0,3);
    vector<int>ans;
    printsubsets(arr,ans,0);
}