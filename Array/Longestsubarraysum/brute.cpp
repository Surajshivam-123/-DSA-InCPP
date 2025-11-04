#include<iostream>
#include<vector>
using namespace std;

int longestSubarraySum(vector<int>nums,int k){
    int n=nums.size();
    int maxlen=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=nums[j];
            if(sum==k){
                maxlen=max(maxlen,j-i+1);
                break;
            }
            else if(sum>k)break;
        }
    }
    return maxlen;
}
int main()
{
return 0;
}