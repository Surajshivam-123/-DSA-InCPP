#include<iostream>
using namespace std;
// Find Peak Element
// A peak element is an element that is strictly greater than its neighbors.

// Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

// You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

// You must write an algorithm that runs in O(log n) time.
int findPeakElement(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        if(r==0)return 0;
        if(nums[0]>nums[1])return 0;
        if(nums[r]>nums[r-1])return r;
        l++;r--;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(nums[mid-1]<nums[mid]){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return -1;
    }

// Find Minimumu element in rotated array
// Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

// [4,5,6,7,0,1,2] if it was rotated 4 times.
// [0,1,2,4,5,6,7] if it was rotated 7 times.
// Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

// Given the sorted rotated array nums of unique elements, return the minimum element of this array.

// You must write an algorithm that runs in O(log n) time.

 

// Example 1:

// Input: nums = [3,4,5,1,2]
// Output: 1
// Explanation: The original array was [1,2,3,4,5] rotated 3 times.
int findMin(vector<int>& nums) {
        int ans=INT_MAX;
        int l=0,r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[l]<=nums[mid] && nums[mid]<=nums[r]){//all sorted
                return nums[l];
            }
            if(nums[l]<=nums[mid]){//left sorted
                l=mid+1;
            }
            else{//right sorted
                if(nums[l]>nums[r]){
                    r=mid;
                }
                else{
                    r=mid-1;
                }
            }
        }
        return -1;
    }