Given the head of a sorted doubly linked list of positive distinct integers, and a target integer, return a 2D array containing all unique pairs of nodes (a, b) such that a + b == target.


Each pair should be returned as a 2-element array [a, b] with a < b. The list is sorted in ascending order. If there are no such pairs, return an empty list.

Example 1

Input: head = [1, 2, 4, 5, 6, 8, 9], target = 7

Output: [[1, 6], [2, 5]]

Explanation:

1 + 6 = 7 and 2 + 5 = 7 are the valid pairs.

Example 2

Input: head = [1, 5, 6], target = 6

Output: [[1, 5]]

Explanation:

1 + 5 = 6 is the only valid pair.

Constraints

    0 <= number of nodes <= 105
    1 <= Node.val <= 105
    1 <= target <= 105
    The linked list is sorted in strictly increasing order
    The linked list is contains distinct values