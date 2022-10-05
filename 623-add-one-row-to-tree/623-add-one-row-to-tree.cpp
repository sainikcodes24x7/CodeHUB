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
    void modify(TreeNode* node, int val, int depth, int currdepth)
    {
        if(!node)
            return;
        if(currdepth==depth-1)
        {
            node->left= new TreeNode(val,node->left,NULL);
            node->right= new TreeNode(val,NULL,node->right);
            return;
        }
        modify(node->left,val,depth,currdepth+1);
        modify(node->right,val,depth,currdepth+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
            root=new TreeNode(val,root,NULL);
        else
            modify(root,val,depth,1);
        return root;
    }
};