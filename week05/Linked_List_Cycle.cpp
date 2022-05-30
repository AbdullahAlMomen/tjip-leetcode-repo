//Time Complextiy O(n), n is total number of nodes.
//Space Complextiy O(1)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head){
                auto slow=head;
            auto fast=head->next;

            while(slow!=fast){
                if(fast==NULL || fast->next==NULL)
                    return false;
                fast=fast->next->next;
                slow=slow->next;
            }
            return true;
        }
        else
            return false;

    }
};
