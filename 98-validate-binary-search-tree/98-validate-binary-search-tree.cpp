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
    long leftmax=LONG_MIN;
    long rightmin=LONG_MAX;
    bool helper(TreeNode* root,long leftmax, long rightmin)
    {
        if(!root)
            return true;
        return ( root->val >leftmax and root->val<rightmin and helper(root->left,leftmax,root->val) and helper(root->right,root->val,rightmin));
    }
    bool isValidBST(TreeNode* root) {
        return helper(root,leftmax,rightmin);
    }
};