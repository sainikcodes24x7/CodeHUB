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
    vector<TreeNode*>helper(int start, int end)
    {
        vector<TreeNode*> v;
        if(start>end)
        {
            v.push_back(NULL);
            return v;
        }
        for(int i=start;i<=end;i++)
        {
            auto left=helper(start,i-1);
            auto right=helper(i+1,end);
            for(auto l:left)
            {
                for(auto r:right)
                {
                    TreeNode* newnode= new TreeNode(i,l,r);
                    v.push_back(newnode);
                }
            }
        }
        return v;
        
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n==0)
            return vector<TreeNode*>();
        auto ans=helper(1,n);
        return ans;
    }
};