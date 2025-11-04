#include<iostream>
using namespace std;
// Longest Increasing Subsequence
// Given an integer array nums, return the length of the longest strictly increasing subsequence.
// Example 1:
//Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       vector<int>ans;
       for(int i=0;i<nums.size();i++){
        auto in=lower_bound(ans.begin(),ans.end(),nums[i]);
        if(in==ans.end()){
            ans.push_back(nums[i]);
        }
        else{
            int ind=in-ans.begin();
            ans[ind]=nums[i];
        }
       }
       return ans.size();
    }
};
 



