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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        queue<TreeNode*>pn;
        pn.push(root);
        //ans.push_back(root->val);
        while(pn.size()!=0)
        {
            int size=pn.size();
            double sum=0;
            for(int i=0;i<size;i++)
            {
                TreeNode*top=pn.front();
                pn.pop();
                sum+=top->val;
                
                if(top->left)
                    pn.push(top->left);
                if(top->right)
                    pn.push(top->right);
            }
           double avg=double(sum/size);
           ans.push_back(avg);
        }
        return ans;
    }
};