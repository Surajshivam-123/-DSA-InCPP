#include<iostream>
#include<vector>
using namespace std;
void sort(vector<int>&nums){//O(n)Time complexity
    int l=0,h=nums.size()-1,m=0;
    while(m<=h){
        if(nums[m]==0){
            swap(nums[l],nums[m]);
            l++;m++;
        }
        else if(nums[m]==1){
            m++;
        }
        else{
            swap(nums[m],nums[h]);
            h--;
        }
    }
    
}
int main(){
//     Example 1:

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
vector<int>nums={2,0,2,1,1,0};
sort(nums);
for(int i:nums){
    cout<<i<<endl;
}
}