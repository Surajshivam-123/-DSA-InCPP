#include<iostream>
#include<vector>
using namespace std;
// In recursion, there is a overlapping subproblem for example:-
// Overlapping subproblem:-In writing fibonacci series once we find f(n) then we have to find same thing in adjacent subtree 
// Memoization:-tend to store the value of sub problems in some map/table.So we have to not perform same task.
// -Once programme calculated then it store the result .so that it can reuse the result.
int f(int n,vector<int>&dp){//TC->O(n) Sc->O(n)
    if(n<=1)return n;
    if(dp[n]!=-1){//step 3-use previously calcuated value
        return dp[n];
    }
    return dp[n]=f(n-1,dp)+f(n-2,dp);//step 2-store the calculated value
}
int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1,-1);//step 1-declare the array
    cout<<f(n,dp);

}
//convert into tables-Rule=>Try to get answer from base case
int main(){
    int n;
    cin>>n;
    int dp[n];
    //base cases
    dp[0]=0;
    dp[1]=1;

    for(int i=2;i<n;i++){
        dp[i]=dp[i-1]+dp[i-2];//we can solve using two variable to reduce space complexity
    }
}
// optimized space complexity
int main(){
    int n;
    cin>>n;
    //base cases
    int a=0,b=1;
    int ans;
    for(int i=2;i<n;i++){
        ans=a+b;
        a=b;
        b=ans;
    }
    cout<<ans<<endl;
}
