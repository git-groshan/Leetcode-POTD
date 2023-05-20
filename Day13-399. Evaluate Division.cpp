#include<bits/stdc++.h>
using namespace std;

//Problem link 
//https://leetcode.com/problems/evaluate-division/

class Solution {
public:
    unordered_map<string  ,vector< pair<string , double>>> graph;
    
    double dfs(string src , string dest , unordered_set<string>&vis){
        
        if(graph.find(src) == graph.end()) return -1.0;
        
        if(src == dest) return 1.0;
        
        vis.insert(src);
        for(auto node : graph[src]){ //node --> pair<string , double>
            if(vis.find(node.first) == vis.end()){
                double res = dfs(node.first , dest , vis);
                if(res!=-1.0) return res*node.second;
            }
        }
        
        return -1;
    }
    
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
            
        int n = equations.size();
        for(int i=0;i<n;i++){
            string ex1 = equations[i][0];
            string ex2 = equations[i][1];
            double val = values[i];
            
            graph[ex1].push_back({ex2 , val});
            graph[ex2].push_back({ex1 , (1/val)});
        }
        
        vector<double>ans;
        
        for(auto query:queries){
            unordered_set<string>vis; // for each query 
            
            ans.push_back(dfs(query[0] , query[1] , vis));
        }
        return ans;
    }
};