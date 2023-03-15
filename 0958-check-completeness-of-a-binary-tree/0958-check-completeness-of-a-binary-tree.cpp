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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        bool isleaf=false;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
        
        {
            TreeNode*top=q.front();
            q.pop();
            if(top==nullptr)
                isleaf=true;
            else
            {
                if(isleaf==true)
                    return false;
                q.push(top->left);
                q.push(top->right);
            }
        }
        }
        return true;
    }
};