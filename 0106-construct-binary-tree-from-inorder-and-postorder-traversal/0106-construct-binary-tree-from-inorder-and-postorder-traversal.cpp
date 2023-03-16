class Solution {
public:

    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, unordered_map<int, int>& ump, int& rootIdx, int left, int right) {
        if(left > right) return NULL;
        
        int pivot = ump[postorder[rootIdx]];
        TreeNode* node = new TreeNode(postorder[rootIdx]);
        rootIdx--;

        node->right = buildTreeHelper(inorder, postorder, ump, rootIdx, pivot+1, right);
        node->left = buildTreeHelper(inorder, postorder, ump, rootIdx, left, pivot-1);
        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int rootIdx = postorder.size()-1;
        unordered_map<int, int> ump;
        for(int i=0;i<inorder.size();i++) ump[inorder[i]] = i;

        return buildTreeHelper(inorder, postorder, ump, rootIdx, 0, inorder.size()-1);
    }
};