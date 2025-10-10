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
// NUMBER OF SEQUENCES WITH SUM TARGET   
// Given an array arr of non-negative integers and an integer target, the task is to count all subsets of the array whose sum is equal to the given target.

// Examples:

// Input: arr[] = [5, 2, 3, 10, 6, 8], target = 10
// Output: 3
// Explanation: The subsets {5, 2, 3}, {2, 8}, and {10} sum up to the target 10.
class Solution {
  public:
  int f(int i, int target, vector<int>& arr, vector<vector<int>>& dp) {
    // base case
    if (i == 0) {
        if (target == 0 && arr[0] == 0) return 2; // take or not take
        if (target == 0) return 1;                // don't take
        if (arr[0] == target) return 1;           // only pick it
        return 0;
    }

    if (dp[i][target] != -1) return dp[i][target];

    int notPick = f(i - 1, target, arr, dp);
    int pick = 0;
    if (arr[i] <= target) pick = f(i - 1, target - arr[i], arr, dp);

    return dp[i][target] = pick + notPick;
}

int perfectSum(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return f(n - 1, target, arr, dp);
}

};
// tabulation
int perfectSum(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1,0));
    if(arr[0]==0)
        dp[0][0]=2;
    else
        dp[0][0]=1;
    if (arr[0] != 0 && arr[0] <= target) dp[0][arr[0]] = 1;
    for(int i=1;i<n;i++){
        for(int tar=0;tar<=target;tar++){
            int npick=dp[i-1][tar];
            int pick=(tar>=arr[i])?dp[i-1][tar-arr[i]]:0;
            dp[i][tar]=npick+pick;
        }
    }
    return dp[n-1][target];
}

// 01 NAPSACK PROBLEM
// Given n items, each with a specific weight and value, and a knapsack with a capacity of W, the task is to put the items in the knapsack such that the sum of weights of the items <= W and the sum of values associated with them is maximized. 

// Note: You can either place an item entirely in the bag or leave it out entirely. Also, each item is available in single quantity.

// Examples :

// Input: W = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1] 
// Output: 3
// Explanation: Choose the last item, which weighs 1 unit and has a value of 3.
int f(int n,vector<int> &val,vector<int> &w,int W,vector<vector<int>>&dp){
        if(n==0){
            if(W>=w[0])return val[0];
            else return 0;
        }
        if(dp[n][W]!=-1)
            return dp[n][W];
        int npick=f(n-1,val,w,W,dp);
        int pick=0;
        if(w[n]<=W)
            pick=val[n]+f(n-1,val,w,W-w[n],dp);
        return dp[n][W]=max(pick,npick);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n=val.size();
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
        return f(n-1,val,wt,W,dp);
    }
// tabulation
int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n=val.size();
        vector<vector<int>>dp(n,vector<int>(W+1,0));
        for(int w=wt[0];w<=W;w++){
            dp[0][w]=val[0];
        }
        for(int i=1;i<n;i++){
            for(int w=0;w<=W;w++){
                int npick=dp[i-1][w];
                int pick=0;
                if(wt[i]<=w){
                    pick=val[i]+dp[i-1][w-wt[i]];
                }
                dp[i][w]=max(pick,npick);
            }
        }
        return dp[n-1][W];
    }
// space optimization
int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n=val.size();
        vector<int>prev(W+1,0);
        for(int w=wt[0];w<=W;w++){
            prev[w]=val[0];
        }
        for(int i=1;i<n;i++){
            for(int w=W;w>=0;w--){
                int npick=prev[w];
                int pick=0;
                if(wt[i]<=w){
                    pick=val[i]+prev[w-wt[i]];
                }
                prev[w]=max(pick,npick);
            }
        }
        return prev[W];
    }

// INFINITE SUBSEQUENCE PROBLEM
// COIN CHANGE
// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.

 

// Example 1:

// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1
class Solution {
    int f(int in,int amount,vector<int>& coins,vector<vector<int>>&dp){
        if(amount==0)
            return 0;
        if(in==0){
            return amount%coins[0]==0?amount/coins[0]:1e9;
        }
        if(dp[in][amount]!=-1)
            return dp[in][amount];
        int notTake=f(in-1,amount,coins,dp);
        int take=INT_MAX;
        if(amount>=coins[in])
            take=1+f(in,amount-coins[in],coins,dp);
        return dp[in][amount]=min(take,notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=f(n-1,amount,coins,dp);
        return ans>=1e9?-1:ans;
    }
};

// tabulation
int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        // base case handle
        for (int i = 0; i <= amount; i++) {
            dp[0][i] = (i % coins[0] == 0) ? i / coins[0] : 1e9;
        }
        for (int i = 1; i < n; i++) {
            for (int tar = 0; tar <= amount; tar++) {
                int ntake = dp[i - 1][tar];
                int take = INT_MAX;
                if (tar >= coins[i])
                    take = 1 + dp[i][tar - coins[i]];
                dp[i][tar] = min(take, ntake);
            }
        }
        return dp[n - 1][amount] >= 1e9 ? -1 : dp[n - 1][amount];
    }

// Target Sum
// You are given an integer array nums and an integer target.

// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

// For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
// Return the number of different expressions that you can build, which evaluates to target.

 

