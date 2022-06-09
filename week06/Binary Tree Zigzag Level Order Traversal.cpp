
//Time Complexity: O(n) where n is number of nodes
//Space Complexity:O(h) height of the tree
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(!root)
            return {};
        queue<TreeNode*>q;
        q.push(root);
        bool flag=true;
        while(!q.empty()){
            vector<int>ans;


            for(int i=q.size();i>0;i--){
                auto curr=q.front();
                q.pop();
                ans.push_back(curr->val);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);

            }
            if(flag)
                result.push_back(ans);
            else
            {
                reverse(ans.begin(),ans.end());
                result.push_back(ans);
            }
            ans.clear();
            flag=!flag;
        }
        return result;
    }
};
