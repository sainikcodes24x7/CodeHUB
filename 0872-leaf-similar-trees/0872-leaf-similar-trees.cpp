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
   void dfs(TreeNode* node, vector<int>& seq)
    {
        if(!node) return;
        if(!node->left && !node->right)
            seq.push_back(node->val);
        dfs(node->left, seq);
        dfs(node->right, seq);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> leafseq1, leafseq2;
        dfs(root1, leafseq1);
        dfs(root2, leafseq2);
        return leafseq1==leafseq2;
    }
};