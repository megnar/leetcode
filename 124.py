from typing import Optional

"""A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path."""


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

        
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        node, target = self.collectAllDataRecursive(root)
        return target
    
    def collectAllDataRecursive(self, root: Optional[TreeNode]) -> tuple:
        if root is None:
            return None, None
        target = root.val # max of node,
                            #sum_r.node + root.val + sum_l.node,  sum_l.target, sum_r.target
        node = root.val  # max root.val, sum_l.node + root.val, sum_r.node + root.val
        node_l, target_l = self.collectAllDataRecursive(root.left)
        node_r, target_r = self.collectAllDataRecursive(root.right)
        
        # compute node value
        if node_l is not None:
            node = max(node, node_l + root.val)
            target = max(target, target_l)
        if node_r is not None:
            node = max(node, node_r + root.val)
            target = max(target, target_r)
        target = max(target, node)
        #compute target value
        if node_l is not None and node_r is not None:
            target = max(node_l + root.val + node_r, target)

        return node, target
        
    




        