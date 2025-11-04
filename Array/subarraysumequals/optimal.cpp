#include<bits/stdc++.h>
using namespace std;
//Prefix Sum Approach
int subarraySum(vector<int>& nums, int k) {//TC=o(n)//SC=O(n)
        int n=nums.size();
        int pf[n];
        pf[0]=nums[0];
        int c=0;
        //storing prefix sum in an array
        for(int i=1;i<n;i++){
            pf[i]=pf[i-1]+nums[i];
        }
        unordered_map<int,int>m;//prefixsum and freq
        int val;
        for(int j=0;j<n;j++){
            if(pf[j]==k)c++;
            val=pf[j]-k;
            if(m.find(val)!=m.end()){
                c+=m[val];
            }
            if(m.find(pf[j])==m.end()){
                m[pf[j]]=0;
            }
            m[pf[j]]++;
        }
       return c;
    }