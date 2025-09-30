/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: m = 3, n = 7
Output: 28*/
int solve(int m,int n,vector<vector<int>>&dp){
    if(m==0 || n==0){
        return 1;
    }
    if(dp[m][n]!=-1){
        return dp[m][n];
    }
    return dp[m][n]=solve(m-1,n,dp)+solve(m,n-1,dp);
}
int uniquePaths(int m, int n) {
    vector<vector<int>>dp(m,vector<int>(n,-1));
    return solve(m-1,n-1,dp);
}

// tabulation
int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0){
                    dp[i][j]=1;
                    continue;
                }
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
}
// space optimization
int uniquePaths(int m, int n) {
        vector<int>prev(n,0);
        for(int i=0;i<m;i++){
            vector<int>temp(n,0);
            for(int j=0;j<n;j++){
                if(i==0 || j==0){
                    temp[j]=1;
                    continue;
                }
                temp[j]=prev[j]+temp[j-1];
            }   
            prev=temp;
        }
        return prev[n-1];
}
// Best Solution
int uniquePaths(int m, int n) {
         int N=n+m-2;
         int r=m-1;
         double res=1;
         for(int i=1;i<=r;i++){
            res=res*(N-r+i)/i;
         }
         return res;
    }

/*You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right*/
int f(int m,int n,vector<vector<int>>&obstacleGrid,vector<vector<int>>&dp){
         if(m<0 || n<0 || obstacleGrid[n][m]){
            return 0;
        }
        if(m==0 && n==0){
            return dp[n][m]=1;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        int up=f(m,n-1,obstacleGrid,dp);
        int left=f(m-1,n,obstacleGrid,dp);
        return dp[n][m]=up+left;
    }
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n=obstacleGrid.size();
    int m=obstacleGrid[0].size();
    if(obstacleGrid[n-1][m-1])
        return 0;
    vector<vector<int>>dp(n,vector<int>(m,-1));
    f(m-1,n-1,obstacleGrid,dp);
    return dp[n-1][m-1];
}

// tabulation
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        if(obstacleGrid[0][0])
            return 0;
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int up=0,left=0;
                if(obstacleGrid[i][j])continue;
                else if(i==0 && j==0)dp[i][j]=1;
                else{
                    if(i>0)up=dp[i-1][j];
                    if(j>0)left=dp[i][j-1];
                    dp[i][j]=up+left;
                }
            }
        }
        return dp[n-1][m-1];
}

// MINIMUM PATH SUM
// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.
class Solution {
public:
    int f(vector<vector<int>>&dp,int x,int y,vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        if(x==m-1 && y==n-1){
            return grid[x][y];
        }
        if(x>=m || y>=n){
            return INT_MAX;
        }
        if(dp[x][y]!=-1){
            return dp[x][y];
        }
        // down
        int down=f(dp,x+1,y,grid);
        // right
        int right=f(dp,x,y+1,grid);
        return dp[x][y]=grid[x][y]+min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(dp,0,0,grid);
    }
};

// tabulation(remove the stack space)
int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1){
                        dp[n-1][m-1]=grid[n-1][m-1];
                        continue;
                    }
                int down=-1;
                int right=-1;
                if(i+1<n){
                    down=dp[i+1][j];
                }
                if(j+1<m){
                    right=dp[i][j+1];
                }
                if(down!=-1 &&  right!=-1){
                    dp[i][j]=grid[i][j]+min(down,right);
                }
                else{
                    dp[i][j]=grid[i][j]+max(down,right);
                }
            }
        }
        return dp[0][0];
    }
    // space optimization
int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int>prev(m);
        for(int i=n-1;i>=0;i--){
            vector<int>curr(m);
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1){
                        curr[m-1]=grid[n-1][m-1];
                        continue;
                    }
                int down=-1;
                int right=-1;
                if(i+1<n){
                    down=prev[j];
                }
                if(j+1<m){
                    right=curr[j+1];
                }
                if(down!=-1 &&  right!=-1){
                    curr[j]=grid[i][j]+min(down,right);
                }
                else{
                    curr[j]=grid[i][j]+max(down,right);
                }
            }
            prev=curr;
        }
        return prev[0];
    }

    // Given a triangle array, return the minimum path sum from top to bottom.

// For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

// Example 1:

// Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
// Output: 11
// Explanation: The triangle looks like:
//    2
//   3 4
//  6 5 7
// 4 1 8 3
// The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
class Solution {
public:
    int f(int n,int m,vector<vector<int>>& triangle,vector<vector<int>>&dp){
        if(n==triangle.size()){
            return 0;
        }
        if(dp[n][m]!=INT_MAX){
            return dp[n][m];
        }
        int down=f(n+1,m,triangle,dp);
        int downright=f(n+1,m+1,triangle,dp);
        return dp[n][m]=triangle[n][m]+min(down,downright);
    }
    int minimumTotal(vector<vector<int>>& triangle){
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        return f(0,0,triangle,dp);
    }
};
// tabulation
int minimumTotal(vector<vector<int>>& triangle){
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                if(i==n-1){
                    dp[i][j]=triangle[i][j];
                }
                else{
                    int down=dp[i+1][j];
                    int downright=dp[i+1][j+1];
                    dp[i][j]=triangle[i][j]+min(down,downright);
                }
            }
        }
        return dp[0][0];
}

// space optimization
int minimumTotal(vector<vector<int>>& triangle){
        int n=triangle.size();
        vector<int>prev;
        for(int i=n-1;i>=0;i--){
            vector<int>curr(triangle.size());
            for(int j=0;j<triangle[i].size();j++){
                if(i==n-1){
                    curr[j]=triangle[i][j];
                }
                else{
                    int down=prev[j];
                    int downright=prev[j+1];
                    curr[j]=triangle[i][j]+min(down,downright);
                }
            }
            prev=curr;
        }
        return prev[0];
    }
