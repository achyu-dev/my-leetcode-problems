from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        gp = dummy

        while True:
            kth = self.getKth(gp, k)
            if not kth:
                break

            gn = kth.next

            # reverse
            prev, curr = kth.next, gp.next

            while curr != gn: # reverse nodes between gp.next and gn
                tmp = curr.next
                curr.next = prev
                prev = curr
                curr = tmp

            tmp = gp.next
            gp.next = kth
            gp = tmp

        return dummy.next

    def getKth(self, curr, k):
        while curr and k > 0:
            curr = curr.next
            k -= 1

        return curr


# Example usage:
if __name__ == "__main__":
    # Create a linked list 1->2->3->4->5
    head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
    k = 2

    solution = Solution()
    new_head = solution.reverseKGroup(head, k)

    # Print the reversed linked list
    curr = new_head
    while curr:
        print(curr.val, end=" -> ")
        curr = curr.next
    print("None")
