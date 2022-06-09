
//Time Complexity : O(n) where n is number of nodes
//Space Complexity:O(h) where h is the height of the tree
class Solution {
public:
    TreeNode *LCA(TreeNode *root,int startValue,int destValue){
        if(!root)
            return NULL;

        if(root->val==startValue || root->val==destValue)
            return root;

        auto l=LCA(root->left,startValue,destValue);
        auto r=LCA(root->right,startValue,destValue);

        if(l && r)
            return root;

        return l?l:r;
    }

    bool traverse(TreeNode *root,string &path,int value){
        if(!root)
            return false;

        if(root->val==value)
            return true;
        path.push_back('L');

        if(traverse(root->left,path,value))
            return true;

        path.pop_back();

        path.push_back('R');
        if(traverse(root->right,path,value))
            return true;

        path.pop_back();

        return false;
    }


    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode * lca=LCA(root,startValue,destValue);
        string startPath="",endPath="";
         traverse(lca, startPath, startValue);
         traverse(lca, endPath, destValue);

        for(auto &p:startPath)p='U';

        return startPath+endPath;

    }
};
