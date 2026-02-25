#include<iostream>
#include <vector>
using namespace std;
// Problem statement
// There is a frog on the '1st' step of an 'N' stairs long staircase. The frog wants to reach the 'Nth' stair. 'HEIGHT[i]' is the height of the '(i+1)th' stair.If Frog jumps from 'ith' to 'jth' stair, the energy lost in the jump is given by absolute value of ( HEIGHT[i-1] - HEIGHT[j-1] ). If the Frog is on 'ith' staircase, he can jump either to '(i+1)th' stair or to '(i+2)th' stair. Your task is to find the minimum total energy used by the frog to reach from '1st' stair to 'Nth' stair.

// For Example
// If the given ‘HEIGHT’ array is [10,20,30,10], the answer 20 as the frog can jump from 1st stair to 2nd stair (|20-10| = 10 energy lost) and then a jump from 2nd stair to last stair (|10-20| = 10 energy lost). So, the total energy lost is 20.
int solve(vector<int>height,vector<int>&dp,int ind){
    if(ind==0)return 0;
    if(dp[ind]!=-1)return dp[ind];
    int left=solve(height,dp,ind-1)+abs(height[ind]-height[ind-1]);
    int  right=INT16_MAX;
    if(ind>1)
        right=solve(height,dp,ind-2)+abs(height[ind]-height[ind-2]);
    return dp[ind]=min(left,right);
}



//solving recursion problem from tabulation
int tabulation(int n,vector<int>&height){
    vector<int>dp(n,0);
    dp[0]=0;
    for(int i=1;i<n;i++){
        int left=dp[i-1]+abs(height[i]-height[i-1]);
        int right=INT16_MAX;
        if(i>1)
            right=dp[i-2]+abs(height[i]-height[i-2]);
        dp[i]=min(left,right);
    }
    return dp[n-1];
}


//Now remove dp array and use variable
 int tabulationv(int n,vector<int>&height){
    int prev=0;
    int prev2=0;
    for(int i=1;i<n;i++){
        int left=prev+abs(height[i]-height[i-1]);
        int right=INT16_MAX;
        if(i>1)
            right=prev2+abs(height[i]-height[i-2]);
        int curi=min(left,right);
        prev2=prev;
        prev=curi;
    }
    return prev;
 }

//Frog with upto k jumps
int f(vector<int>heights,vector<int>dp,int k,int in){
    if(in==0)return 0;
    if(dp[in]!=-1)return dp[in];
    int mine=INT16_MAX;
    for(int i=1;i<=k;i++){
        if((in-i)>=0){
            int energy=f(heights,dp,k,in-i)+abs(heights[in]-heights[in-i]);
            mine=min(energy,mine);
        }
        else break;
    }
    return dp[in]=mine;
}

//solving recursion problem from tabulation
int solve(vector<int>heights,int k){
    int n=heights.size();
    vector<int>dp(n+1,0);
    dp[0]=0;
    for(int i=1;i<n;i++){
        int mine=INT16_MAX;
        for(int j=1;j<=k;j++){
            if((i-j)>=0){
                int energy=dp[i-j]+abs(heights[i]-heights[i-j]);
                mine=min(mine,energy);
            }
            else break;
        }
        dp[i]=mine;
    }
    return dp[n-1];
}

int main(){
    int n=8;
    vector<int>height={7,4,4,2,6,6,3,4};
    vector<int>dp(n+1,-1);
    cout<<solve(height,dp,7)<<endl;
    cout<<tabulation(7,height)<<endl;
    cout<<tabulationv(7,height)<<endl;
}

// BUY AND SELL STOCK II
// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock.

// Find and return the maximum profit you can achieve.

 

// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 7
// Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
// Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
// Total profit is 4 + 3 = 7.

// Steps
// 1.express everything in terms of index and also carry buy flag to tell whether you can buy or not
// 2.explore all possibiity on that day
// 3.take the maximum profit
// 3.base case

