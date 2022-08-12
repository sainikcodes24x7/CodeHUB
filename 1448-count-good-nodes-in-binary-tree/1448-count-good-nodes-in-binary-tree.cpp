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
    void helper(TreeNode* root, int prev, int &c)
    {
        if(!root)
            return;
        if(root->val>=prev)
            c++;
        helper(root->left,max(prev,root->val),c);
        helper(root->right,max(prev,root->val),c);
    }
    int goodNodes(TreeNode* root) {
        int c=0;
        helper(root,root->val,c);
        return c;
    }
};