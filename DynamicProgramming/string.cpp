#include<iostream>
using namespace std;
// Key Concepts
// Subsequences:

// A subsequence is a sequence derived by deleting some or no elements from the original string without changing the order.
// Longest Common Subsequence (LCS):

// Find the maximum-length subsequence common to two strings.
// Approaches Covered
// Brute Force:

// Recursive exploration of all subsequences.
// Exponential complexity, impractical for larger inputs.
// Recurrence Relation:

// If characters match: 
// LCS(i,j)=1+LCS(i−1,j−1)
// If characters don't match: 
// LCS(i,j)=max(LCS(i−1,j),LCS(i,j−1))
// Memoization:
// Store intermediate results to avoid redundant calculations.
// Reduces complexity to 
// O(n×m).
// Tabulation:

// Iterative table-building approach.
// Base cases: 
// LCS(0,j)=0 and
// LCS(i,0)=0.
// Space Optimization:

// Reduce O(n×m) space to O(2×m) using rolling arrays.
// Steps to Solve
// Understand the Problem:

// Identify matching and non-matching cases.
// Formulate recurrence relations.
// Recursive Approach:

// Use recursion tree to visualize overlapping subproblems.
// Memoization:

// Implement 
// dp[i][j]
// dp[i][j] to store results for i and j indices.
// Tabulation:

// Shift indexes for iterative table-building.
// Space Optimization:

// Use two arrays for current and previous rows.
// Code Implementation
// Recursive Solution:

// Base cases: if any of index will go to -1 return 0

// Recursive calls based on recurrence relations.
// Memoization:

// Add dp table to store results and avoid redundant computations.
// Tabulation:

// Fill dp table iteratively using loops.
// Optimized:

// Use rolling arrays for space-efficient tabulation

// PROBLEM STATEMENT
// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings

// Example 1:

// Input: text1 = "abcde", text2 = "ace" 
// Output: 3

int f(int i1,int i2,string &text1,string &text2,vector<vector<int>>&dp){
        if(i1<0 || i2<0)
            return 0;
        if(dp[i1][i2]!=-1)
            return dp[i1][i2];
        if(text1[i1]==text2[i2])
            return dp[i1][i2]=1+f(i1-1,i2-1,text1,text2,dp);
        return dp[i1][i2]=max(f(i1-1,i2,text1,text2,dp),f(i1,i2-1,text1,text2,dp));
    }
int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.length();
        int n2=text2.length();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return f(n1-1,n2-1,text1,text2,dp);
}
// TC-O(n1*n2) SC-O(n1*n2 +(n1+n2)(memory stack)) 
// tabulation
int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.length();
        int n2=text2.length();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
                    
            }
        }
        return dp[n1][n2];
    }
// PRINT LONGEST COMMON SUBSEQUENCE
// You are given two strings s1 and s2. Your task is to print all distinct longest common subsequences in lexicographical order.

// Note: A subsequence is derived from another string by deleting some or none of the elements without changing the order of the remaining elements.

// Examples:

// Input: s1 = "abaaa", s2 = "baabaca"
// Output: ["aaaa", "abaa", "baaa"]
// Explanation: Length of lcs is 4, in lexicographical order they are "aaaa", "abaa", "baaa".
// In this Problem we will use 2d dp vector of previous array if same character is present in corresponding row and column and we go back diagonally else go to up or left if current dp value is same as up or down
class Solution {
    vector<vector<int>> dp;
    vector<vector<set<string>>> memo;

    set<string> findLCS(int i, int j, string &s1, string &s2) {
        // Base case
        if (i == 0 || j == 0) return {""};

        // If already computed
        if (!memo[i][j].empty()) return memo[i][j];

        set<string> result;

        if (s1[i-1] == s2[j-1]) {
            // Characters match, append it to all LCS of smaller subproblem
            set<string> temp = findLCS(i-1, j-1, s1, s2);
            for (auto &x : temp)
                result.insert(x + s1[i-1]);
        } else {
            // Move to direction(s) where dp is equal (keep all possibilities)
            if (dp[i-1][j] >= dp[i][j-1]) {
                set<string> top = findLCS(i-1, j, s1, s2);
                result.insert(top.begin(), top.end());
            }
            if (dp[i][j-1] >= dp[i-1][j]) {
                set<string> left = findLCS(i, j-1, s1, s2);
                result.insert(left.begin(), left.end());
            }
        }

        return memo[i][j] = result;
    }

public:
    vector<string> allLCS(string &text1, string &text2) {
        int n1 = text1.size(), n2 = text2.size();

        dp.assign(n1 + 1, vector<int>(n2 + 1, 0));
        memo.assign(n1 + 1, vector<set<string>>(n2 + 1));

        // Build LCS length table
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        set<string> res = findLCS(n1, n2, text1, text2);

        vector<string> ans;
        for (auto &x : res) {
            ans.push_back(x);
        }

        return ans;
    }
};