int f(int i,bool buy,vector<int>& prices,vector<vector<int>>&dp){
        int n=prices.size();
        if(i==(n-1)){
            if(buy)
                return prices[n-1];
            return 0;
        }
        if(dp[i][buy]!=-1)
            return dp[i][buy];
        int value1=-1,value2=-1,value3;
        // nothing
        value3=f(i+1,buy,prices,dp);
        // buy
        if(!buy)
            value1=f(i+1,true,prices,dp)-prices[i];
        // sell
        else
            value2=f(i+1,false,prices,dp)+prices[i];
        return dp[i][buy]=max(value1,max(value2,value3));
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,false,prices,dp);
    }


// BEST TO BUY AND SEL STOCK III
// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// Find the maximum profit you can achieve. You may complete at most two transactions.

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

// Example 1:

// Input: prices = [3,3,5,0,0,3,1,4]
// Output: 6
// Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
// Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

int f(int i, bool buyAllow, int cap, vector<int>& prices,
          vector<vector<vector<int>>>& dp) {
        if (i == prices.size() || cap == -1)
            return 0;
        if (dp[i][buyAllow][cap] != -1)
            return dp[i][buyAllow][cap];
        // either buy or not buy and transaction does not complete during buying
        if (buyAllow)
            return dp[i][buyAllow][cap] =
                       max(-prices[i] + f(i + 1, false, cap, prices, dp),
                           f(i + 1, true, cap, prices, dp));
        else // sell
            return dp[i][buyAllow][cap] =
                       max(prices[i] + f(i + 1, true, cap - 1, prices, dp),
                           f(i + 1, false, cap, prices, dp));
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(2, -1)));
        return f(0, true, 1, prices, dp);
    }

//tabulation
int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {
                    if (buy)
                        dp[i][buy][cap] =
                                   max(-prices[i] +
                                           dp[i + 1][0][cap],
                                       dp[i + 1][1][cap]);
                    else // sell
                        dp[i][buy][cap] =
                                   max(prices[i] +
                                           dp[i + 1][1][cap - 1],
                                       dp[i + 1][0][cap]);
                }
            }
        }
        return dp[0][1][2];
    } 

// Using Nx4 space complexity
int f(int i, int trans, vector<int>& prices,
          vector<vector<int>>& dp) {
        if (i == prices.size() || trans==4)
            return 0;
        if (dp[i][tpermutationrans]!= -1)
            return dp[i][trans];
        // either buy or not buy and transaction does not complete during buying
        if (trans%2==0)
            return dp[i][trans] =
                       max(-prices[i] + f(i + 1,trans+1, prices, dp),
                           f(i + 1,trans, prices, dp));
        else // sell
            return dp[i][trans] =
                       max(prices[i] + f(i + 1,trans+1, prices, dp),
                           f(i + 1,trans, prices, dp));
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(
            n,vector<int>(4, -1));
        return f(0,0, prices, dp);
    }

// BEST TO BUY AND SEL STOCK IV
// You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

// Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

// Example 1:

// Input: k = 2, prices = [2,4,1]
// Output: 2
// Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

int f(int i, bool buyAllow, int cap, vector<int>& prices,
          vector<vector<vector<int>>>& dp) {
        if (i == prices.size() || cap == -1)
            return 0;
        if(dp[i][buyAllow][cap]!=-1)
            return dp[i][buyAllow][cap];
        if (buyAllow)
            return dp[i][buyAllow][cap] =
                       max(-prices[i] + f(i + 1, false, cap, prices, dp),
                           f(i + 1, true, cap, prices, dp));
        else // sell
            return dp[i][buyAllow][cap] =
                       max(prices[i] + f(i + 1, true, cap - 1, prices, dp),
                           f(i + 1, false, cap, prices, dp));
    }
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(
        n, vector<vector<int>>(2, vector<int>(k, -1)));
    return f(0, true, k - 1, prices, dp);
}

