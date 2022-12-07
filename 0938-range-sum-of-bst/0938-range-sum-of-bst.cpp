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
    vector<int> rangeSumBST(TreeNode* root,vector<int>&v, int low, int high) {
        if(root==NULL)
        {
           vector<int>p;
            return p;
        }
        if(root->val>low)
        {
            rangeSumBST(root->left,v,low,high);
        }
        if(root->val>=low && root->val <=high){
            v.push_back(root->val);
        }
        if(root->val<high)
        {
            rangeSumBST(root->right,v,low,high);
        }
        return v;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int>v;
        vector<int>output=rangeSumBST(root,v,low,high);
        int sum=0;
        for(int i=0;i<output.size();i++)
        {
            sum+=output[i];
        }
        return sum;
    }
};