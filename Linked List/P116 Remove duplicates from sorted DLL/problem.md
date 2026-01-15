Given the head of a doubly linked list with its values sorted in non-decreasing order. Remove all duplicate occurrences of any value in the list so that only distinct values are present in the list.


Return the head of the modified linked list.

Example 1

Input: head -> 1 <-> 1 <-> 3 <-> 3 <-> 4 <-> 5

Output: head -> 1 <-> 3 <-> 4 <-> 5

Explanation: head -> 1 <-> 1 <-> 3 <-> 3 <-> 4 <-> 5

The underlined nodes were deleted to get the desired result.

Example 2

Input: head -> 1 <-> 1 <-> 1 <-> 1 <-> 1 <-> 2

Output: head -> 1 <-> 2

Explanation: head -> 1 <-> 1 <-> 1 <-> 1 <-> 1 <-> 2

The underlined nodes were deleted to get the desired result.

Constraints

    1 <= number of nodes in the linked list <= 105
    -104 <= ListNode.val <= 104
    Values of nodes are sorted in non-decreasing order.