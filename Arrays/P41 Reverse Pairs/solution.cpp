#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int merge(vector<int> &nums, int low, int mid, int high)
    {
        int cnt = 0;
        int j = mid + 1;
        for (int i = low; i <= mid; i++)
        {
            while (j <= high && nums[i] > 2LL * nums[j]) // Use 2LL to prevent integer overflow
            {
                j++;
            }
            cnt += (j - (mid + 1)); // Count the number of valid pairs
        }

        vector<int> temp;
        int left = low, right = mid + 1; // Pointers for left and right subarrays
        while (left <= mid && right <= high) // Merge the two sorted halves
        {
            if (nums[left] <= nums[right])
            {
                temp.push_back(nums[left++]); // Append smaller element to temp
            }
            else
            {
                temp.push_back(nums[right++]); // Append smaller element to temp
            }
        }

        while (left <= mid)
        {
            temp.push_back(nums[left++]); // Append remaining elements from left subarray
        }

        while (right <= high)
        {
            temp.push_back(nums[right++]); // Append remaining elements from right subarray
            // nums[i] = temp[i - low];
        }

        for (int i = low; i <= high; i++)
        {
            nums[i] = temp[i - low]; // Copy back the merged elements to original array
        }

        return cnt;
    }

    int mergesort(vector<int> &nums, int low, int high)
    {
        if (low >= high)
            return 0;
        int mid = (low + high) / 2;
        int inv = mergesort(nums, low, mid);
        inv += mergesort(nums, mid + 1, high);
        inv += merge(nums, low, mid, high);
        return inv;
    }

    int reversePairs(vector<int> &nums)
    {
        return mergesort(nums, 0, nums.size() - 1);
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 2, 3, 1};
    cout << sol.reversePairs(nums) << endl;
    return 0;
}