from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

# Tortoise and Hare Algorithm
# Floyd's Cycle-Finding Algorithm
class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        slow, fast = head, head

        while (fast and fast.next): # Check if fast and fast.next are not None
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                return True

        return False