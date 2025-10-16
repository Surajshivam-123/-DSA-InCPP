#include <iostream>
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

int f(int i1, int i2, string &text1, string &text2, vector<vector<int>> &dp)
{
    if (i1 < 0 || i2 < 0)
        return 0;
    if (dp[i1][i2] != -1)
        return dp[i1][i2];
    if (text1[i1] == text2[i2])
        return dp[i1][i2] = 1 + f(i1 - 1, i2 - 1, text1, text2, dp);
    return dp[i1][i2] = max(f(i1 - 1, i2, text1, text2, dp), f(i1, i2 - 1, text1, text2, dp));
}
int longestCommonSubsequence(string text1, string text2)
{
    int n1 = text1.length();
    int n2 = text2.length();
    vector<vector<int>> dp(n1, vector<int>(n2, -1));
    return f(n1 - 1, n2 - 1, text1, text2, dp);
}
// TC-O(n1*n2) SC-O(n1*n2 +(n1+n2)(memory stack))
// tabulation
int longestCommonSubsequence(string text1, string text2)
{
    int n1 = text1.length();
    int n2 = text2.length();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
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

// KEY CONCEPT
// In this Problem we will use 2d dp vector of previous array if same character is present in corresponding row and column and we go back diagonally else go to up or left if current dp value is same as up or down
class Solution
{
    vector<vector<int>> dp;
    vector<vector<set<string>>> memo;

    set<string> findLCS(int i, int j, string &s1, string &s2)
    {
        // Base case
        if (i == 0 || j == 0)
            return {""};

        // If already computed
        if (!memo[i][j].empty())
            return memo[i][j];

        set<string> result;

        if (s1[i - 1] == s2[j - 1])
        {
            // Characters match, append it to all LCS of smaller subproblem
            set<string> temp = findLCS(i - 1, j - 1, s1, s2);
            for (auto &x : temp)
                result.insert(x + s1[i - 1]);
        }
        else
        {
            // Move to direction(s) where dp is equal (keep all possibilities)
            if (dp[i - 1][j] >= dp[i][j - 1])
            {
                set<string> top = findLCS(i - 1, j, s1, s2);
                result.insert(top.begin(), top.end());
            }
            if (dp[i][j - 1] >= dp[i - 1][j])
            {
                set<string> left = findLCS(i, j - 1, s1, s2);
                result.insert(left.begin(), left.end());
            }
        }

        return memo[i][j] = result;
    }

public:
    vector<string> allLCS(string &text1, string &text2)
    {
        int n1 = text1.size(), n2 = text2.size();

        dp.assign(n1 + 1, vector<int>(n2 + 1, 0));
        memo.assign(n1 + 1, vector<set<string>>(n2 + 1));

        // Build LCS length table
        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        set<string> res = findLCS(n1, n2, text1, text2);

        vector<string> ans;
        for (auto &x : res)
        {
            ans.push_back(x);
        }

        return ans;
    }
};
// LONGEST PALINDROMIC STRING
// Given a string s, find the longest palindromic subsequence's length in s.

// A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
// Example 1:

// Input: s = "bbbab"
// Output: 4
// Explanation: One possible longest palindromic subsequence is "bbbb".
// KEY CONCEPT-Just reverse the string and find longest common subsequence from them
int longestPalindromeSubseq(string s1)
{
    int n1 = s1.length();
    string s2 = string(s1.rbegin(), s1.rend());
    vector<int> prev(n1 + 1, 0), curr(n1 + 1, 0);
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                curr[j] = 1 + prev[j - 1];
            }
            else
            {
                curr[j] = max(prev[j], curr[j - 1]);
            }
        }
        prev = curr;
    }
    return prev[n1];
}

// LOWEST COMMON SUBSTRING
// You are given two strings s1 and s2. Your task is to find the length of the longest common substring among the given strings.

// Examples:

// Input: s1 = "ABCDGH", s2 = "ACDGHR"
// Output: 4
// Explanation: The longest common substring is "CDGH" with a length of 4.
int longestCommonSubstr(string &s1, string &s2)
{
    int n1 = s1.length();
    int n2 = s2.length();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    int ans = 0;
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return ans;
}

// Minimum Insertions/Deletions to Convert String A to String B
// Given a string s. In one step you can insert any character at any index of the string.

// Return the minimum number of steps to make s palindrome.

// A Palindrome String is one that reads the same backward as well as forward.

// Example 1:

// Input: s = "zzazz"
// Output: 0
// Explanation: The string "zzazz" is already palindrome we do not need any insertions.
int minInsertions(string s1)
{
    int n1 = s1.length();
    string s2 = string(s1.rbegin(), s1.rend());
    vector<int> prev(n1 + 1, 0), curr(n1 + 1, 0);
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                curr[j] = 1 + prev[j - 1];
            }
            else
            {
                curr[j] = max(prev[j], curr[j - 1]);
            }
        }
        prev = curr;
    }
    return n1 - prev[n1];
}

// SHORTEST COMMON SUBSEQUENCE
// Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

// A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

// Example 1:

