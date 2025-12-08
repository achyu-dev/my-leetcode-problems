Given a non-empty grid mat consisting of only 0s and 1s, where all the rows are sorted in ascending order, find the index of the row with the maximum number of ones.

If two rows have the same number of ones, consider the one with a smaller index. If no 1 exists in the matrix, return -1.
Examples:

Input : mat = [ [1, 1, 1], [0, 0, 1], [0, 0, 0] ]

Output: 0

Explanation: The row with the maximum number of ones is 0 (0 - indexed).

Input: mat = [ [0, 0], [0, 0] ]

Output: -1

Explanation: The matrix does not contain any 1. So, -1 is the answer.

Constraints:

      n == mat.length 
      m == mat[i].length 
      1 <= n, m <= 100 
      mat[i][j] is either 0 or 1.