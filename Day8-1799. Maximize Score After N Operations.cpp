#include<bits/stdc++.h>
using namespace std;
//Problem link 
//https://leetcode.com/problems/maximize-score-after-n-operations/

// class Solution {
// public:
//     int solve(vector<int>&nums, vector<bool>&visited, int operation)
//     {     
//         int maxScore = 0;
//         for (int i = 0; i < nums.size() - 1; i++)
//         {
//             if (visited[i]) continue;
//             for (int j = i + 1; j < nums.size(); j++)
//             {
//                 if (visited[j]) continue;
//                 visited[i] = true;
//                 visited[j] = true;
//                 //=====================================================================
//                 int currScore = operation * __gcd(nums[i], nums[j]);
//                 int nextMaxScore = solve(nums, visited, operation + 1);
//                 int totalScore = currScore + nextMaxScore;
//                 maxScore = max(maxScore, totalScore);
//                 //======================================================================
//                 visited[i] = false;
//                 visited[j] = false;
//             }
//         }
//         return maxScore; 
//     }
//     int maxScore(vector<int>& nums) 
//     {
//         int n = nums.size();
//         vector<bool>visited(n, false);
//         int ans = solve(nums, visited, 1);
//         return ans;
        
//     }
// };


class Solution {
public:
    int solve(vector<int>&nums,  unordered_map<vector<bool>, int>&mp, vector<bool>&visited, int operation)
    {
        if (mp.count(visited)) return mp[visited]; //use stored result
            
        int maxScore = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (visited[i]) continue;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (visited[j]) continue;
                visited[i] = true;
                visited[j] = true;
                //=====================================================================
                int currScore = operation * __gcd(nums[i], nums[j]);
                int nextMaxScore = solve(nums, mp, visited, operation + 1);
                int totalScore = currScore + nextMaxScore;
                maxScore = max(maxScore, totalScore);
                //======================================================================
                visited[i] = false;
                visited[j] = false;
            }
        }
        return mp[visited] = maxScore; //store the result
    }
    int maxScore(vector<int>& nums) 
    {
        int n = nums.size();
        vector<bool>visited(n, false);
        unordered_map<vector<bool>, int>mp;
        int ans = solve(nums, mp, visited, 1);
        return ans;
        
    }
};