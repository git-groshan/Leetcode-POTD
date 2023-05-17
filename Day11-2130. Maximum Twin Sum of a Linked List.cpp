#include<bits/stdc++.h>
using namespace std;

// problem link 
// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

// Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
    ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int>v;
        ListNode* temp  = head;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp = temp->next;
        }
        int i=0 , j = v.size() -1;
        long long int  maxTwinSum = INT_MIN;
        while(i<j){
            long long int sum = v[i++] + v[j--];
            maxTwinSum = max(maxTwinSum , sum);
        }
        return maxTwinSum;
    }
};