// Example 1:

// Input: nums = [1,1,1,1,1], target = 3
// Output: 5
// Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3

class Solution {
    int f(int i,vector<int>& nums, int target,vector<vector<int>>&dp){
        if(i==0){
            if(target==0 && nums[0]==0)
                return 2;
            return abs(target)==abs(nums[0]);
        }
        if(dp[i][target+2000]!=-1){
            return dp[i][target+2000];
        }
        int neg=f(i-1,nums,target-nums[i],dp);
        int pos=f(i-1,nums,target+nums[i],dp);
        return dp[i][target+2000]=neg+pos;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(4001,-1));
        return f(n-1,nums,target,dp);
    }
};
// Another method
class Solution {
    int f(int i,vector<int>& nums, int target,vector<vector<int>>&dp){
        if(i==0){
            if(target==0 && nums[0]==0)
                return 2;
            if(target==0)
                return 1;
            return target==nums[0];
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        int npick=f(i-1,nums,target,dp);
        int pick=0;
        if(target>=nums[i])
            pick=f(i-1,nums,target-nums[i],dp);
        return dp[i][target]=pick+npick;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if((sum-target)%2!=0 || abs(target)>sum)
            return 0;
        int tar=(sum-target)/2;
        vector<vector<int>>dp(n,vector<int>(tar+1,-1));
        return f(n-1,nums,tar,dp);
    }
};
// UNBOUNDED KNAPSACK (INFINITE SUBSEQUENCE PROBLEM)
// Given a set of items, each with a weight and a value, represented by the array wt and val respectively. Also, a knapsack with a weight limit capacity.
// The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
// Note: Each item can be taken any number of times.

// Examples:

// Input: val = [1, 1], wt = [2, 1], capacity = 3
// Output: 3
// Explanation: The optimal choice is to pick the 2nd element 3 times.
int f(int i,vector<int>& val, vector<int>& wt, int capacity,vector<vector<int>>&dp){
        if(i==0){
            return val[0]*(capacity/wt[0]);
        }
        if(capacity<0)
            return 0;
        if(dp[i][capacity]!=-1){
            return dp[i][capacity];
        }
        int npick=f(i-1,val,wt,capacity,dp);
        int pick=0;
        if(capacity>=wt[i])
            pick=val[i]+f(i,val,wt,capacity-wt[i],dp);
        return dp[i][capacity]=max(pick,npick);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n=val.size();
        vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
        return f(n-1,val,wt,capacity,dp);
    }
// tabulation
int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n=val.size();
        vector<vector<int>>dp(n,vector<int>(capacity+1,0));
        for(int k=wt[0];k<=capacity;k++){
            dp[0][k]=val[0]*(k/wt[0]);
        }
        for(int i=1;i<n;i++){
            for(int k=0;k<=capacity;k++){
                int npick=dp[i-1][k];
                int pick=0;
                if(k>=wt[i])
                    pick=val[i]+dp[i][k-wt[i]];
                dp[i][k]=max(pick,npick);
            }
        }
        return dp[n-1][capacity];
    }
// space optimiaztion into 1d array
int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n=val.size();
        vector<int>curr(capacity+1,0);
        for(int k=wt[0];k<=capacity;k++){
            curr[k]=val[0]*(k/wt[0]);
        }
        for(int i=1;i<n;i++){
            for(int k=0;k<=capacity;k++){
                int npick=curr[k];
                int pick=0;
                if(k>=wt[i])
                    pick=val[i]+curr[k-wt[i]];
                curr[k]=max(pick,npick);
            }
        }
        return curr[capacity];
    }

// ROD CUTTING
// Given a rod of length n inches and an array price[], where price[i] denotes the value of a piece of length i. Your task is to determine the maximum value obtainable by cutting up the rod and selling the pieces.

// Note: n = size of price, and price[] is 1-indexed array.

// Example:

// Input: price[] = [1, 5, 8, 9, 10, 17, 17, 20]
// Output: 22
// Explanation: The maximum obtainable value is 22 by cutting in two pieces of lengths 2 and 6, i.e., 5 + 17 = 22.
int f(int i, int n, vector<int> &price, vector<vector<int>> &dp) {
    if (i == 0) return 0;
    if (dp[i][n] != -1) return dp[i][n];

    int npick = f(i - 1, n, price, dp);
    int pick = 0;
    if (n >= i)
        pick = price[i - 1] + f(i, n - i, price, dp);  // ✅ fix

    return dp[i][n] = max(pick, npick);
}

int cutRod(vector<int> &price) {
    int n = price.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return f(n, n, price, dp);
}

// tabulation
int cutRod(vector<int> &price) {
        int n=price.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int npick=dp[i-1][j];
                int pick=0;
                if(j>=i)
                    pick=price[i-1]+dp[i][j-i];
                dp[i][j]=max(pick,npick);
            }
        }
        return dp[n][n];
    }
// space optimization (convert into 1d arry)
int cutRod(vector<int> &price) {
        int n=price.size();
        vector<int>curr(n+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int npick=curr[j];
                int pick=0;
                if(j>=i)
                    pick=price[i-1]+curr[j-i];
                curr[j]=max(pick,npick);
            }
        }
        return curr[n];
    }