from collections import deque

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        if root == None:
            return []
        sol = []
        stack = deque()
        stack.append(root)
        while stack:
            #if p.left != None and p.left not in visited:
            if stack[-1].left != None and stack[-1].left.val != -1000:
                stack.append(stack[-1].left)
                continue
            
            n = stack.pop()
            sol.append(n.val)
            n.val = -1000

            #if n.right != None and p.right not in visited:
            if n.right != None and n.right.val != -1000:
                stack.append(n.right)   
                
        return sol