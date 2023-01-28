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
    TreeNode* rightest(TreeNode* root)
    {
        if(root->right==NULL)
            return root;
        return rightest(root->right);
    }
    void flatten(TreeNode* root) {
        if(!root)
            return;
        TreeNode* nextright;
        TreeNode* rightmost;
        
        while(root)
        {
            if(root->left)
            {
                rightmost=rightest(root->left);
                nextright=root->right;
                root->right=root->left;
                root->left=NULL;
                rightmost->right=nextright;
            }
            root=root->right;
        }
    }
};