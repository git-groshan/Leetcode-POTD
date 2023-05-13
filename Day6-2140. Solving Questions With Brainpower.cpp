#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    long long int f(int idx , vector<vector<int>>& questions , vector<long long int>&dp){
        if(idx>=questions.size()) return 0;
        
        if(dp[idx] !=-1) return dp[idx];
        
        long long take = 0 , notTake=0;
        take = questions[idx][0] + f(idx +  questions[idx][1] + 1 , questions, dp );
        notTake = 0 + f(idx+1 , questions , dp);
        
        return dp[idx] = max(take , notTake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        
        vector<long long int>dp(n ,-1);
        
        return f(0 , questions , dp);
    }
};