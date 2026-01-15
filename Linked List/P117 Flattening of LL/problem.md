Given a special linked list containing n head nodes where every node in the linked list contains two pointers:

    ‘Next’ points to the next node in the list
    ‘Child’ pointer to a linked list where the current node is the head

Each of these child linked lists is in sorted order and connected by a 'child' pointer.


Flatten this linked list such that all nodes appear in a single sorted layer connected by the 'child' pointer and return the head of the modified list.

Example 1

Input:

Output: head -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> 11 -> 12

Explanation: All the linked lists are joined together and sorted in a single level through the child pointer.

Example 2

Input:

Output: head -> 2 -> 4 -> 5 -> 10 -> 12 -> 13 -> 16 -> 17 -> 20

Explanation: All the linked lists are joined together and sorted in a single level through the child pointer.

Constraints

    n == Number of head nodes
    1 <= n <= 100
    1 <= Number of nodes in each child linked list <= 100
    0 <= ListNode.val <= 1000
    All child linked lists are sorted in non-decreasing order