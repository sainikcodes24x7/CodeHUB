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
    unordered_map<TreeNode*,int>mp;
    int robhelper(TreeNode*root)
    {
        if(!root)
            return 0;
        if(!root->left and !root->right)
            return root->val;
        int take=root->val;
        int nottake=robhelper(root->left)+robhelper(root->right);
        
        if(mp.count(root))
            return mp[root];
        
        if(root->left)
            take+=robhelper(root->left->left)+robhelper(root->left->right);
        if(root->right)
            take+=robhelper(root->right->right)+robhelper(root->right->left);
        return mp[root]=max(take,nottake);
    }
   
    int rob(TreeNode* root) {
        
        return robhelper(root);
        //sumofall(root,res);
        //return max(sum,res-sum);
        
    }
};