// Another Method
int f(int i,int trans, vector<int>& prices,
          vector<vector<int>>& dp,int k) {
        if (i == prices.size() || trans == 2*k)
            return 0;
        if (dp[i][trans] != -1)
            return dp[i][trans];
        if (trans%2==0)
            return dp[i][trans] =
                       max(-prices[i] + f(i + 1,trans+1, prices, dp,k),
                           f(i + 1,trans, prices, dp,k));
        // sell
            return dp[i][trans] =
                       max(prices[i] + f(i + 1,trans+1, prices, dp,k),
                           f(i + 1,trans, prices, dp,k));
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(
            n, vector<int>(2*k,-1));
        return f(0,0, prices, dp,k);
    }
    // BEST TO BUY AND SEL STOCK V
    // https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v/solutions/6821355/recursion-memo-magic-3d-dp-knapsack-in-o-n-k-to-o-k-space-optimized/


    // Longest Increasing subsequence
    // Given an integer array nums, return the length of the longest strictly increasing subsequence.

 

// Example 1:

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

// One Method TC-O(NxN)
class Solution {
    int f(int i,int parent,vector<int>& nums,vector<vector<int>>&dp){
        if(i==nums.size()){
            return 0;
        }
        if(dp[i][parent]!=-1)
            return dp[i][parent];
        int take=0;
        if(parent==0 || nums[parent-1]<nums[i])
            take=1+f(i+1,i+1,nums,dp);
        int ntake=f(i+1,parent,nums,dp);
        return dp[i][parent]=max(take,ntake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(0,0,nums,dp);
    }
};

// tabulation
 int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,0));
        dp[n-1][0]=1;
        for(int i=1;i<=n;i++){
            dp[n-1][i]=(int)(nums[n-1]>nums[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            for(int j=n;j>=0;j--){
                int take=0;
                if(j==0 || nums[j-1]<nums[i]){
                    take=1+dp[i+1][i+1];
                }
                int ntake=dp[i+1][j];
                dp[i][j]=max(take,ntake);
            }
        }
        return dp[0][0];
    }

// Another Method Space complexity optimization
// Compare all current with previos element
int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        int ans=1;
        for(int i=1;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i]){
                    dp[i]=max(dp[i],1+dp[prev]);
                    ans=max(ans,dp[i]);
                }
            }
        }
        return ans;
    }

// Print Longest Increasing Subsequence
// Difficulty: MediumAccuracy: 51.81%Submissions: 47K+Points: 4Average Time: 20m
// You are given an array of integers arr[], return the Longest Increasing Subsequence (LIS) of the given array.
// LIS is the longest subsequence where each element is strictly greater than the previous one.
// Note: If multiple LIS of the same maximum length exist, return the one that appears first based on the lexicographical order of their indices (i.e., the earliest combination of positions from the original sequence).

// Examples:

// Input: arr[] = [10, 20, 3, 40]
// Output: [10, 20, 40]
// Explanation: [10, 20, 40] is the longest subsequence where each number is greater than the previous one, maintaining the original order.
vector<int> getLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(n,1);
        vector<int>ans;
        vector<int>hash(n);
        int cnt=1;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(arr[prev]<arr[i] && dp[i]<(1+dp[prev])){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            cnt=max(cnt,dp[i]);
        }
        int in=-1;
        for(int i=0;i<n;i++){
            if(dp[i]==cnt){
                in=i;
                break;
            }
        }
        while(cnt--){
            ans.push_back(arr[in]);
            in=hash[in];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

// longest divisible subset
// Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

// answer[i] % answer[j] == 0, or
// answer[j] % answer[i] == 0
// If there are multiple solutions, return any of them.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [1,2]
// Explanation: [1,3] is also accepted.
 vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>hash(n);
        sort(nums.begin(),nums.end());
        int cnt=1;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if((nums[prev]%nums[i]==0 || nums[i]%nums[prev]==0) && dp[i]<(1+dp[prev])){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            cnt=max(cnt,dp[i]);
        }
        int in=-1;
        for(int i=0;i<n;i++){
            if(cnt==dp[i]){
                in=i;
                break;
            }
        }
        vector<int>ans;
        while(cnt--){
            ans.push_back(nums[in]);
            in=hash[in];
        }
        return ans;
    }

    // LONGEST STRING CHAIN
