#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    void swap(ListNode* t1 , ListNode* t2){
        int val = t1->val;
        t1->val = t2->val;
        t2->val = val;
        
    }
    ListNode* swapPairs(ListNode* head) {
        ListNode *temp = head;
        while( temp!=NULL and temp->next!=NULL   ){
            swap(temp , temp->next);
            temp = temp->next->next;
        }
        return head;
    }
};