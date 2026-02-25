#include <iostream>
using namespace std;

// find all subset using bit manipulation
// for each num insert only those index where bit is 1
vector<vector<int>> subsets(vector<int> &nums)
{
    int n = nums.size();
    int subset = 1 << n;
    vector<vector<int>> ans;
    for (int num = 0; num < subset; num++)
    {
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            if (num & (1 << i))
            {
                temp.push_back(nums[i]);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}

// find single number among array contain each element trepeat wice except 1
int singleNumber(vector<int> &nums)
{
    int ans = nums[0];
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        ans = ans ^ nums[i];
    }
    return ans;
}

// SINGLE NUMBER II
// Every element except repeats one time
// Example 2:

// Input: nums = [0,1,0,1,0,1,99]
// Output: 99
int singleNumber(vector<int> &nums)
{
    int ones = 0, twos = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        // Step 1: If a bit is in 'ones' AND in current number,
        // it means we've seen it twice now, so add it to 'twos'
        twos |= (ones & nums[i]);

        // Step 2: Toggle the bits in 'ones' for current number
        // If bit was 0, make it 1. If it was 1, make it 0
        ones ^= nums[i];

        // Step 3: Find bits that appear 3 times (in both ones and twos)
        // and remove them from both (reset the counter)
        int threes = ones & twos;
        ones &= ~threes; // Remove from ones
        twos &= ~threes; // Remove from twos
    }

    return ones; // The number that appeared once
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
vector<int> singleNumber(vector<int> &nums)
{
    vector<long long> ans(2);
    long long n = nums.size();
    long long ones = 0;
    for (long long i = 0; i < n; i++)
    {
        ones = ones ^ nums[i];
    }
    long long rightMost = (ones & (ones - 1)) ^ ones;
    int ans1 = 0, ans2 = 0;
    for (auto v : nums)
    {
        if (v & rightMost)
        {
            ans1 = ans1 ^ v;
        }
        else
        {
            ans2 = ans2 ^ v;
        }
    }
    return {ans1, ans2};
}

// Divide two integers without using multiplication and divison operator
int divide(int dividend, int divisor)
{
    int sign = true;
    if (dividend < 0 && divisor > 0)
        sign = false;
    if (dividend > 0 && divisor < 0)
        sign = false;
    long long n = llabs((long long)dividend);
    long long d = llabs((long long)divisor);
    long long quotient = 0;
    while (n >= d)
    {
        int cnt = 0;
        while (n >= (d << (cnt + 1)))
        {
            cnt++;
        }
        quotient += 1 << cnt;
        n -= d << cnt;
    }
    if (quotient == (1 << 31) && sign)
        return INT_MAX;
    if (quotient == (1 << 31) && !sign)
        return INT_MIN;
    return sign ? quotient : -1 * quotient;
}

//     You are given an array a1,a2,…,an
//  of distinct positive integers. You have to do the following operation exactly once:

// choose a positive integer k
// ;
// for each i
//  from 1
//  to n
// , replace ai
//  with ai mod k†
// .
// Find a value of k
//  such that 1≤k≤1018
//  and the array a1,a2,…,an
//  contains exactly 2
//  distinct values at the end of the operation. It can be shown that, under the constraints of the problem, at least one such k
//  always exists. If there are multiple solutions, you can print any of them.
// Input
// Each test contains multiple test cases. The first line contains the number of test cases t
//  (1≤t≤500
// ). The description of the test cases follows.

// The first line of each test case contains a single integer n
//  (2≤n≤100) — the length of the array a
// The second line of each test case contains n integers a1,a2,…,an (1≤ai≤1017) — the initial state of the array. It is guaranteed that all the aiare distinct.

// Note that there are no constraints on the sum of n over all test cases.

// Output
// For each test case, output a single integer: a value of k
//  (1≤k≤1018) such that the array a1,a2,…,an contains exactly 2 distinct values at the end of the operation.

// Example
// Input
// 5
// 4
// 8 15 22 30
// 5
// 60 90 98 120 308
// 6
// 328 769 541 986 215 734
// 5
// 1000 2000 7000 11000 16000
// 2
// 2 1
// Output
// 7
// 30
// 3
// 5000
// 1000000000000000000

typedef long long ll;
int main() {

int t;
cin>>t;
while(t--){
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    for(ll i=1;i<=60;i++){
        ll k=1LL<<i;
        unordered_set<ll>st;
        for(ll j=0;j<n;j++){
            st.insert(a[j]%k);
        }
        if(st.size()==2){
            cout<<k<<endl;
            break;
        }
    }
}
    return 0;
}
// Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.

// rolling hash
bool hasAllCodes(string s, int k) {
        if(s.length()<((1<<k)+k-1))return false;
        int req = 1 << k;
        vector<bool>seen(1<<k,false);
        int mask = req - 1;
        int hash = 0;

        for (int i = 0; i < s.length(); ++i) {
            hash = ((hash << 1) & mask) | (s[i] & 1);

            if (i >= k - 1 && !seen[hash]) {
                seen[hash] = 1;
                req--;
                if (req == 0) return true;
            }
        }

        return false;
    }

// You are given the root of a binary tree where each node has a value 0 or 1. Each root-to-leaf path represents a binary number starting with the most significant bit.

// For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.
// For all leaves in the tree, consider the numbers represented by the path from the root to that leaf. Return the sum of these numbers.

// The test cases are generated so that the answer fits in a 32-bits integer.

 

// Example 1:


// Input: root = [1,0,1,0,1,0,1]
// Output: 22
// Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22

 
class Solution {
public:
    int dfs(TreeNode* root, int curr){
        if(!root) return 0;

        curr = (curr << 1) | root->val;

        if(!root->left && !root->right)
            return curr;

        return dfs(root->left, curr) + dfs(root->right, curr);
    }

    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
};