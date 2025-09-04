#include<iostream>
#include<vector>
using namespace std;
// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

 

// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]

// brute-force
vector<int> productExceptSelf_brute(vector<int>& nums) {
    int pro=1;
    vector<int>ans;
    for(int i=0;i<nums.size();i++){
        pro=1;
        for(int j=0;j<nums.size();j++){
            if(i!=j){
            pro*=nums[j];
        }
    }
        ans.push_back(pro);
}

return ans;
    }
//best approach using prefix and suffix
vector<int> productExceptSelf_best(vector<int>& nums) {//[1,2,3,4]
    int n=nums.size();
    vector<int> ans(n);
    vector<int>prefix(n,1);
    vector<int>suffix(n,1);
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]*nums[i-1];//[1,1,2,6,24]
    }
    for(int i=n-2;i>=0;i--){
        suffix[i]=suffix[i+1]*nums[i+1];//[24,24,12,4,1]
    }
    for(int i=0;i<n;i++){
        ans[i]=prefix[i]*suffix[i];
    }
    return ans;
    }
 vector<int> productExceptSelf_same(vector<int>& nums) {
       int n=nums.size();
       vector<int>ans(n,1);
       for(int i=1;i<n;i++){
            ans[i]=ans[i-1]*nums[i];
       }
       int suffi=1;
       for(int j=n-1;j>=0;j--){
            ans[j]*=suffi;
            suffi*=nums[j];
       }
       return ans;
    }

    
int main(){
vector<int>suraj={1,2,3,4};
productExceptSelf_best(suraj);
for(int i=0;i<suraj.size();i++){
    cout<<suraj[i]<<endl;
}
return 0;
}