// Input: str1 = "abac", str2 = "cab"
// Output: "cabac"
// Explanation:
// str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
// str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
// The answer provided is the shortest such string that satisfies these properties.
// KEY CONCEPT
// We will use dp array to find the string
// starting with bottom right corner and traverse diagonally if string matches else go maximum side;
string shortestCommonSupersequence(string str1, string str2)
{
    int n1 = str1.length();
    int n2 = str2.length();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    string ans;
    int i = n1, j = n2;
    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            ans += str1[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            ans += str1[i - 1];
            i--;
        }
        else
        {
            ans += str2[j - 1];
            j--;
        }
    }
    while (j > 0)
    {
        ans += str2[j - 1];
        j--;
    }
    while (i > 0)
    {
        ans += str1[i - 1];
        i--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// DISTINCT SUBSEQUENCE
// Given two strings s and t, return the number of distinct subsequences of s which equals t.

// The test cases are generated so that the answer fits on a 32-bit signed integer.

// Example 1:

// Input: s = "rabbbit", t = "rabbit"
// Output: 3
// Explanation:
// As shown below, there are 3 ways you can generate "rabbit" from s.
// rabbbit
// rabbbit
// rabbbit

// STEP 1-express everything in terms of i and j;
// STEP 2-explore all possibilities
// STEP 3-return summation
// BASE CASE-if index of string t goes till -1 then it means we had get one subsequence so return 1 and else if index of string becomes -1 then return 0;
int f(int i1, int i2, string &s, string &t, vector<vector<int>> &dp)
{
    if (i2 < 0)
        return 1;
    if (i1 < 0)
        return 0;
    if (dp[i1][i2] != -1)
        return dp[i1][i2];
    if (s[i1] == t[i2])
        return dp[i1][i2] = f(i1 - 1, i2 - 1, s, t, dp) + f(i1 - 1, i2, s, t, dp);
    return dp[i1][i2] = f(i1 - 1, i2, s, t, dp);
}
int numDistinct(string s, string t)
{
    int n1 = s.length(), n2 = t.length();
    vector<vector<int>> dp(n1, vector<int>(n2, -1));
    return f(n1 - 1, n2 - 1, s, t, dp);
}
// tabulation
int numDistinct(string s, string t)
{
    int n1 = s.length(), n2 = t.length();
    vector<vector<double>> dp(n1 + 1, vector<double>(n2 + 1, 0));
    for (int i = 0; i <= n1; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return (int)dp[n1][n2];
}
// space optimization 2 array
int numDistinct(string s, string t)
{
    int n1 = s.length(), n2 = t.length();
    vector<double> prev(n2 + 1, 0), curr(n2 + 1, 0);
    prev[0] = curr[0] = 1;
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (s[i - 1] == t[j - 1])
                curr[j] = prev[j - 1] + prev[j];
            else
                curr[j] = prev[j];
        }
        prev = curr;
    }
    return (int)prev[n2];
}
// 1 array
int numDistinct(string s, string t)
{
    vector<double> dp(t.length() + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= s.length(); i++)
    {
        for (int j = t.length(); j >= 1; j--)
        {
            if (s[i - 1] == t[j - 1])
                dp[j] += dp[j - 1];
        }
    }
    return (int)dp[t.length()];
}

// EDIT DISTANCE
// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

// You have the following three operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character

// Example 1:

// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation:
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')
int f(int i, int j, string &word1, string &word2, vector<vector<int>> &dp)
{
    if (j < 0)
        return i + 1;
    if (i < 0)
        return j + 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (word1[i] == word2[j])
        return f(i - 1, j - 1, word1, word2, dp);
    int value1 = 1 + f(i, j - 1, word1, word2, dp);     // insert one char which matches with char of word2 so shrink word2 and word1 will remain as it is
    int value2 = 1 + f(i - 1, j, word1, word2, dp);     // delete unmatched char of word1;
    int value3 = 1 + f(i - 1, j - 1, word1, word2, dp); // replace unmarched char with matched character
    return dp[i][j] = min(value1, min(value2, value3)); // return minimum of all
}
int minDistance(string word1, string word2)
{
    int n1 = word1.length(), n2 = word2.length();
    vector<vector<int>> dp(n1, vector<int>(n2, -1));
    return f(n1 - 1, n2 - 1, word1, word2, dp);
}

// tabulation
int minDistance(string word1, string word2)
{
    int n1 = word1.length(), n2 = word2.length();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    for (int i = 1; i <= n2; i++)
    {
        dp[0][i] = i;
    }
    for (int i = 1; i <= n1; i++)
    {
        dp[i][0] = i;
    }
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }
        }
    }
    return dp[n1][n2];
}

// WILDCARD MATCHING
// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).

 

// Example 1:

// Input: s = "aa", p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".

bool f(int i,int j,string &s, string &p,vector<vector<int>>&dp){
        if(i==-1){
            while(j!=-1){
                if(p[j]!='*')
                    return false;
                j--;
            }
            return true;
        }
        if(j==-1)return false;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j]=f(i-1,j-1,s,p,dp);
        }
        if(p[j]=='*'){
            return dp[i][j]=f(i,j-1,s,p,dp) | f(i-1,j,s,p,dp);
        }
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int n1=s.length(),n2=p.length();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return f(n1-1,n2-1,s,p,dp);
    }

// tabulation
bool isMatch(string s, string p) {
        int n1 = s.length(), n2 = p.length();
        vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));
        dp[0][0]=true;
        for (int i = 1; i <= n2; i++) {
            if (p[i-1] != '*')
                break;
            dp[0][i] = true;
        }
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
                }
            }
        }
        return dp[n1][n2];
    }

// space optimization
bool isMatch(string s, string p) {
        int n1 = s.length(), n2 = p.length();
        vector<bool> prev(n2 + 1, false);
        prev[0] = true;
        for (int i = 1; i <= n2; i++) {
            if (p[i - 1] != '*')
                break;
            prev[i] = true;
        }
        for (int i = 1; i <= n1; i++) {
            vector<bool> curr(n2 + 1, false);
            for (int j = 1; j <= n2; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    curr[j] = prev[j - 1];
                } else if (p[j - 1] == '*') {
                    curr[j] = curr[j - 1] | prev[j];
                }
            }
            prev = curr;
        }
        return prev[n2];
    }