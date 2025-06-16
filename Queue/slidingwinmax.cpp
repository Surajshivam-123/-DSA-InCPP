#include<iostream>
#include<deque>
#include<vector>
using namespace std;
// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation: 
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
vector<int> maxSlidingWindow(vector<int>& nums, int k) {//TC->O(n) SC->O(n)
    vector<int>ans;
    deque<int>dq;
    for(int i=0;i<k;i++){//TC->O(k)
        while(dq.size()>0 && nums[dq.back()]<=nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for(int i=k;i<nums.size();i++){//TC->O(n-k)
        ans.push_back(nums[dq.front()]);
        if(dq.front()<=i-k){
            dq.pop_front();
        }
        while(dq.size()>0 && nums[dq.back()]<=nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans.push_back(nums[dq.front()]);
    return ans;
}
int main()
{
    vector<int>nums={1,3,-1,-3,5,3,6,7};
    vector<int>ans=maxSlidingWindow(nums,3);
    for(int v:ans){
        cout<<v<<" ";
    }
    cout<<endl;
return 0;
}