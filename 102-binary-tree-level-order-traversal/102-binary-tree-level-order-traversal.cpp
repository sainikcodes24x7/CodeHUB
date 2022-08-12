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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)
            return ans;
        
        queue<TreeNode*>pn;
        pn.push(root);
        while(pn.size()!=0)
        {
            vector<int>k;
            int n=pn.size();
            for(int i=0;i<n;i++)
            {
                 TreeNode* top=pn.front();
                pn.pop();
                if(top->left)
                    pn.push(top->left);
                if(top->right)
                    pn.push(top->right);
                k.push_back(top->val);
            }
           ans.push_back(k);
        }
        return ans;
    }
};