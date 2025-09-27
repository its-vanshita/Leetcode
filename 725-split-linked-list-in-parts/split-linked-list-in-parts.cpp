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
    int getLength(ListNode* head){
        int len=0;
        ListNode* temp=head;

        while(temp!=NULL){
            len++;
            temp=temp->next;
        }

        return len;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        int L = getLength(head);
        int eachBucketNode = L/k;
        int extraNode = L%k;

        vector<ListNode*> result(k,NULL);
        ListNode* curr = head;
        ListNode* prev = NULL;

        for(int i=0;curr!=NULL && i<k;i++){
            
            result[i]=curr;
           
            for(int count = 1; count<= eachBucketNode + (extraNode>0 ? 1 : 0); count++)
            {
               prev=curr;
               curr=curr->next;
            }

            
            prev->next=NULL;
            extraNode--;
        }

        return result;
    }
};