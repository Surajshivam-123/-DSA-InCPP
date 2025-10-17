#include<iostream>
#include <vector>
using namespace std;


// BUY AND SELL STOCK II
// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can sell and buy the stock multiple times on the same day, ensuring you never hold than one share of the stock.

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
        if (dp[i][trans]!= -1)
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