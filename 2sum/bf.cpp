// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.
// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>nums = {2,7,11,15};
    int target=9;
    vector<int>ans;
    int f=0;
    for(int i=0;i<nums.size();i++){
        if(f==1)break;
        for(int j=0;j<nums.size();j++){
            if((nums[i]+nums[j])==target){
                ans.push_back(i);
                ans.push_back(j);
                f=1;
                break;
            }
        }
    }
    for(int i:ans){
        cout<<i<<" ";
    }
}