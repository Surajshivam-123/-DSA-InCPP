#include<iostream>
#include<vector>
using namespace std;
 int maxProfit1(vector<int>& prices) {
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
    int maxProfit2(vector<int>& prices) {
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