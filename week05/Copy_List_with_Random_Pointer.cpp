//Time Complexity O(n) where n is the total number of nodes
//Space Complexity O(1)
class Solution {
public:

    Node *copyNodeCreate(Node *head){
        auto curr=head;
        while(curr){
            Node *newNode=new Node(curr->val);
            newNode->next=curr->next;
            curr->next=newNode;
            curr=newNode->next;
        }
        return head;
    }
    Node *randomNodeCreate(Node *head){
        auto curr=head;
        while(curr){
            auto track=curr->next;
            if(curr->random)
                track->random=curr->random->next;
            curr=track->next;
        }
        return head;
    }
    Node *extractCopyNode(Node *head){
        if(head==NULL)
            return NULL;
        auto curr=head;
        auto currCp=head->next;
        while(curr){
            auto track=curr->next;
            curr->next=track->next;
            curr=curr->next;
            if(curr)
                track->next=curr->next;
        }
        return currCp;
    }
    Node* copyRandomList(Node* head) {
      auto curr=copyNodeCreate(head);
        curr=randomNodeCreate(curr);
        auto newNode=extractCopyNode(curr);
        return newNode;
    }
};
