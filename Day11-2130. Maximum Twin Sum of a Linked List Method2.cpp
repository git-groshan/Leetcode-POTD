#include<bits/stdc++.h>
using namespace std;
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
    // Methode 2 revers Linked list after mid 
    void printLL(ListNode* head){
        while(head !=NULL){
            cout<<head->val<<" ";
            head = head->next;
        }
    }
      ListNode* reverseList(ListNode* head) {
    ListNode* current,*prev,*next;
   current=head;
   prev=NULL;
   while(current!=NULL){
       next=current->next;
       current->next=prev;
       prev=current;
       current=next;
   }
   
   return prev;
        
    }
    
    int pairSum(ListNode* head) {
        ListNode * slow = head , *fast = head->next;
        
        while(fast!=NULL and fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // now reverse LL starting from slow 
        slow->next = reverseList(slow->next);
        
        fast = head;
        slow = slow->next;
        // printLL(head);
        cout<<endl;
        // cout<<"slow ->data "<<slow->val;
        int mx = INT_MIN;
        while(slow!=NULL){
            mx = max(mx , slow->val + fast->val);
            slow = slow ->next;
            fast = fast->next;
        }
        return mx;
    }
};