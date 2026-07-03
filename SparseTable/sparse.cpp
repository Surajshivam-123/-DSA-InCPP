// Maximum total subarray value
// You are given an integer array nums of length n and an integer k.

// You must select exactly k distinct non-empty subarrays nums[l..r] of nums. Subarrays may overlap, but the exact same subarray (same l and r) cannot be chosen more than once.

// The value of a subarray nums[l..r] is defined as: max(nums[l..r]) - min(nums[l..r]).

// The total value is the sum of the values of all chosen subarrays.

// Return the maximum possible total value you can achieve.

 

// Example 1:

// Input: nums = [1,3,2], k = 2

// Output: 4

// Explanation:

// One optimal approach is:

// Choose nums[0..1] = [1, 3]. The maximum is 3 and the minimum is 1, giving a value of 3 - 1 = 2.
// Choose nums[0..2] = [1, 3, 2]. The maximum is still 3 and the minimum is still 1, so the value is also 3 - 1 = 2.
// Adding these gives 2 + 2 = 4.

// Example 2:

// Input: nums = [4,2,5,1], k = 3

// Output: 12

// Explanation:

// One optimal approach is:

// Choose nums[0..3] = [4, 2, 5, 1]. The maximum is 5 and the minimum is 1, giving a value of 5 - 1 = 4.
// Choose nums[1..3] = [2, 5, 1]. The maximum is 5 and the minimum is 1, so the value is also 4.
// Choose nums[2..3] = [5, 1]. The maximum is 5 and the minimum is 1, so the value is again 4.
// Adding these gives 4 + 4 + 4 = 12.

class Solution {
   vector<vector<int>>stMax,stMin;
   vector<int>log2Arr;
   void buildSparseTable(const vector<int>&nums,int n){
    log2Arr.assign(n+1,0);
    for(int i=2;i<=n;i++){
        log2Arr[i]=log2Arr[i/2]+1;
    }
    int k=log2Arr[n]+1;
    stMax.assign(n,vector<int>(k));
    stMin.assign(n,vector<int>(k));
    for(int i=0;i<n;i++){
        stMax[i][0]=nums[i];
        stMin[i][0]=nums[i];
    }
    for(int j=1;j<k;j++){
        for(int i=0;(i+(1<<j))<=n;i++){
            stMax[i][j]=max(stMax[i][j-1],stMax[i+(1<<(j-1))][j-1]);
            stMin[i][j]=min(stMin[i][j-1],stMin[i+(1<<(j-1))][j-1]);
        }
    }
   }
   int getMax(int L,int R){
        int j=log2Arr[R-L+1];
        return max(stMax[L][j],stMax[R-(1<<j)+1][j]);
    }
    int getMin(int L,int R){
        int j=log2Arr[R-L+1];
        return min(stMin[L][j],stMin[R-(1<<j)+1][j]);
    }
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n=nums.size();
        buildSparseTable(nums,n);
        priority_queue<array<long long,3>>pq;
        for(int L=0;L<n;L++){
            long long score=getMax(L,n-1)-getMin(L,n-1);
            pq.push({score,L,n-1});
        }
        long long totalSum = 0;
        
        for (int i = 0; i < k; i++) {
            auto top = pq.top();
            pq.pop();
            
            totalSum += top[0];
            int L = top[1];
            int R = top[2];
            
            if (R > L) {
                int newR = R - 1;
                long long newScore = getMax(L, newR) - getMin(L, newR);
                pq.push({newScore, L, newR});
            }
        }
        
        return totalSum;
        }
};