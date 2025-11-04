#include<bits/stdc++.h>
using namespace std;
//Approach with 2 pointer 
vector<vector<int>> threeSum(vector<int>& nums) {//TC=>O(nlogn +n^2)
        vector<vector<int>>ans;                  //SC=>o(unique triplets)
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if( i!=0 && nums[i]==nums[i-1])continue;
            int j=i+1,k=n-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;k--;
                    while(j<k && nums[j]==nums[j-1]){
                    j++;
                }
                }
                else if(nums[i]+nums[j]+nums[k]>0){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return ans;
                }
int main(){

}