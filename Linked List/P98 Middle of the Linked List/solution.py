# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

from typing import Optional

class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow, fast= head, head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        return slow
        
# usage
head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
sol = Solution()
middle = sol.middleNode(head)
print(middle.val)