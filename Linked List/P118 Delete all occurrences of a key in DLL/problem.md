Given the head of a doubly linked list and an integer target. Delete all nodes in the linked list with the value target and return the head of the modified linked list.

Example 1

Input: head -> 1 <-> 2 <-> 3 <-> 1 <-> 4, target = 1

Output: head -> 2 <-> 3 <-> 4

Explanation: All nodes with the value 1 were removed.

Example 2

Input: head -> 2 <-> 3 <-> -1 <-> 4 <-> 2, target = 2

Output: head -> 3 <-> -1 <-> 4

Explanation: All nodes with the value 2 were removed.

Note that the value of head is changed.

Constraints

    0 <= number of nodes in the linked list <= 105
    -104 <= ListNode.val <= 104
    -104 <= target <= 104