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
    vector<vector<int>>ans;
    vector<int>path;
    
    void helper(TreeNode* root, int targetsum, int sum)
    {
        if(root==NULL)
        {
            return;
        }
        path.push_back(root->val);
        sum+=root->val;
        
        if(sum==targetsum and root->left==NULL and root->right==NULL)
        {
            ans.push_back(path);
        }
        helper(root->left,targetsum,sum);
        helper(root->right,targetsum,sum);
        
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum=0;
        helper(root,targetSum,sum);
        return ans;
    }
};
