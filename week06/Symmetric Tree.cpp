//Time Complexity: O(n) where n is number of nodes
//Space Complexity:O(n)
class Solution {
public:
    bool ischeck(TreeNode *l,TreeNode *r){


        if(!l && !r)
            return true;
        if(l && r && (l->val!=r->val))
            return false;
       if((l &&!r)|| (!l && r))
           return false;
        return ischeck(l->left,r->right)&&ischeck(l->right,r->left);
    }
    bool isSymmetric(TreeNode* root) {
        return ischeck(root->left,root->right);

    }
};
