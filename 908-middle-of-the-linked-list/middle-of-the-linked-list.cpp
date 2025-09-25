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

    ListNode* middleNode(ListNode* head) {
        
        int length=getLength(head);
        int pos=length/2;

        ListNode* temp=head;

        for(int i=0;i<pos;i++){
            temp=temp->next;
        }

        return temp;
    }
};