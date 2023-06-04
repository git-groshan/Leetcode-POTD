#include<bits/stdc++.h>
using namespace std;

//problem link 
//https://leetcode.com/problems/number-of-provinces/

class Solution {
public:
    void dfs(int src , vector<int>g[] , int n , vector<bool>&vis){
        vis[src] = true;
        
        for(int nbr: g[src]){
            if(!vis[nbr])
            dfs(nbr , g , n , vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>g[n+1];
        vector<bool>vis(n+1 , false);
        int ct= 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(isConnected[i][j]){
                g[i+1].push_back(j+1);
                g[j+1].push_back(i+1);
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                dfs(i , g , n  , vis);
                ct++;
            }
        }
        return ct;
    }
};