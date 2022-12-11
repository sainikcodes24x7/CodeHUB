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
    int subTreesum(TreeNode* root,int& mx)
    {
        if(root==NULL) return 0;

        // we are using max function over here because as we know node can be negative , and we also know that when we take negatuve nodes
        // then they will reduce our path cost but we need to maximize it as much as possible
        // so whenever we got negative node then just take 0 instead of negative value
        int l = max(0,subTreesum(root->left,mx));
        int r = max(0,subTreesum(root->right,mx));

        int curr = root->val+l+r;                             // curr node + left node + right node (path sum for curr node)
        cout<<curr<<" ";

        mx = max(mx,curr);                                    // took max out of all

        return root->val+max(l,r);                            // max(l,r) means we will chose one path that will gave max path sum to us
    }
    int maxPathSum(TreeNode* root) 
    {
        int mx = INT_MIN;
        subTreesum(root,mx);
        return mx;
    }

};