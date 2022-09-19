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
    void helper(int i, TreeNode* root, pair<int,int>&res)
    {
        if(!root)
            return ;
        if(i>res.first)
        {
            res={i,root->val};
        }
        helper(i+1,root->left,res);
        helper(i+1,root->right,res);
        
    }
    int findBottomLeftValue(TreeNode* root) {
        pair<int,int>res={0,root->val};
        helper(0,root,res);
        return res.second;
    }
};