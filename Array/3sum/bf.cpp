#include<bits/stdc++.h>
using namespace std;
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.
// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
vector<vector<int>> threeSum(vector<int>& nums) {//Time complexity O(n^3*log(unique triplets))
        vector<vector<int>>ans;//Space compleity O(unique triplets*2) or O(unique triplets)
        unordered_set<vector<int>>s;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    vector<int>p;
                    if(nums[i]+nums[j]+nums[k]==0){
                        p.push_back(nums[i]);
                        p.push_back(nums[j]);
                        p.push_back(nums[k]);
                        sort(p.begin(),p.end());
                        if(s.find(p)==s.end()){//O(log(n))
                            s.insert(p);
                            ans.push_back(p);
                        }
                    }
        }
        }
        }
        return ans;
                }