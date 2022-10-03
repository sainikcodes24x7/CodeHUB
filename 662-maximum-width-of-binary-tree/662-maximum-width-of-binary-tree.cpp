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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int res=1;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            int n=q.size();
            int left=q.front().second;
            int right=q.back().second;
            res=max(res,right-left+1);
            for(int i=0;i<n;i++)
            {
                pair<TreeNode*,int>top=q.front();
                q.pop();
                int idx=top.second-left;
                if(top.first->left)
                    q.push({top.first->left,(long long)2*idx+1});
                if(top.first->right)
                    q.push({top.first->right,(long long)2*idx+2});
            }
        }
        return res;
    }
};