#include<iostream>
#include<vector>
using namespace std;
/*You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2*/
int singleNonDuplicate(vector<int>& nums) {
        int s=0,e=nums.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(e==0){
                return nums[mid];
            }
            if(s==nums.size()-1){
                return nums[mid];
            }
            if((nums[mid]!=nums[mid+1]) && (nums[mid]!=nums[mid-1])){
                return nums[mid];
            }
            else if(nums[mid]==nums[mid-1]){
                if((e-mid)%2==0){
                        e=mid-2;
                    }
                else{
                        s=mid+1;
                    }
                }
            else if(nums[mid]==nums[mid+1]){
                if((e-mid-1)%2==0){
                    e=mid-1;
                }
                else{
                    s=mid+2;
                }
            }
            }
           return -1;
        }
    int main(){
        
    }