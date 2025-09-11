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
