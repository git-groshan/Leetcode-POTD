#include<bits/stdc++.h>
using namespace std;

//Problem link 
//https://leetcode.com/problems/minimum-absolute-difference-in-bst/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root , int &prev  , int &ans ){
        if(root==NULL) return;
        inorder(root->left , prev , ans);
        cout<<"ans "<<ans<<endl;
        if(prev!=-1) ans = min(ans , abs(root->val - prev));
        prev = root->val;
        cout<<"prev "<<prev<<endl;
        inorder(root->right , prev , ans);
         cout<<"ans "<<ans<<endl;
    }
    int getMinimumDifference(TreeNode* root) {
       int ans = INT_MAX;
        int prev = -1;
        inorder(root , prev , ans);
        return ans;
        
    }
};