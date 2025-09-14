#include<iostream>
using namespace std;
/*
How to find given question is solve by dp
-count the total number of ways
-find min and max of among all ways
-try all posssible ways

Three imp points
1.)Try to represent the problem in terms of index
2.)Do all possible stuffs on that acc to the problem statement
3.)sum of all stuffs->give output no. of ways
    min of all stuffs->find min
    */
/*Q.)we have stair and you can only climb once or twice step at once .You need to find total number of distinct ways to reach the top*/
int solve(int index){
    if(index==1 || index==0){
        return 1;
    }
    int left,right;
    left=solve(index-1);
    right=solve(index-2);
    return left +right;
}
int main(){
    cout<<solve(5)<<endl;
return 0;
}
// MAXIMUM ADJACENT ELEMENTS
/*Given an array arr containing positive integers. Find the maximum sum of elements of any possible subsequence such that no two numbers in the subsequence should be adjacent in array arr[].
Input: arr[] = [5, 5, 10, 100, 10, 5]
Output: 110
Explanation: If you take indices 0, 3 and 5, then = 5+100+5 = 110.*/

// User function template for C++
class Solution {
  public:
//   solve by recursion
    int solve(vector<int>& arr,vector<int>&dp,int in){
        if(in<0){
            return 0;
        }
        int pick,npick;
        pick=arr[in]+solve(arr,dp,in-2);
        npick=solve(arr,dp,in-1);
        return dp[in]=max(pick,npick);
    }
// solve by dynamic programming(Memoization)
    int solve(vector<int>& arr,vector<int>&dp,int in){
        if(in<0){
            return 0;
        }
        int pick,npick;
        if(in-2>=0 && dp[in-2]!=-1){
            pick=arr[in]+dp[in-2];
        }
        else{
            pick=arr[in]+solve(arr,dp,in-2);
        }
        if(in-1>=0 && dp[in-1]!=-1){
            npick=dp[in-1];
        }
        else{
            npick=solve(arr,dp,in-1);
        }
        return dp[in]=max(pick,npick);
    }
    int findMaxSum(vector<int>& arr) {
      vector<int>dp(arr.size(),-1);
      return solve(arr,dp,arr.size()-1);
    }
    // tabulation
    int findMaxSum(vector<int>& arr) {
      vector<int>dp(arr.size());
      dp[0]=arr[0];
      for(int i=1;i<dp.size();i++){
          int pick=0,npick=0;
          pick=arr[i]+((i-2)>=0?dp[i-2]:0);
          npick=(i-1)>=0?dp[i-1]:0;
          dp[i]=max(pick,npick);
      }
      return dp[arr.size()-1];
    }
    //space optimization
    int findMaxSum(vector<int>& arr) {
      int prev1=arr[0];
      int prev2=-1;
      for(int i=1;i<arr.size();i++){
          int pick=arr[i]+((prev2!=-1)?prev2:0);
          int npick=prev1;
          prev2=prev1;
          prev1=max(pick,npick);
      }
     return prev1;
    }
};

// HOUSE ROBBER
/*You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        int cur1=0,prev11=0,prev12=0;
        int cur2=0,prev21=0,prev22=0;
        prev11=nums[0];
        for(int i=1;i<nums.size()-1;i++){
            cur1=max(nums[i]+(i>1?prev12:0),prev11);
            prev12=prev11;
            prev11=cur1;
        }
        prev21=nums[1];
        for(int i=2;i<nums.size();i++){
            cur2=max(nums[i]+(i>1?prev22:0),prev21);
            prev22=prev21;
            prev21=cur2;
        }
        return max(prev11,prev21);
    }
};

/*Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities. (Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day. As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days. Can you help Ninja find out the maximum merit points Ninja can earn?

You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. Your task is to calculate the maximum number of merit points that Ninja can earn.
Sample Input 1:
3
1 2 5 
3 1 1
3 3 3
O/P-11
For the first test case,
One of the answers can be:
On the first day, Ninja will learn new moves and earn 5 merit points. 
On the second day, Ninja will do running and earn 3 merit points. 
On the third day, Ninja will do fighting and earn 3 merit points. 
The total merit point is 11 which is the maximum. 
Hence, the answer is 11.
*/

int solve(vector<vector<int>>&arr,vector<vector<int>>&dp,int n,int act){
    if(n==arr.size()){
        return 0;
    }
    int mx=0;
    for(int i=0;i<3;i++){
        if(i!=act){
            if(dp[n+1][i]!=-1){
                mx=max(mx,dp[n+1][i]+arr[n][i]);
            }
            else{
                mx=max(mx,solve(arr,dp,n+1,i)+arr[n][i]);
            }
        }
    }
    return dp[n][act]=mx;
}
int ninjaTraining(int n,vector<vector<int>>&arr){
    vector<vector<int>>dp(n+1,vector<int>(4,-1));
    return solve(arr,dp,0,3);
}

// Tabulation
int ninjaTraining(int n,vector<vector<int>>&arr){
    vector<vector<int>>dp(n+1,vector<int>(3));
    for(int i=0;i<3;i++){
        dp[0][i]=arr[0][i];
    }
    for(int i=1;i<n;i++){
        dp[i][0]=arr[i][0]+max(dp[i-1][1],dp[i-1][2]);
        dp[i][1]=arr[i][1]+max(dp[i-1][0],dp[i-1][2]);
        dp[i][2]=arr[i][2]+max(dp[i-1][0],dp[i-1][1]);
    }
    return max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
}
// Space optimization
int ninjaTraining(int n,vector<vector<int>>&arr){
    int prev1=arr[0][0],prev2=arr[0][1],prev3=arr[0][2];
    for(int i=1;i<n;i++){
        int curr1=arr[i][0]+max(prev2,prev3);
        int curr2=arr[i][1]+max(prev1,prev3);
        int curr3=arr[i][2]+max(prev1,prev2);
        prev1=curr1;
        prev2=curr2;
        prev3=curr3;
    }
    return max(prev1,max(prev2,prev3));
}

/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: m = 3, n = 7
Output: 28*/
int solve(int m,int n,vector<vector<int>>&dp){
    if(m==0 || n==0){
        return 1;
    }
    if(dp[m][n]!=-1){
        return dp[m][n];
    }
    return dp[m][n]=solve(m-1,n,dp)+solve(m,n-1,dp);
}
int uniquePaths(int m, int n) {
    vector<vector<int>>dp(m,vector<int>(n,-1));
    return solve(m-1,n-1,dp);
}

// tabulation
