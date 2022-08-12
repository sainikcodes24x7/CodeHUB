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
    void solve(TreeNode* root, int k,priority_queue<int,vector<int>>&pq)
    {
        
        if(!root)
            return;
        solve(root->left,k,pq);
        if(pq.size()==k)
            return;
        pq.push(root->val);
        solve(root->right,k,pq);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int,vector<int>>pq;
        solve(root,k,pq);
        return pq.top();
    }
};