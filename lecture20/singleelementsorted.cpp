#include<iostream>
#include<vector>
using namespace std;
int singleNonDuplicate(vector<int>& nums) {
        int s=0,e=nums.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(e==0){
                return nums[mid];
            }
            if(s==nums.size()-1){
                return nums[mid];
            }
            if((nums[mid]!=nums[mid+1]) && (nums[mid]!=nums[mid-1])){
                return nums[mid];
            }
            else if(nums[mid]==nums[mid-1]){
                if((e-mid)%2==0){
                        e=mid-2;
                    }
                else{
                        s=mid+1;
                    }
                }
            else if(nums[mid]==nums[mid+1]){
                if((e-mid-1)%2==0){
                    e=mid-1;
                }
                else{
                    s=mid+2;
                }
            }
            }
           return -1;
        }
    int main(){
        
    }