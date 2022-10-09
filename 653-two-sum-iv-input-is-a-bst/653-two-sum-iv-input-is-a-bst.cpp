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
    unordered_map<int,int>mp;
    bool findTarget(TreeNode* root, int k) {
        if(!root)
            return false;
        
        if(mp.find(root->val)!=mp.end())
        {
            return true;
        }
        else{
            mp[k-root->val]=1;
        }
        
        if(findTarget(root->left,k))
            return true;
        if(findTarget(root->right,k))
            return true;
        return false;
    }
};