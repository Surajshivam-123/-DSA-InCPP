#include<bits/stdc++.h>
using namespace std;
// Example 1:

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// Example 2:

// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]
vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i!=0 && nums[i]==nums[i-1])continue;
            for(int j=i+1;j<n;){
                int k=j+1,l=n-1;
                while(k<l){
                    long long int sum=(long long)nums[i]+(long long)nums[j]+(long long)nums[k]+(long long)nums[l];
                    if(sum==target){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;l--;
                        while(k<l && nums[k]==nums[k-1]){
                            k++;
                        }
                        // while(k<l && nums[l]==nums[l-1]){
                        //     l--;
                        // }
                        }
                        else if(sum>target){
                            l--;
                        }
                        else{
                            k++;
                        }
                    }
                    j++;
                    while(j<n && nums[j]==nums[j-1])j++;
                }
            }
        
        return ans;
    }