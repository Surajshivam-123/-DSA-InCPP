#include<iostream>
using namespace std;

// ALL POSSIBLE BINARY TREE
// Given an integer n, return a list of all possible full binary trees with n nodes. Each node of each tree in the answer must have Node.val == 0.

// Each element of the answer is the root node of one possible tree. You may return the final list of trees in any order.

// A full binary tree is a binary tree where each node has exactly 0 or 2 children.

 

// Example 1:


// Input: n = 7
// Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]

// KEY CONCEPT
// BASE CASE:

// If n == 1 → only one tree: a single root node.
// OTHERWISE:

// Make a root.

// Split remaining n-1 nodes into (left, right) where both are odd.

// For n = 7: (1,5) , (3,3) , (5,1).

// Get left array = allPossibleFBT(left), right array = allPossibleFBT(right).

// For every pair (lt, rt) in these arrays → attach them to a new root and push into result.

// Use memoization to avoid recomputing.

unordered_map<int,vector<TreeNode*>>dp;
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*>res;
        if(n==1){
            TreeNode* root=new TreeNode(0);
            res.push_back(root);
            return res;
        }
        if(dp.find(n)!=dp.end())
            return dp[n];
        for(int i=1;i<n-1;i+=2){
            vector<TreeNode*>l=allPossibleFBT(i);
            vector<TreeNode*>r=allPossibleFBT(n-i-1);
            for(auto left:l){
                for(auto right:r){
                    TreeNode* root=new TreeNode(0);
                    root->left=left;
                    root->right=right;
                    res.push_back(root);
                }
            }
        }
        return dp[n]=res;
    }
// tabulation
vector<TreeNode*> allPossibleFBT(int n) {
        vector<vector<TreeNode*>>dp(n+1);
        TreeNode* root=new TreeNode(0);
        dp[1]={root};
        for(int i=3;i<=n;i+=2){
            for(int j=1;j<i-1;j+=2){
                vector<TreeNode*>l=dp[j];
                vector<TreeNode*>r=dp[i-1-j];
                for(auto lt:l){
                    for(auto rt:r){
                        TreeNode *newNode=new TreeNode(0);
                        newNode->left=lt;
                        newNode->right=rt;
                        dp[i].push_back(newNode);
                    }
                }
            }
        }
        return dp[n];
    }
