#include<bits/stdc++.h>
using namespace std;

// problem link 
//https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

class Solution {
public:
    /*
    void dfs(int node ,vector<int>g[] , int n , vector<int>&vis ){
        vis[node] = true;
        
        for(auto nbr : g[node]){
            if(!vis[nbr])
                dfs(nbr , g , n , vis);
        }
    }
    */
    // We only have to count the number of nodes with zero incoming edge. i.e indgree =0
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        vector<int>g[n];
        for(auto edge :edges){
            g[edge[0]].push_back(edge[1]);
        }
        /*
        vector<int>vis(n , false);
        int ct =0;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i , g , n , vis);
                ans.push_back(i);
            }
        }
        return ans;
    }
    */
        vector<int>in(n , 0);
        vector<int>out(n ,0);
        for(int i=0;i<n;i++){
            out[i] = g[i].size();
            for(auto nbr : g[i]){
                in[nbr]++;
            }
            
        }
        vector<int>ans;
        
        for(int i=0;i<n;i++){
            if(in[i] == 0) ans.push_back(i);
        }
        return ans;
    }
};