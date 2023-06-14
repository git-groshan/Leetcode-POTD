#include<bits/stdc++.h>
using namespace std;

//Problem link 
//https://leetcode.com/contest/weekly-contest-303/problems/equal-row-and-column-pairs/

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>rows , cols;
        
        for(int i=0;i<n;i++){
            auto temp = grid[i];
            rows.push_back(temp);
        }
        for(int j=0;j<n;j++){
            vector<int>col;
            for(int i=0;i<n;i++){
                col.push_back(grid[i][j]);
            }
            cols.push_back(col);
        }
        int pair =0;
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(rows[r]==cols[c]) pair++;
            }
        }
        return pair;
        
    }
};
//Solution 2 using map<vector<int> , int>

class Solution2 {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int> , int>mp;
        int ans = 0;
        int n = grid.size();
        for(int i=0;i<n;i++)  mp[grid[i]]++;
        
        for(int j=0;j<n;j++){
            vector<int>col;
            for(int i=0;i<n;i++){
                col.push_back(grid[i][j]);
                if(mp.find(col) != mp.end()) ans+=mp[col];
            }
        }
        return ans;
    }
};

/*
2352. Equal Row and Column Pairs
Medium

823

49

Add to List

Share
Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.

A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).

 

Example 1:


Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
Output: 1
Explanation: There is 1 equal row and column pair:
- (Row 2, Column 1): [2,7,7]
Example 2:


Input: grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
Output: 3
Explanation: There are 3 equal row and column pairs:
- (Row 0, Column 0): [3,1,2,2]
- (Row 2, Column 2): [2,4,2,2]
- (Row 3, Column 2): [2,4,2,2]
 

Constraints:

n == grid.length == grid[i].length
1 <= n <= 200
1 <= grid[i][j] <= 105
*/