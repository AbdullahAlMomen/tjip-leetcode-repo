//Time Complexity O(n) where n is the thotal number of nodes
//Space Complextiy O(n/2)==O(n), where n is total nodes in the list.
class Solution {
public:

    int size(ListNode *head){
        ListNode *curr=head;
        int n=0;
        while(curr!=NULL)
        {   n++;
            curr=curr->next;
        }
        return n;

    }

    ListNode *moveDummy(ListNode *head,int &count){
        ListNode *copyHead=head;
        while(count--){
            copyHead=copyHead->next;
        }

        return copyHead;
    }

    void copyCreate(ListNode *dummy,ListNode *currCp){

         while(dummy!=NULL){
            currCp->next=dummy;;
            dummy=dummy->next;
            currCp=currCp->next;
        }
    }

    ListNode  *reverse(ListNode *head){
        ListNode *prev=NULL;
        ListNode *curr=head;
        ListNode *nxt=NULL;

        while(curr!=NULL){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;

    }

    int maxSum(ListNode *curr,ListNode *newHead,int &count){
        int maxElement=0;
        while(count--){
            int sum=0;
            if(curr && newHead){
                sum=curr->val+newHead->val;
                curr=curr->next;
                newHead=newHead->next;
                maxElement=max(maxElement,sum);
            }

        }

        return maxElement;
    }

    int pairSum(ListNode* head) {
        int n=size(head);

        ListNode *curr=head;
        ListNode *dummy=head;
        int count=n/2;

        dummy=moveDummy(dummy,count);

        ListNode *cpHead=dummy;
        ListNode *currCp=dummy;
        dummy=dummy->next;

        copyCreate(dummy,currCp);

        cpHead=reverse(cpHead);

        count=n/2;
       int ans= maxSum(curr,cpHead,count);

        return ans;


    }
};
