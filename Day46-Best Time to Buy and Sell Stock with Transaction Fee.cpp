#include<bits/stdc++.h>
using namespace std;

/*
714. Best Time to Buy and Sell Stock with Transaction Fee
Medium

5876

153

Add to List

Share
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Example 2:

Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
 

Constraints:

1 <= prices.length <= 5 * 104
1 <= prices[i] < 5 * 104
0 <= fee < 5 * 104
*/

class Solution {
public:
    int f(int ind  , int buy , int fee , vector<int>&prices , int n , vector<vector<int>>&dp){
        if(ind==n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        
if(buy){
    return dp[ind][buy] = max(-prices[ind] +f(ind+1 , 0 , fee , prices , n , dp),
                             0 + f(ind+1 , 1, fee , prices , n , dp));
        }
        else{
            return dp[ind][buy] = max(prices[ind]-fee + f(ind+1 ,1 , fee, prices, n , dp ) , 0 + f(ind+1 , 0 , fee , prices , n , dp));
        }
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n , vector<int>(2,-1));
        
        return f(0 , 1, fee , prices , n , dp);
    }
};