// MAXIMUM PATH SUM IN MATRIX
// You are given a matrix mat[][] of size n x m where each element is a positive integer. Starting from any cell in the first row, you are allowed to move to the next row, but with specific movement constraints. From any cell (r, c) in the current row, you can move to any of the three possible positions :

// (r+1, c-1) — move diagonally to the left.
// (r+1, c) — move directly down.
// (r+1, c+1) — move diagonally to the right.
// Find the maximum sum of any path starting from any column in the first row and ending at any column in the last row, following the above movement constraints.

// Examples :

// Input: mat[][] = [[3, 6, 1], [2, 3, 4], [5, 5, 1]]
// Output: 15
// Explaination: The best path is (0, 1) -> (1, 2) -> (2, 1). It gives the maximum sum as 15.

class Solution {
    int f(int r,int c,vector<vector<int>>& mat,vector<vector<int>>&dp){
        if(r==mat.size()-1){
            return dp[r][c]=mat[r][c];
        }
        if(dp[r][c]!=-1)
            return dp[r][c];
        vector<int>dc={-1,0,1};
        int maximumPath=0;
        for(int i=0;i<3;i++){
            int nc=c+dc[i];
            if(nc<mat[r].size() && nc>=0){
                int value=f(r+1,nc,mat,dp);
                maximumPath=max(maximumPath,value);
            }
        }
        return dp[r][c]=mat[r][c]+maximumPath;
    }
  public:
    int maximumPath(vector<vector<int>>& mat) {
      int ans=0;
      vector<vector<int>>dp(mat.size(),vector<int>(mat[0].size(),-1));
      for(int c=0;c<mat[0].size();c++){
          int value=f(0,c,mat,dp);
          ans=max(ans,value);
      }
        return ans;
    }
};
// tabulation
int maximumPath(vector<vector<int>>& mat) {
      int n=mat.size();
      int m=mat[0].size();
      int ans=0;
      vector<vector<int>>dp(n,vector<int>(m,-1));
      vector<int>dc={-1,0,1};
      for(int i=n-1;i>=0;i--){
          for(int j=m-1;j>=0;j--){
              if(i==n-1){
                  dp[i][j]=mat[i][j];
              }
              else{
                  int maximumPath=0;
                  for(int k=0;k<3;k++){
                    int nc=j+dc[k];
                    if(nc<m && nc>=0){
                        maximumPath=max(maximumPath,dp[i+1][nc]);
                    }
                  }
                  dp[i][j]=mat[i][j]+maximumPath;
              }
          }
      }
      for(int c=0;c<m;c++){
          ans=max(ans,dp[0][c]);
      }
        return ans;
    }

// CHERRY PICKUP II
// You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.

// You have two robots that can collect cherries for you:

// Robot #1 is located at the top-left corner (0, 0), and
// Robot #2 is located at the top-right corner (0, cols - 1).
// Return the maximum number of cherries collection using both robots by following the rules below:

// From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
// When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
// When both robots stay in the same cell, only one takes the cherries.
// Both robots cannot move outside of the grid at any moment.
// Both robots should reach the bottom row in grid.
 

// Example 1:


// Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
// Output: 24
// Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
// Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12.
// Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12.
// Total of cherries: 12 + 12 = 24.

class Solution {
    int f(int i,int aj,int bj,vector<vector<int>>& grid,vector<vector<vector<int>>>&dp){
        int len=grid[0].size();
        int n=grid.size();
        if(aj<0 || aj>=len || bj<0 || bj>=len){
            return -1e8;
        }
        if(i==n-1){
            if(aj==bj)return dp[i][aj][bj]=grid[i][aj];
            return dp[i][aj][bj]=grid[i][aj]+grid[i][bj];
        }
        if(dp[i][aj][bj]!=-1){
            return dp[i][aj][bj];
        }
        int maxi=0;
        for(int a=-1;a<=1;a++){
            for(int b=-1;b<=1;b++){
                if(aj==bj)
                    maxi=max(maxi,grid[i][aj]+f(i+1,aj+a,bj+b,grid,dp));
                else
                    maxi=max(maxi,grid[i][aj]+grid[i][bj]+f(i+1,aj+a,bj+b,grid,dp));
            }
        }
        return dp[i][aj][bj]=maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid[0].size();
        int m=grid.size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
        return f(0,0,n-1,grid,dp);//TC-O(NxMxM) SC-O(NxMxM)
    }
};

// Tabulation
int cherryPickup(vector<vector<int>>& grid) {
        int n=grid[0].size();
        int m=grid.size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(n,0)));
        // base condition
        for(int aj=0;aj<n;aj++){
            for(int bj=0;bj<n;bj++){
                if(aj==bj)dp[m-1][aj][bj]=grid[m-1][aj];
                else dp[m-1][aj][bj]=grid[m-1][aj]+grid[m-1][bj];
            }
        }
        for(int i=m-2;i>=0;i--){
            for(int aj=0;aj<n;aj++){
                for(int bj=0;bj<n;bj++){
                   int maxi=0;
                   for(int a=-1;a<=1;a++){
                        for(int b=-1;b<=1;b++){
                            if((aj+a)<0 || (aj+a)>=n || (bj+b)<0 || (bj+b)>=n)
                                continue;
                            if(aj==bj)
                                maxi=max(maxi,grid[i][aj]+dp[i+1][aj+a][bj+b]);
                            else
                                maxi=max(maxi,grid[i][aj]+grid[i][bj]+dp[i+1][aj+a][bj+b]);
                        }
                    } 
                    dp[i][aj][bj]=maxi;
                }
            }
        }
        return dp[0][0][n-1];
    }