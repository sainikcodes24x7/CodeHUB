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
    TreeNode* construct(vector<int>nums,int s,int e)
    {
        if(s>e)
            return NULL;
        int mid=(s+e)/2;
         TreeNode* root= new  TreeNode(nums[mid]);
        
        // for elements less than mid 
        root->left=construct(nums,s,mid-1);
        
        //for e
        root->right= construct(nums,mid+1,e);
        return root;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)
            return NULL;
        int n=nums.size();
         TreeNode*p=construct(nums,0,n-1);
        return p;
    }
};