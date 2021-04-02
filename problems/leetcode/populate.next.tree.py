"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def recSol(self, n):
        if not n:
            return
        
        if n.left:
            n.left.next = n.right
            self.recSol(n.left)
            
        if n.right:
            if n.next:
                n.right.next = n.next.left
            self.recSol(n.right)
        
        
    
    def connect(self, root: 'Node') -> 'Node':
        self.recSol(root)
        return root
        