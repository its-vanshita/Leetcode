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


// also one form of iterative approach (purely done by me)

 void insertAtTail(ListNode* newNode, ListNode* &head, ListNode* &tail){
 
            if(head==NULL){
                head=tail=newNode;
            }

            else{
                tail->next = newNode;
                tail = newNode;
            }
    }


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        ListNode* head = NULL;
        ListNode* tail = NULL;
        int sum = 0;
        int carry = 0;

        while(temp1!=NULL || temp2!=NULL){

            if(temp1==NULL){
               sum = carry + temp2->val; 
            }

            else if(temp2==NULL){
                sum = carry + temp1->val;
            }

            else{
                sum = carry + temp1->val + temp2->val;
            }


            int digit = sum % 10;
            carry = sum / 10;


            ListNode* newNode = new ListNode(digit);
            insertAtTail(newNode,head,tail);

            if(temp1!=NULL){
              temp1 = temp1->next;
            }

            if(temp2!=NULL){
              temp2 = temp2->next;
            }

            
        }

        if(carry){
            ListNode* newNode = new ListNode(carry);
            tail->next = newNode;
            tail=newNode;
        }

        return head;
    }



};
