/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* hasCycle(ListNode *head) {
         ListNode* slow=head;
         ListNode* fast=head;

         while(fast!=NULL){
            fast=fast->next;

            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
            }

            if(fast==slow){
                return fast;
            }
         }
         return nullptr;
    }

    ListNode *detectCycle(ListNode *head) {
      
      ListNode* fast = hasCycle(head);
      if(!fast){
        return nullptr;
      }

      ListNode* slow = head;

      // Check cycle starting point
      while(slow!=fast){
        fast=fast->next;
        slow=slow->next;
      }

      return slow;


    }
};