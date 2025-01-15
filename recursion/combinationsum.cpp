#include<bits/stdc++.h>
using namespace std;
//COMBINATION SUM
//EXAMPLE
// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.
//APPROACH
// we divide each call into three conditons.
// 1.contain one element only once
// 2.Exclude particular element
// 3.contain multiple times
set<vector<int>>s;
void helper(int i,vector<int>arr,vector<vector<int>>&ans,vector<int>&ele,int target){
    if(target<0 || i==arr.size()){
        return;
    }
    if(target==0){
        if(s.find(ele)==s.end()){
        ans.push_back(ele);
        s.insert(ele);
        return;
        }
    }
    ele.push_back(arr[i]);
    helper(i+1,arr,ans,ele,target-arr[i]);//cond-1
    helper(i,arr,ans,ele,target-arr[i]);//cond-3
    ele.pop_back();//backtracking
    helper(i+1,arr,ans,ele,target);//cond-2
}
vector<vector<int>> combinationsum(vector<int>arr,int target){
    vector<vector<int>>ans;
    vector<int>ele;
    helper(0,arr,ans,ele,target);
    return ans;
}
int main(){
    vector<int>arr={2,3,5};
    vector<vector<int>>ans=combinationsum(arr,8);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}