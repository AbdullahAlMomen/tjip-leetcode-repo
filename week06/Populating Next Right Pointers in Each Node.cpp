//Time Complexity: O(n) where n is number of nodes
//Space Complexity:O(n)
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return NULL;
        queue<Node *>q;

        q.push(root);
        while(!q.empty()){
            Node *nexNode=NULL;
            for(int i=q.size();i>0;i--){
                auto curr=q.front();
                q.pop();
                curr->next=nexNode;
                nexNode=curr;
                if(curr->right){
                    q.push(curr->right);
                    q.push(curr->left);
                }
            }

        }
        return root;
    }
};
