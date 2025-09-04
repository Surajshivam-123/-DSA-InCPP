#include<iostream>
using namespace std;
// maximum subarray sum

// brute-force
int maximumsubarraysum(int arr[],int n){
    int maxsum=INT16_MIN;
    for(int st=0;st<n;st++){
        int sum=0;
        for(int end=st;end<n;end++){
            sum+=arr[end];
            maxsum=max(sum,maxsum);
        }
        
        }
        return maxsum;
}
// kadane's algorithm
int main(){
    int array[]={-2,1,-3,4,-1,2,1,-5,4};
    int n=9;
    int sum=0,maxsum=INT16_MIN;
    for(int i=0;i<n;i++){
        sum+=array[i];
        maxsum=max(sum,maxsum);
        if(sum<0){
            sum=0;
        }
    }
    cout<<maxsum;
}