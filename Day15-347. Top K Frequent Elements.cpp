#include<bits/stdc++.h>
using namespace std;

//problem link 
//https://leetcode.com/problems/top-k-frequent-elements/submissions/


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n = nums.size();
        map<int,int> mp;
        for(int i=0; i<n; i++) mp[nums[i]]++;
        vector<int> ans;
        vector<pair<int,int>> pr;
        for(auto it : mp)
        {
            pr.push_back({it.second,it.first});
            //cout<<it.second<<" "<<it.first<<endl;
            
        }
        sort(pr.begin(),pr.end());
        reverse(pr.begin(),pr.end());
        for(auto it : pr)
            {
               if(k==0) break;
                ans.push_back(it.second);
                k--;
                
            }
        return ans;
    }
};