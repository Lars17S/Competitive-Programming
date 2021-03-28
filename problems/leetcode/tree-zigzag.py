from collections import deque 

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        l = deque()
        r = deque()
        sol = []
        l.append(root)
        while l or r:
            if l:
                sol.append([])
                while l:
                    n = l.pop()
                    sol[-1].append(n.val)
                    #print(n.val)
                    if n.left != None:
                        r.append(n.left)
                    if n.right != None:
                        r.append(n.right)
            if r:
                sol.append([])
                while r:
                    n = r.pop()
                    #print(n.val)
                    sol[-1].append(n.val)
                    if n.right != None:
                        l.append(n.right)
                    if n.left != None:
                        l.append(n.left)
        return sol