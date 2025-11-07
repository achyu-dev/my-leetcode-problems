Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.


// brute force
```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // sort array in increasing order and see

        // replace array in place witj frequency of elements
        int n = nums.size();
        int a, b, c;
        if (nums[i] == '0') a+;
        if (nums[i] == '1') b++
        if (nums[i] == '2') c++;

        for (int i = 0; i < cnt0; i++) arr[i] = 0;
        
    }
}; 
```


Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]

 

Constraints:

    n == nums.length
    1 <= n <= 300
    nums[i] is either 0, 1, or 2.

 

Follow up: Could you come up with a one-pass algorithm using only constant extra space?
