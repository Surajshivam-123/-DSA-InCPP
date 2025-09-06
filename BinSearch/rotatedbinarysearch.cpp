#include<iostream>
#include<vector>
using namespace std;
    int search(vector<int>& nums, int target) {//[4,5,6,7,0,1,2]
       int s=0,end=nums.size()-1;
       while(s<=end){
         int mid=s+(end-s)/2;
         if(nums[mid]==target){
            return mid;
         }
         if(nums[s]<=nums[mid]){//left half sorted
            if(target>=nums[s] && nums[mid]>=target){
                end=mid-1;
            }
            else{
                s=mid+1;
            }
         }
         else{//right half sorted
            if(target>=nums[mid] && nums[end]>=target){
                    s=mid+1;
            }
            else{
                end=mid-1;
            }
         }
       }
       return -1;
       }
    
    
int main(){
    vector<int>arr={5,6,7,8,9,1,2,3,4};
    cout<<search(arr,3);
}