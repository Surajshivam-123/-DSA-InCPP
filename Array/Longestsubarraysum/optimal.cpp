#include<iostream>
using namespace std;
//2 pointer approach'
if array 
int longestSubarraySum(vector<int>a,int k){
    int maxlen=0;
    int n=a.size();
    int l=0,r=0;
    int sum=a[0];
    while(r<n){
        while(l<=r && sum>k){
            sum-=a[l];
            l++;
        }
        if(sum==k){
            maxlen=max(maxlen,r-l+1);
        }
        r++;
        if(r<n)sum+=a[r];
    }
    return maxlen;
}


int main()
{
return 0;
}