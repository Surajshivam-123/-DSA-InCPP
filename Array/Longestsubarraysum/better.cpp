#include<iostream>
#include<vector>
#include<map>
using namespace std;
//Hashing
int longestSubarraySum(vector<int>nums,int k){
    int maxlen=0;
    int n=nums.size();
    vector<int>pf(n,0);
    pf[0]=nums[0];
    for(int i=1;i<n;i++){
        pf[i]=pf[i-1]+nums[i];
    }
    map<int,int>m;
    m[0]=-1;
    for(int i=0;i<n;i++){
        int val=pf[i]-k;
        //if(val==0)maxlen=max(maxlen,i+1);
        if(m.find(val)!=m.end()){
            int len=i-m[val];
            maxlen=max(maxlen,len);
        }
        if(m.find(pf[i])==m.end()){
            m[pf[i]]=i;
        }
    }
    return maxlen;
}

int main()
{
return 0;
}