Problem Statement: Given two sorted arrays a and b of size m and n respectively. Find the kth element of the final sorted array.
Examples

Example 1:  
Input: a = [2, 3, 6, 7, 9], b = [1, 4, 8, 10], k = 5  
Output: 6  
Explanation: The final sorted array would be [1, 2, 3, 4, 6, 7, 8, 9, 10]. The 5th element of this array is 6.

Example 2:  
Input: a = [100, 112, 256, 349, 770], b = [72, 86, 113, 119, 265, 445, 892], k = 7  
Output: 256  
Explanation: The final sorted array is [72, 86, 100, 112, 113, 119, 256, 265, 349, 445, 770, 892]. The 7th element of this array is 256.

Examples

Example 1:  
Input: a = [2, 3, 6, 7, 9], b = [1, 4, 8, 10], k = 5  
Output: 6  
Explanation: The final sorted array would be [1, 2, 3, 4, 6, 7, 8, 9, 10]. The 5th element of this array is 6.

Example 2:  
Input: a = [100, 112, 256, 349, 770], b = [72, 86, 113, 119, 265, 445, 892], k = 7  
Output: 256  
Explanation: The final sorted array is [72, 86, 100, 112, 113, 119, 256, 265, 349, 445, 770, 892]. The 7th element of this array is 256.

Constraints:

    1 <= m, n <= 104
    0 <= arr1[i[, arr2[i] < 109
    1 <= k <= m+n