// You are given an array of words where each word consists of lowercase English letters.

// wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

// For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
// A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

// Return the length of the longest possible word chain with words chosen from the given list of words.

 

// Example 1:

// Input: words = ["a","b","ba","bca","bda","bdca"]
// Output: 4
// Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
class Solution {
    bool check(string small,string large){
        int len1=0,len2=0;
        while(len2!=large.size()){
            if(small[len1]==large[len2]){
                len1++;
            }
            len2++;
        }
        return len1==small.size();
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),[&](string a,string b){
            return a.length()<b.length();
        });
        int ans=1;
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            int len=words[i].length();
            for(int prev=0;prev<i;prev++){
                if(words[prev].length()==len-1){
                    if(check(words[prev],words[i]) && dp[i]<(1+dp[prev])){
                        dp[i]=1+dp[prev];
                    }
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};

// NUMBER OF LONGEST INCREASING SUBSEQUENCE
// Given an integer array nums, return the number of longest increasing subsequences.

// Notice that the sequence has to be strictly increasing.

 

// Example 1:

// Input: nums = [1,3,5,4,7]
// Output: 2
// Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1),cnt(n,1);
        int mx=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && dp[i]<1+dp[j]){
                    dp[i]=1+dp[j];
                    cnt[i]=cnt[j];
                }
                else if(nums[j]<nums[i] && (1+dp[j])==dp[i]){
                    cnt[i]+=cnt[j];
                }
            }
            mx=max(mx,dp[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]==mx){
                ans+=cnt[i];
            }
        }
        return ans;
        
    }

// filling bookcashshelves 
// You are given an array books where books[i] = [thicknessi, heighti] indicates the thickness and height of the ith book. You are also given an integer shelfWidth.

// We want to place these books in order onto bookcase shelves that have a total width shelfWidth.

// We choose some of the books to place on this shelf such that the sum of their thickness is less than or equal to shelfWidth, then build another level of the shelf of the bookcase so that the total height of the bookcase has increased by the maximum height of the books we just put down. We repeat this process until there are no more books to place.

// Note that at each step of the above process, the order of the books we place is the same order as the given sequence of books.

// For example, if we have an ordered list of 5 books, we might place the first and second book onto the first shelf, the third book on the second shelf, and the fourth and fifth book on the last shelf.
// Return the minimum possible height that the total bookshelf can be after placing shelves in this manner.

 

// Example 1:


// Input: books = [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]], shelfWidth = 4
// Output: 6
// Explanation:
// The sum of the heights of the 3 shelves is 1 + 3 + 2 = 6.
// Notice that book number 2 does not have to be on the first shelf.
class Solution {
    int f(int i, int remWidth, int maxHeight, vector<vector<int>>& books, vector<vector<int>>& memo) {
        // Base case: processed all books
        if (i == books.size()) {
            return maxHeight;
        }
        
        if (memo[i][remWidth] != -1) {
            return memo[i][remWidth];
        }
        int thickness = books[i][0];
        int height = books[i][1];
        int result = INT_MAX;
        // Option 1: Place book on current shelf (if it fits)
        if (remWidth >= thickness) {
            result = f(i + 1, remWidth - thickness, max(maxHeight, height), books, memo);
        }
        // Option 2: Start a new shelf with this book
        int newShelf = maxHeight + f(i + 1, shelfWidth - thickness, height, books, memo);
        return memo[i][remWidth] = min(result, newShelf);
    }
    
    int shelfWidth;
    
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        this->shelfWidth = shelfWidth;
        int n = books.size();
        vector<vector<int>> memo(n, vector<int>(shelfWidth + 1, -1));
        return f(0, shelfWidth, 0, books, memo);
    }
};