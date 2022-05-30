//Time Complexity O(n) where n is total number of node in the two list.
//Space Complexity O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode *prev=NULL;
        ListNode *curr=head;
        ListNode *next=NULL;

        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
};
