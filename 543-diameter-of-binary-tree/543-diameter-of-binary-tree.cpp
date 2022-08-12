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
    int helper(TreeNode* root, int &d)
    {
        if(!root)
            return 0;
        int lefth=helper(root->left,d);
        int righth=helper(root->right,d);
        d=max(d,lefth+righth);
        return 1+max(lefth,righth);
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        helper(root,diameter);
        return diameter;
    }
};