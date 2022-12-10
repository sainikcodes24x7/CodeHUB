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
     int MOD = 1e9 + 7;
    long long treeSum = 0, result = 0, subTreeSum;
    
    int maxProduct(TreeNode* root) {
        treeSum = totalSumSubTree(root) , totalSumSubTree(root);
        return result % MOD;
    }
    int totalSumSubTree(TreeNode* root){
        if(!root) return 0;
        subTreeSum = totalSumSubTree(root->left) + totalSumSubTree(root->right) + root->val;
        result = max(result, subTreeSum * (treeSum - subTreeSum));
        return subTreeSum;

    } 
};