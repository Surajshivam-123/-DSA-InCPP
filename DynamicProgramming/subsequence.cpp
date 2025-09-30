#include<iostream>
using namespace std;

// Steps 
// 1.Express in terms of index and target
// 2.explore possibilties of that index

// PARTITION EQUAL SUBSET SUM
// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

// Example 1:

// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].

class Solution {
public:
    bool f(int n,int target,vector<int>& nums,vector<vector<int>>&dp){
        if(n==0)
            return nums[0]==target;
        if(target==0)
            return true;
        if(dp[n][target]!=-1)
            return dp[n][target];
        bool notPick=f(n-1,target,nums,dp);
        bool pick=false;
        if(nums[n]<=target)
            pick=f(n-1,target-nums[n],nums,dp);
        return dp[n][target]=(notPick || pick);

    }
    bool canPartition(vector<int>& nums) {//TC-O(Nxtarget) SC-O(Nxtarget + n)
        int sum=0;
        int n=nums.size()-1;
        for(auto v:nums)
            sum+=v;
        if(sum%2==1)
            return false;
        int target=sum/2;
        vector<vector<bool>>dp(n+1,vector<int>(target+1,-1));
        return f(n,target,nums,dp);

    }
};

// tabulation
bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size()-1;
        for(auto v:nums)
            sum+=v;
        if(sum%2==1)
            return false;
        int tar=sum/2;
        vector<vector<bool>>dp(n+1,vector<bool>(tar+1,false));
        // base cases
        for(int i=0;i<=n;i++)
            dp[i][0]=true;
        if(nums[0]<=tar)
            dp[0][nums[0]]=true;
        // loops
        for(int i=1;i<=n;i++){
            for(int target=1;target<=tar;target++){
                bool notPick=dp[i-1][target];
                bool pick=false;
                if(nums[i]<=target)
                    pick=dp[i-1][target-nums[i]];
                dp[i][target]=(notPick || pick);
            }

        }
        return dp[n][tar];
    }

// space optimization
 bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size()-1;
        for(auto v:nums)
            sum+=v;
        if(sum%2==1)
            return false;
        int tar=sum/2;
        vector<int>prev(tar+1,false);
        // base cases
        if(nums[0]<=tar)
            prev[nums[0]]=true;
        // loops
        for(int i=1;i<=n;i++){
            vector<int>curr(tar+1,false);
            curr[0]=true;
            for(int target=1;target<=tar;target++){
                bool notPick=prev[target];
                bool pick=false;
                if(nums[i]<=target)
                    pick=prev[target-nums[i]];
                curr[target]=(notPick || pick);
            }
            prev=curr;
        }
        return prev[tar];
    }

    // 2035. Partition Array Into Two Arrays to Minimize Sum Difference
//     You are given an integer array nums of 2 * n integers. You need to partition nums into two arrays of length n to minimize the absolute difference of the sums of the arrays. To partition nums, put each element of nums into one of the two arrays.

// Return the minimum possible absolute difference.

 

// Example 1:

// example-1
// Input: nums = [3,9,7,3]
// Output: 2
// Explanation: One optimal partition is: [3,9] and [7,3].
// The absolute difference between the sums of the arrays is abs((3 + 9) - (7 + 3)) = 2.
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n=nums.size()-1;
        int sum=accumulate(nums.begin(),nums.end(),0);
        int tar=sum;
        vector<vector<bool>>dp(n+1,vector<bool>(tar+1,false));
        // base cases
        for(int i=0;i<=n;i++)
            dp[i][0]=true;
        if(nums[0]<=tar)dp[0][tar]=true;
        // loops
        for(int i=1;i<=n;i++){
            for(int target=1;target<=tar;target++){
                bool notPick=dp[i-1][target];
                bool pick=false;
                if(nums[i]<=target)
                    pick=dp[i-1][target-nums[i]];
                dp[i][target]=(notPick || pick);
            }

        }
        int ans=1e8;
        for(int i=0;i<=sum/2;i++){
            if(dp[n][i]==1){
                ans=min(ans,abs(sum-2*i));
            }
        }
        return ans;
    }
};