// Problem statement
// There is a frog on the '1st' step of an 'N' stairs long staircase. The frog wants to reach the 'Nth' stair. 'HEIGHT[i]' is the height of the '(i+1)th' stair.If Frog jumps from 'ith' to 'jth' stair, the energy lost in the jump is given by absolute value of ( HEIGHT[i-1] - HEIGHT[j-1] ). If the Frog is on 'ith' staircase, he can jump either to '(i+1)th' stair or to '(i+2)th' stair. Your task is to find the minimum total energy used by the frog to reach from '1st' stair to 'Nth' stair.

// For Example
// If the given ‘HEIGHT’ array is [10,20,30,10], the answer 20 as the frog can jump from 1st stair to 2nd stair (|20-10| = 10 energy lost) and then a jump from 2nd stair to last stair (|10-20| = 10 energy lost). So, the total energy lost is 20.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
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


int main(){
    int n=8;
    vector<int>height={7,4,4,2,6,6,3,4};
    vector<int>dp(n+1,-1);
    cout<<solve(height,dp,7)<<endl;
    cout<<tabulation(7,height)<<endl;
    cout<<tabulationv(7,height)<<endl;
}