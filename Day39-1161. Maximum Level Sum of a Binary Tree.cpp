#include<bits/stdc++.h>
using namespace std;

//Problem link 
//https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/


 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int ans_level = 1;
        int level = 1;
        // vector<pair<int , int >>vp;
        // vp.push_back(level)
        int ans = INT_MIN;
        while(!q.empty()){
            int sz = q.size();
            int sum = 0;
            for(int i=0;i<sz;i++ ){
                TreeNode *node = q.front();
                // cout<<"cur_level is "<<level<<endl;
                cout<<" "<<"cur_level_val are : "<<node->val<<" ";
                q.pop();
                sum+=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            cout<<endl;
            cout<<"level "<<level<<" sum is "<<sum<<endl;
            if(sum>ans){
                ans = sum;
               ans_level = level;
                cout<<"ans_level "<<ans_level<<endl;
                
            }
            cout<<"ans is "<<ans;
            level++;
            
        }
        
        return ans_level;
    }
};