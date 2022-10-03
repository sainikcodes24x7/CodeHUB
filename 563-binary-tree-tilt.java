class Solution {
    
    int res = 0;
    
    public int findTilt(TreeNode root) {
        calc(root);
        return res;        
    }
    
    public int calc(TreeNode root) {
        if(root == null)
            return 0;
        int l = calc(root.left);
        int r = calc(root.right);
        res += Math.abs(l - r);
        return l + r + root.val;
    }
    
}
