# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        countA = 0
        countB = 0
        nodeA = headA
        nodeB = headB
        while nodeA:
            nodeA = nodeA.next
            countA += 1
        while nodeB:
            nodeB = nodeB.next
            countB += 1
        nodeA = headA
        nodeB = headB
        if countA > countB:
            for i in range(countA - countB):
                nodeA = nodeA.next
        else:
            for i in range(countB - countA):
                nodeB = nodeB.next
        while nodeA != nodeB:
                nodeA = nodeA.next
                nodeB = nodeB.next
        return nodeA