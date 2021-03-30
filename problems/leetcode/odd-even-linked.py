# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        if not head:
            return head
        n = head
        temp_head = head.next
        i = 0
        while n.next and n.next.next:
            temp = n.next
            n.next = n.next.next
            n = temp
            i = i + 1 
        if i % 2 == 0:
            n.next = temp_head
        else:
            t = n.next
            n.next = None
            t.next = temp_head
        return head