//Time Complexity: O(n) where n is number of nodes
//Space Complexity:O(n)
class Solution {
public:

    void bfs(TreeNode* root, int &height){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            height++;

            for(int i=q.size();i>0;i--){
                TreeNode *curr=q.front();
                q.pop();
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
        }
    }

    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
       int height=0;
        bfs(root,height);
        return height;

    }
};
