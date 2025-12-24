from typing import Optional

# Definition for singly-linked list

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:

        #O(n) solution, O(1) space - iterative approach

        # prev, curr = None, head
        # while curr:
        #     nxt = curr.next
        #     curr.next = prev
        #     prev = curr
        #     curr = nxt
        
        # return prev

        #Recursive solution - O(n) , O(n)

        if not head:
            return None # base case
        
        temp = head
        if head.next:
            temp = self.reverseList(head.next) # recursive call
            head.next.next = head
        
        head.next = None
        
        return temp


if __name__ == "__main__":
    # Create a linked list 1 -> 2 -> 3 -> 4 -> 5
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)

    solution = Solution()
    reversed_head = solution.reverseList(head)

    # Print reversed linked list
    current = reversed_head
    while current:
        print(current.val, end=" -> " if current.next else "")
        current = current.next   