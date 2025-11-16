#include<iostream>
using namespace std;

// find all subset using bit manipulation 
// for each num insert only those index where bit is 1
vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int subset=1<<n;
        vector<vector<int>>ans;
        for(int num=0;num<subset;num++){
            vector<int>temp;
            for(int i=0;i<n;i++){
                if(num&(1<<i)){
                    temp.push_back(nums[i]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }

// find single number among array contain each element trepeat wice except 1
int singleNumber(vector<int>& nums) {
        int ans=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            ans=ans^nums[i];
        }
        return ans;
    }

// SINGLE NUMBER II
// Every element except repeats one time
// Example 2:

// Input: nums = [0,1,0,1,0,1,99]
// Output: 99
int singleNumber(vector<int>& nums) {
    int ones = 0, twos = 0;
    int n = nums.size();
    
    for(int i = 0; i < n; i++) {
        // Step 1: If a bit is in 'ones' AND in current number,
        // it means we've seen it twice now, so add it to 'twos'
        twos |= (ones & nums[i]);
        
        // Step 2: Toggle the bits in 'ones' for current number
        // If bit was 0, make it 1. If it was 1, make it 0
        ones ^= nums[i];
        
        // Step 3: Find bits that appear 3 times (in both ones and twos)
        // and remove them from both (reset the counter)
        int threes = ones & twos;
        ones &= ~threes;   // Remove from ones
        twos &= ~threes;   // Remove from twos
    }
    
    return ones;  // The number that appeared once
}

/*
SIMPLE ANALOGY - Think of it like a two-hand counter:
- LEFT HAND (ones): Counts 1st occurrence
- RIGHT HAND (twos): Counts 2nd occurrence  
- When both hands are up (3rd occurrence): Reset both hands to zero

EXAMPLE WALKTHROUGH: [2, 2, 3, 2]

Initial: ones = 0, twos = 0

After 1st '2':
  - twos = 0 (not in ones yet)
  - ones = 2 (first time seeing 2)
  - No threes to remove
  Result: ones = 2, twos = 0

After 2nd '2':
  - twos = 2 (was in ones, now moved to twos)
  - ones = 0 (XOR removes it from ones)
  - No threes yet
  Result: ones = 0, twos = 2

After '3':
  - twos = 2 (3 not in ones, so twos unchanged)
  - ones = 3 (first time seeing 3)
  - No threes
  Result: ones = 3, twos = 2

After 3rd '2':
  - twos = 2 (already there)
  - ones = 2 (XOR adds it back)
  - threes = 2 (2 is in both ones AND twos!)
  - Remove 2 from both ones and twos
  Result: ones = 3, twos = 0

Answer: 3 ✓
*/


// SingleNUmber III
// Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

// You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

 

// Example 1:

// Input: nums = [1,2,1,3,2,5]
// Output: [3,5]
// Explanation:  [5, 3] is also a valid answer.
vector<int> singleNumber(vector<int>& nums) {
        vector<long long> ans(2);
        long long n = nums.size();
        long long ones = 0;
        for (long long i = 0; i < n; i++) {
            ones = ones ^ nums[i];
        }
        long long rightMost = (ones & (ones - 1)) ^ ones;
        int ans1 = 0, ans2 = 0;
        for (auto v : nums) {
            if (v & rightMost) {
                ans1 = ans1 ^ v;
            } else {
                ans2 = ans2 ^ v;
            }
        }
        return {ans1,ans2};
    }

// Divide two integers without using multiplication and divison operator
int divide(int dividend, int divisor) {
        int sign=true;
        if(dividend<0 && divisor>0)sign=false;
        if(dividend>0 && divisor<0)sign=false;
        long long n=llabs((long long)dividend);
        long long d=llabs((long long)divisor);
        long long quotient=0;
        while(n>=d){
            int cnt=0;
            while(n>=(d<<(cnt+1))){
                cnt++;
            }
            quotient+=1<<cnt;
            n-=d<<cnt;
        }
        if(quotient==(1<<31) && sign)
            return INT_MAX;
        if(quotient==(1<<31) && !sign)
            return INT_MIN;
        return sign?quotient:-1*quotient;
    }