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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
            return NULL;
        
        // exchange the values
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;
        
        //left recursive call
        if(root->left)
        {
            TreeNode* leftc=invertTree(root->left);
        }
        
        //right recursive call
        if(root->right)
        {
            TreeNode* rightc=invertTree(root->right);
        }
        return root;
    }
};