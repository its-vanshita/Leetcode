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
    ListNode* iterative(ListNode* l1,ListNode* l2){
          
             ListNode* ans = new ListNode(-1);
             ListNode* it = ans;
             int carry = 0;

             while(l1 || l2 || carry){

                int a = l1?l1->val:0;
                int b = l2?l2->val:0;

                int sum = a + b + carry;
                int digit = sum % 10;
                carry = sum /10;

                ListNode* newNode = new ListNode(digit);
                it->next = newNode;
                it = it ->next;

                l1=l1?l1->next:NULL;
                l2=l2?l2->next:NULL;
             }

            ListNode* finalAns = ans -> next;
            delete ans;
            return finalAns;
             
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* ans = iterative(l1,l2);
        return ans;
    }
};