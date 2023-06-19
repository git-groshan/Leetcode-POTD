#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

        int mod = 1000000007;
        int dr[4] = {1,0,-1,0};
        int dc[4] = {0,1,0,-1};

    bool isValid(int i,int j,vector<vector<int>>& grid){

        if(i<0 || i>= grid.size() || j<0 || j>= grid[0].size())
         return false;

        return true; 
    } 

    int dfs(int r,int c,vector<vector<int>>& grid,vector<vector<int>>& dp){

        if(dp[r][c] != -1)
         return dp[r][c];


        int ans = 1;

        for(int i=0;i<4;i++){

            int nr = r + dr[i];
            int nc = c + dc[i];

            if(isValid(nr,nc,grid) && grid[nr][nc] > grid[r][c]){
                ans = (ans%mod + dfs(nr,nc,grid,dp)%mod)%mod;
            }
        }

        return dp[r][c]=ans;
    } 

    int countPaths(vector<vector<int>>& grid) {
        
         vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
         long long cnt = 0;

         for(int i=0;i<grid.size();i++)
           for(int j=0;j<grid[0].size();j++)
             cnt = (cnt%mod + dfs(i,j,grid,dp)%mod)%mod;

        return (int)cnt%mod;     
    }
};

/*
2328. Number of Increasing Paths in a Grid
Hard

1682

39

Add to List

Share
You are given an m x n integer matrix grid, where you can move from a cell to any adjacent cell in all 4 directions.

Return the number of strictly increasing paths in the grid such that you can start from any cell and end at any cell. Since the answer may be very large, return it modulo 109 + 7.

Two paths are considered different if they do not have exactly the same sequence of visited cells.

 

Example 1:


Input: grid = [[1,1],[3,4]]
Output: 8
Explanation: The strictly increasing paths are:
- Paths with length 1: [1], [1], [3], [4].
- Paths with length 2: [1 -> 3], [1 -> 4], [3 -> 4].
- Paths with length 3: [1 -> 3 -> 4].
The total number of paths is 4 + 3 + 1 = 8.
Example 2:

Input: grid = [[1],[2]]
Output: 3
Explanation: The strictly increasing paths are:
- Paths with length 1: [1], [2].
- Paths with length 2: [1 -> 2].
The total number of paths is 2 + 1 = 3.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 1000
1 <= m * n <= 105
1 <= grid[i][j] <= 105
*/

//https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/