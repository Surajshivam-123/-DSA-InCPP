#include<iostream>
#include<vector>
using namespace std;
// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
// brute-force
int majorityElement_brute(vector<int>& nums) {
        int c;
        int u=INT16_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            c=0;
            if(nums[i]==u){
                continue;
            }
            for(int j=0;j<n;j++){
                if(nums[i]==nums[j]){
                    c++;
                }
                if(c>n/2){
                    u=nums[i];
                }
            }
        }
        return u;
    }
// better
int majorityElement_better(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int n=nums.size();
    int c=1,ans=nums[0];
    for(int i=1;i<n;i++){
        if(ans==nums[i]){
            c++;
        }
        else{
            c=1;
            ans=nums[i];
        }
        if(c>n/2){
            return a;
        }
    }

}
// moore's voting algorithm
int majorityElement(vector<int>& nums) {
        int f=0,ans=0;
        for(int i=0;i<nums.size();i++){
            if(f==0){
                ans=nums[i];
            }
            if(ans==nums[i]){
                f++;
            }
            else{
                f--;
            }
        }
        return ans;
    }
int main(){
    vector<int>arr={2,2,1,1,1,2,2};
    cout<<majorityElement(arr);

}