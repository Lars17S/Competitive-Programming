# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        sol = ListNode(0)
        p = l1
        q = l2
        sol_it = sol
        carry = 0
        while p is not None and q is not None:
            val_sum = p.val + q.val + carry
            if val_sum > 9:
                val_sum = val_sum - 10
                carry = 1
            else: carry = 0
            sol_it.next = ListNode(val_sum)
            sol_it = sol_it.next
            p = p.next
            q = q.next
        fin_it = q if p is None else p
        while fin_it is not None:
            val_sum = fin_it.val + carry
            if val_sum > 9:
                val_sum = val_sum - 10
                carry = 1
            else:
                carry = 0
            sol_it.next = ListNode(val_sum)
            sol_it = sol_it.next
            fin_it = fin_it.next
        if carry == 1:
            sol_it.next = ListNode(carry)
        
        return sol.next