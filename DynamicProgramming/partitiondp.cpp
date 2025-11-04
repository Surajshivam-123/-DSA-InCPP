#include<iostream>
using namespace std;
// Rules for partition dp
// 1.start with entire block/array and represent them with i and j where i=starting point and j=ending point
// 2.try all partition using for loop
// 3.return best 2 possible partition

//Example: arr=[10,20,30,40,50]
//Matrices          A  B  C  D
// initially i=1 and j=4
// start with f(i,j)


// Matrix Chain Multiplication
// Given an array arr[] which represents the dimensions of a sequence of matrices where the ith matrix has the dimensions (arr[i-1] x arr[i]) for i>=1, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.

// Examples:

// Input: arr[] = [2, 1, 3, 4]
// Output: 20
// Explanation: There are 3 matrices of dimensions 2 × 1, 1 × 3, and 3 × 4, Let this 3 input matrices be M1, M2, and M3. There are two ways to multiply: ((M1 x M2) x M3) and (M1 x (M2 x M3)), note that the result of (M1 x M2) is a 2 x 3 matrix and result of (M2 x M3) is a 1 x 4 matrix. 
// ((M1 x M2) x M3)  requires (2 x 1 x 3) + (2 x 3 x 4) = 30 
// (M1 x (M2 x M3))  requires (1 x 3 x 4) + (2 x 1 x 4) = 20. 
// The minimum of these two is 20.
class Solution {
    int f(int i,int j,vector<int> &arr,vector<vector<int>>&dp){
        if(i==j){
            return 0;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<j;k++){
            int value=f(i,k,arr,dp)+f(k+1,j,arr,dp)+arr[i-1]*arr[j]*arr[k];
            ans=min(ans,value);
        }
        return dp[i][j]=ans;
    }
  public:
    int matrixMultiplication(vector<int> &arr) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(1,n-1,arr,dp);
    }
};

// Tabulation
class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                int ans=INT_MAX;
                for(int k=i;k<j;k++){
                    int value=dp[i][k]+dp[k+1][j]+arr[i-1]*arr[j]*arr[k];
                    ans=min(ans,value);
                }
                dp[i][j]=ans;
            }
        }
        return dp[1][n-1];
    }
};

// MINIMUM COST TO CUT STICK
// Given a wooden stick of length n units. The stick is labelled from 0 to n. For example, a stick of length 6 is labelled as follows:


// Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.

// You should perform the cuts in order, you can change the order of the cuts as you wish.

// The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer to the first example for a better explanation.

// Return the minimum total cost of the cuts.

 

// Example 1:


// Input: n = 7, cuts = [1,3,4,5]
// Output: 16
// Explanation: Using cuts order = [1, 3, 4, 5] as in the input leads to the following scenario:

// The first cut is done to a rod of length 7 so the cost is 7. The second cut is done to a rod of length 6 (i.e. the second part of the first cut), the third is done to a rod of length 4 and the last cut is to a rod of length 3. The total cost is 7 + 6 + 4 + 3 = 20.
// Rearranging the cuts to be [3, 5, 1, 4] for example will lead to a scenario with total cost = 16 (as shown in the example photo 7 + 4 + 3 + 2 = 16).
class Solution {
    int f(int i,int j,vector<int>& cuts,vector<vector<int>>&dp){
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=INT_MAX;
        for(int d=i;d<=j;d++){
            int value=cuts[j+1]-cuts[i-1]+f(i,d-1,cuts,dp)+f(d+1,j,cuts,dp);
            ans=min(ans,value);
        }
        return dp[i][j]=ans;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        int sze=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(sze+1,vector<int>(sze+1,-1));
        return f(1,sze,cuts,dp);
    }
};
// Time Complexity-O(m^2xm)=O(m^3)
// Space Complexity -O(mxm + stack space)

// tabulation
int minCost(int n, vector<int>& cuts) {
        int sze=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(sze+2,vector<int>(sze+2,0));
        for(int i=sze;i>=1;i--){
            for(int j=1;j<=sze;j++){
                if(i<=j){
                    int ans=INT_MAX;
                    for(int d=i;d<=j;d++){
                        int value=cuts[j+1]-cuts[i-1]+dp[i][d-1]+dp[d+1][j];
                        ans=min(ans,value);
                    }
                    dp[i][j]=ans;
                }
            }
        }
        return dp[1][sze];
    }

// BURST BALLOoN
// You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

// If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

// Return the maximum coins you can collect by bursting the balloons wisely.

 

// Example 1:

// Input: nums = [3,1,5,8]
// Output: 167
// Explanation:
// nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
// coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
// Example 2:

