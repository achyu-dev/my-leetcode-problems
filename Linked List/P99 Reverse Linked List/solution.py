from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:

        #O(n) solution, O(1) space 

        # prev, curr = None, head
        # while curr:
        #     nxt = curr.next
        #     curr.next = prev
        #     prev = curr
        #     curr = nxt
        
        # return prev

        #Recursive solution - O(n) , O(n)

        if not head:
            return None
        
        temp = head
        if head.next:
            temp = self.reverseList(head.next)
            head.next.next = head
        
        head.next = None
        
        return temp


# test
def print_list(node):
    while node:
        print(node.val, end=" -> ")
        node = node.next
    print("None")
head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
solution = Solution()
reversed_head = solution.reverseList(head)
print_list(reversed_head)       