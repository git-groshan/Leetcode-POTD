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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *ptr1 = head, *ptr2 = head, *kth = NULL;
        while (--k)
            ptr1 = ptr1->next;
        
        kth = ptr1;
        ptr1 = ptr1->next;
        
        while (ptr1) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        swap(ptr2->val, kth->val);
        return head;
    }
};

class Solution2 {
public:
    ListNode* getKth(ListNode* head , int k){
        ListNode* temp = head;
        while(--k) temp = temp->next;
        return temp;
    }
    
    ListNode* getKthFromEnd(ListNode* head , int k){
        ListNode* temp = head;
        int sz=0;
        while(temp!=NULL){
            temp = temp->next;
            sz++;
        }
        temp = head;
        int kth = sz - k + 1;
        while(--kth) temp = temp->next;
        
        return temp;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* start = getKth(head , k );
        ListNode* end = getKthFromEnd(head , k);
        
        int val = start->val;
        start->val = end->val;
        end->val = val;
        
        return head;
        
        
    }
};