
//Time Complexity: O(n) where n is number of nodes
//Space Complexity:O(n)
class Solution {
    void check(TreeNode *root,int &k,int &result){
        if(root==NULL)
            return ;
        check(root->left,k,result);
        k--;
        if(k==0)
            result=root->val;
        check(root->right,k,result);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int result;
        check(root,k,result);
        return result;
    }
};
