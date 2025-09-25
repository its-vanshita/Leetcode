/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* getMiddle(ListNode* head, ListNode* &middleNodePrev){

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL){
            fast=fast->next;

            if(fast!=NULL){
                fast=fast->next;
                middleNodePrev=slow;
                slow=slow->next;
            }
        }
        return slow;
    }

    ListNode* reverseList(ListNode* &prev,ListNode* &curr){

          while(curr!=NULL){
            ListNode* forward=curr->next;

            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }


    bool isPalindrome(ListNode* head) {
          //edge-case
        if(head->next==NULL){
            return true;
        }

        ListNode* firstListHead = head;
        ListNode* middleNodePrev=NULL;


        // 1. Find middle node
        ListNode* middleNode = getMiddle(head,middleNodePrev);

        // 2. Break the given LL into two parts
        middleNodePrev->next = NULL;

        // 3. Now reverse the second list

        ListNode* prev=NULL;
        ListNode* curr=middleNode;

        ListNode* secondListHead = reverseList(prev,curr);

        ListNode* temp1 = firstListHead;
        ListNode* temp2 = secondListHead;

        while(temp1!=NULL){
            if(temp1->val != temp2->val)
            {
                return false;
            }
            
                temp1=temp1->next;
                temp2=temp2->next;
        }
      return true;

    }
};