#include<iostream>
#include<vector>
using namespace std;
int majorityElement(vector<int>& nums) {
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
int main(){

}