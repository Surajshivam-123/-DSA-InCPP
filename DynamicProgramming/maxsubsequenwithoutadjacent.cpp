#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
*/

int f(vector<int>nums,int in){//TC->O(2^n)
    if(in==0)return nums[in];
    if(in<0)return 0;
    //pick
    int pick=nums[in]+f(nums,in-2);
    //not pick
    int npick=f(nums,in-1);
    return max(pick,npick);
}

//reduce time complexity by removing overlapping subproblem
//Memoiztion
int of(vector<int>nums,int in,vector<int>dp){//TC->O(N)
    if(in==0)return nums[in];
    if(in<0)return 0;
    if(dp[in]!=-1)return dp[in];
    int pick=nums[in]+of(nums,in-2,dp);
    //not pick
    int npick=of(nums,in-1,dp);
    return dp[in]=max(pick,npick);
}

//Tabulation
int tf(vector<int>& nums){//TC->O(n) and SC->O(n)
    vector<int>dp(nums.size());
    dp[0]=nums[0];
    for(int i=1;i<nums.size();i++){
        int pick=nums[i]+(i>1?dp[i-2]:0);
        int npick=dp[i-1];
        dp[i]=max(pick,npick);
    }
    return dp[nums.size()-1];
}

//space optimization
int sf(vector<int>& nums){
    int prev1=nums[0],prev2=0;
    for(int i=1;i<nums.size();i++){
        int pick=nums[i]+prev2;
        int npick=prev1;
        int cur=max(npick,pick);
        prev2=prev1;
        prev1=cur;
    }
    return prev1;
}

int rob(vector<int>& nums){
    vector<int>dp(nums.size()+1,-1);
    return of(nums,nums.size()-1,dp);
}


int main()
{
    vector<int>nums={1,2,3,1};
    cout<<rob(nums)<<endl;
    cout<<sf(nums)<<endl;
    cout<<tf(nums)<<endl;
return 0;
}