//Time Complexity O(n) where n is total number of node in the two list.
//Space Complexity don't sure, may be O(n) total number of node in the two list.
class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int carry=0;
        ListNode *newHead=new ListNode(0);
        ListNode *curr=newHead;
        while(l1 || l2 || carry==1){
            int sum=0;
            if(l1!=NULL){
                 sum+= l1->val;
                 l1=l1->next;
            }

            if(l2!=NULL)
            {
                 sum+= l2->val;
                 l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;

            ListNode *newNode=new ListNode(sum%10);
            curr->next=newNode;
            curr=newNode;

        }

        return newHead->next;
    }
};
