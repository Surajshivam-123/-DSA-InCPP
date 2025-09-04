#include<iostream>
#include<vector>
using namespace std;
// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

// brute-force
int maxProfit_bruteforce(vector<int>& prices) {
    int n=prices.size();
    int profit,maxprofit=INT16_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            profit=prices[j]-prices[i];
            maxprofit=max(profit,maxprofit);
        }
    }
    if(maxprofit<0){
        return 0;
    }
    return maxprofit;    
    }

//best
int maxProfit(vector<int>& prices) {
    int minp=INT16_MAX;
    int profit,maxprofit=0;
    for(int i=0;i<prices.size();i++){
        minp=min(prices[i],minp);
        profit=prices[i]-minp;
        maxprofit=max(profit,maxprofit);

    }
    return maxprofit;
}
    int main(){


    }