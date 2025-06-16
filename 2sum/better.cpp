#include<bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        vector<int>t;
        for(int i=0;i<nums.size();i++){
            t.push_back(nums[i]);
        }
        sort(t.begin(),t.end());
        int l=0,r=t.size()-1;
        while(l<r){
            if((t[l]+t[r])==target){
                ans.push_back(t[l]);
                ans.push_back(t[r]);
                break;
            }
            else if((t[l]+t[r])>target){
                r--;
            }
            else if((t[l]+t[r])<target){
                l++;
            }
        }
        int in;
        for(int i=0;i<nums.size();i++){
                if(nums[i]==ans[0]){
                     ans[0]=i;
                     in=i;
                     break;
            }
            }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ans[1] && in!=i){
                    ans[1]=i;
                    break;
            }
        }

        return ans;
    }