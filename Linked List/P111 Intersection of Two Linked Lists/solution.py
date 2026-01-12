from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        l1, l2 = headA, headB
        while l1 != l2:
            l1 = l1.next if l1 else headB
            l2 = l2.next if l2 else headA
        
        return l1

if __name__ == "__main__":
    # Example usage:
    # Creating two intersecting linked lists:
    # List A: 1 -> 2 \
    #                  -> 3 -> 4
    # List B:      6 /
    
    intersecting_node = ListNode(3)
    intersecting_node.next = ListNode(4)

    headA = ListNode(1)
    headA.next = ListNode(2)
    headA.next.next = intersecting_node

    headB = ListNode(6)
    headB.next = intersecting_node

    solution = Solution()
    intersection = solution.getIntersectionNode(headA, headB)
    
    if intersection:
        print(f"Intersected at node with value: {intersection.val}")
    else:
        print("No intersection")       