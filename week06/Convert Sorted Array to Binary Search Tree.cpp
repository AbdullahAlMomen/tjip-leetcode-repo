
//Time Complexity: O(n) where n is number of nodes
//Space Complexity:O(n)
class Solution {
public:

    TreeNode* constructBST(vector<int>&nums,int l, int r){
        if(l>r)
            return NULL;
        int m=l+(r-l)/2;
        TreeNode *curr=new TreeNode(nums[m]);
        curr->left=constructBST(nums,l,m-1);
        curr->right=constructBST(nums,m+1,r);
        return curr;


    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {

        auto curr= constructBST(nums,0,nums.size()-1);
        return curr;
    }
};
