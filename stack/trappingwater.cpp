#include<iostream>
using namespace std;
// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
// Example 1:
// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
// Example 2:
// Input: height = [4,2,0,3,2,5]
// Output: 9

//Prefix approach
int trap(vector<int>& height) {//TC->O(n)  SC->O(n)
    int n=height.size();
    int hl[n],hr[n];
    int maxl=0,maxr=0;
    for(int i=0;i<n;i++){
        if(maxl<height[i]){
            maxl=height[i];
        }
        hl[i]=maxl;
    }
    for(int i=n-1;i>=0;i--){
        if(maxr<height[i]){
            maxr=height[i];
        }
        hr[i]=maxr;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=max(0,min(hl[i],hr[i])-height[i]);
    }
    return ans;
}


//Two pointer approach
int trap(vector<int>& height) {//TC->O(n)  SC->O(1)
    int n=height.size();
    int l=0,r=n-1;
    int ans=0,lmax=0,rmax=0;
    while(l<r){
     lmax=max(lmax,height[l]);
     rmax=max(rmax,height[r]);
     if(lmax<=rmax){
         ans+=lmax-height[l];
         l++;
     }
     else{
         ans+=rmax-height[r];
         r--;
     }
    }
    return ans;
 }


int main()
{
return 0;
}
