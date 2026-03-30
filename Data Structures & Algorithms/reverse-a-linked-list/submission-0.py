# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head.next == nil:
            return head
        prev, cur, tmp = nil, head, nil
        tmp = cur.next
        cur.next = prev
        prev = cur
        cur = tmp



    