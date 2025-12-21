Given the head of a doubly linked list and an integer X, insert a node with value X before the head of the linked list and return the head of the modified list.

Example 1

Input: head = [1, 2, 3], X = 3

Output: head = [3, 1, 2, 3]

Explanation: 3 was added before the 1st node. Note that the head's value is changed.

Example 2

Input: head = [5], X = 7

Output: head = [7, 5]

Constraints

    n == Number of nodes in the Linked List
    1 <= n <= 100
    0 <= ListNode.val <= 100
    0 <= X <= 100