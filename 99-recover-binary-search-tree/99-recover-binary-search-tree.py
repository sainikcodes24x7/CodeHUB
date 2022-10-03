# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        done = True
        def recur(node, not_less_than, not_greater_than):
            nonlocal done
            if not_less_than and node.val < not_less_than.val:
                node.val, not_less_than.val = not_less_than.val, node.val
                done = True                
            if not_greater_than and node.val > not_greater_than.val:
                node.val, not_greater_than.val = not_greater_than.val, node.val
                done = True                
            if not done and node.left: recur(node.left, not_less_than, node)
            if not done and node.right: recur(node.right, node, not_greater_than)
        while done:                
            done = False
            recur(root, None, None)