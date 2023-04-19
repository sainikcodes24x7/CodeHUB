/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* root, int left, int right, int &ans)
    {
        if(!root)
            return;
        ans=max(ans,left);
        ans=max(ans,right);
        helper(root->left,0,left+1,ans);
        helper(root->right,right+1,0,ans);
        return;
    }
    int longestZigZag(TreeNode* root) {
        int left=0;
        int right=0;
        int ans=0;
        helper(root,left,right,ans);
        return ans;
    }
};