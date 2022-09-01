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
    void helper(TreeNode* root, int prev, int &count)
    {
        if(!root)
            return;
        if(root->val>=prev)
            count++;
        helper(root->left,max(root->val,prev),count);
        helper(root->right,max(root->val,prev),count);
    }
    int goodNodes(TreeNode* root) {
        if(!root)
            return -1;
        int count=0;
        helper(root,root->val,count);
        return count;
    }
};