// Input: nums = [1,5]
// Output: 10
class Solution {
    int f(int i,int j,vector<int>& nums,vector<vector<int>>&dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=INT_MIN;
        for(int div=i;div<=j;div++){
            int val=nums[i-1]*nums[div]*nums[j+1]+f(i,div-1,nums,dp)+f(div+1,j,nums,dp);
            ans=max(ans,val);
        }
        return dp[i][j]=ans;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
       nums.insert(nums.begin(),1);
       nums.push_back(1);
       vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
       return f(1,n,nums,dp);
    }
};
// here are chossing element from bottom which makes the subproblem independent and we can solve then independently
// TC-O(NxNxN)
// SC-O(NxN)+stack space
// Tabulation
int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int i = n; i >= 1; i--) {
            for (int j = i; j <= n; j++) {
                int ans = INT_MIN;
                for (int div = i; div <= j; div++) {
                    int val = nums[i - 1] * nums[div] * nums[j + 1] +
                              dp[i][div - 1] + dp[div + 1][j];
                    ans = max(ans, val);
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][n];
    }

// Boolean Parenthesization
// Difficulty: HardAccuracy: 20.15%Submissions: 147K+Points: 8Average Time: 30m
// You are given a boolean expression s containing
//     'T' ---> true
//     'F' ---> false 
// and following operators between symbols
//    &   ---> boolean AND
//     |   ---> boolean OR
//    ^   ---> boolean XOR
// Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

// Note: The answer is guaranteed to fit within a 32-bit integer.

// Examples:

// Input: s = "T|T&F^T"
// Output: 4
// Explaination: The expression evaluates to true in 4 ways: ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).

// User function Template for C++
class Solution {
    int f(int i,int j,bool isTrue,string &s,vector<vector<vector<int>>>&dp){
        if(i==j){
            if(isTrue)return s[i]=='T';
            else return s[i]=='F';
        }
        if(dp[i][j][isTrue]!=-1)
            return dp[i][j][isTrue];
        int ans=0;
        for(int k=i+1;k<=j;k+=2){
            char op=s[k];
            int leftTrue=f(i,k-1,1,s,dp);
            int rightTrue=f(k+1,j,1,s,dp);
            int leftFalse=f(i,k-1,0,s,dp);
            int rightFalse=f(k+1,j,0,s,dp);
            if(op=='&'){
                if(isTrue)
                    ans+=leftTrue*rightTrue;
                else
                    ans+=leftFalse*rightFalse+leftFalse*rightTrue+leftTrue*rightFalse;
            }
            else if(op=='|'){
                if(isTrue)
                    ans+=leftTrue*rightTrue+leftFalse*rightTrue+leftTrue*rightFalse;
                else
                    ans+=leftFalse*rightFalse;
            }
            else{
                if(isTrue)
                    ans+=leftFalse*rightTrue+leftTrue*rightFalse;
                else
                    ans+=leftTrue*rightTrue+leftFalse*rightFalse;
            }
        }
        return dp[i][j][isTrue]=ans;
    }
  public:
    int countWays(string &s) {
        int n=s.length();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return f(0,n-1,1,s,dp);
        
    }
};
// TimeComplexity-O(NxNx2xN)~O(N^3)
// Space Complexity-O(N^3)+Stack Space


// FRONT PARTITION
// // Palindrome Partitioning
// Given a string s, partition s such that every substring of the partition is a palindrome.

// Return the minimum cuts needed for a palindrome partitioning of s.

 

// Example 1:

// Input: s = "aab"
// Output: 1
// Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.

class Solution {
    bool isPalindrome(int i,int j,string &s){
        while(i<j && s[i]==s[j]){
            i++;j--;
        }
        return i>=j;
    }
    int f(int i,string &s,vector<int>&dp){
        int n=s.length();
        if(i==n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int minCost=INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalindrome(i,j,s)){
                int cost=1+f(j+1,s,dp);
                minCost=min(minCost,cost);
            }
        }
        return dp[i]=minCost;
    }
public:
    int minCut(string s) {
        int n=s.length();
        vector<int>dp(n,-1);
        return f(0,s,dp)-1;
    }
};

// Partition array for maximum sum
// Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

// Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

 

// Example 1:

// Input: arr = [1,15,7,9,2,5,10], k = 3
// Output: 84
// Explanation: arr becomes [15,15,15,9,10,10,10]
class Solution {
    int f(int i,vector<int>& arr, int k,vector<int>&dp){
        int n=arr.size();
        if(i==n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int ans=0;
        int mx=0;
        for(int part=i;part<min(n,i+k);part++){
            mx=max(mx,arr[part]);
            int value=mx*(part-i+1)+f(part+1,arr,k,dp);
            ans=max(ans,value);
        }
        return dp[i]=ans;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n,-1);
        return f(0,arr,k,dp);
    }
};

// Count Square Submatrices with all ones 
// Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

// Example 1:

// Input: matrix =
// [
//   [0,1,1,1],
//   [1,1,1,1],
//   [0,1,1,1]
// ]
// Output: 15
// Explanation: 
// There are 10 squares of side 1.
// There are 4 squares of side 2.
// There is  1 square of side 3.
// Total number of squares = 10 + 4 + 1 = 15.
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        int ans=0;
        for(int i=0;i<m;i++){
            dp[i][0]=matrix[i][0];
            if(matrix[i][0])ans++;
        }
        for(int i=1;i<n;i++){
            dp[0][i]=matrix[0][i];
            if(matrix[0][i])ans++;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0)continue;
                vector<vector<int>>arr={{-1,-1},{0,-1},{-1,0}};
                int mn=301;
                for(auto v:arr){
                    mn=min(mn,dp[i+v[0]][j+v[1]]);
                }
                dp[i][j]=mn+1;
                ans+=dp[i][j];
                }
            }
        return ans;
    }
};