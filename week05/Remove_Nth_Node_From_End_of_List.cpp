//Time Complexity O(n),n is the number of node in the list.
//Space Complexity O(1)


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         ListNode *curr=head;
        ListNode *dummy=head;

        while(n--){
            dummy=dummy->next;
        }

        while(dummy->next!=NULL){
            curr=curr->next;
            dummy=dummy->next;

        }

        curr->next=curr->next->next;

        return head;
    }
};
