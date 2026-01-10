from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
        
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head.next is None:
            return None
        
        slow = fast = head
        prev = None
        while fast and fast.next:
            prev = slow
            fast = fast.next.next
            slow = slow.next
        
        prev.next = prev.next.next
        return head
        
def main():
    # Example usage:
    sol = Solution()
    
    # Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
    
    # Deleting the middle node
    new_head = sol.deleteMiddle(head)
    
    # Printing the modified linked list
    current = new_head
    while current:
        print(current.val, end=" -> " if current.next else "")
        current = current.next
    

if __name__ == "__main__":
    main()