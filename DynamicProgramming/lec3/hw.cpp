#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
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

int main()
{
return 0;
}