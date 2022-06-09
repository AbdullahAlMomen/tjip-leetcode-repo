//Time Complexity O(n) where n is the number of nodes
//Space Complexity O(h) or O(n) whew h is the height of the tree
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;

        else if(root->val==p->val || root->val==q->val)
            return root;

        auto l=lowestCommonAncestor(root->left,p,q);
        auto r=lowestCommonAncestor(root->right,p,q);

        if(l && r)
            return root;
        if(l)
            return l;
        else
            return r;
    }
};
