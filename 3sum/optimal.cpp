#include<bits/stdc++.h>
using namspace std;
//Approach with hashing
vector<vector<int>> threeSum(vector<int>& nums) {//TC=>O(n^2*log(uniquetriplets))
        int tar;                                //SC=>(uniqutriplets+n)
        int n=nums.size();
        set<vector<int>>se;//Unique triplets
        for(int i=0;i<n-2;i++){//a+b+c=0  =>a+b=-c=tar =>a=tar-b
            tar=-nums[i];
            set<int>s;
            for(int j=i+1;j<n;j++){
                int tofind=tar-nums[j];
                if(s.find(tofind)!=s.end()){
                    vector<int>p={nums[i],nums[j],tofind};
                    sort(p.begin(),p.end());
                        se.insert(p);
                }
                s.insert(nums[j]);
            }
        }
        vector<vector<int>>ans(se.begin(),se.end());
        return ans;
                }
