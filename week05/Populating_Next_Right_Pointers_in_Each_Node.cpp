//Time Complexity O(n), n is total number of nodes
//Space Complexity O(w), w is total number of nodes in the same level.
class Solution {
public:
    Node* connect(Node* root) {
       if(root==NULL) return NULL;
        queue<Node *>q;
        q.push(root);
        while(!q.empty()){
            Node *nextNode=NULL;
            for(int i=q.size();i>0;i--){
                auto curr=q.front();
                q.pop();
                curr->next=nextNode;
                nextNode=curr;
                if(curr->right){
                    q.push(curr->right);
                    q.push(curr->left);
                }
            }
        }
        return root;
    }
};
