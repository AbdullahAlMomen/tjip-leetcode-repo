//Time Complexity: O(n) where n is number of nodes
//Space Complexity:O(n)
class Solution {
public:

    TreeNode *generateTree(vector<int>& preorder, vector<int>& inorder,int l,int r,int &pos,unordered_map<int,int>&mp){
        if(l>r)
            return NULL;
        int v=preorder[pos++];
        TreeNode *root=new TreeNode(v);
        int m=mp[v];
        root->left=generateTree(preorder,inorder,l,m-1,pos,mp);

        root->right=generateTree(preorder,inorder,m+1,r,pos,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       unordered_map<int,int>mp;
        int pos=0;
        for(int i=0;i<preorder.size();i++){
            mp[inorder[i]]=i;
        }
        return generateTree(preorder,inorder,0,preorder.size()-1,pos,mp);
    }
};
