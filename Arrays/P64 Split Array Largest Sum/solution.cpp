#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPartitions(const vector<int> &nums, int maxSum)
    {
        int currentSum = 0;
        int partitions = 1; // Start with one partition
        for (int num : nums)
        {
            if (currentSum + num > maxSum)
            {
                // Need to start a new partition
                partitions++;
                currentSum = num; // Start new partition with current number
            }
            else
            {
                currentSum += num; // Add to current partition
            }
        }
        return partitions;
    }

    int splitArray(vector<int> &nums, int k)
    {
        /*
        First, we will find the maximum element and the summation of the given array.
        We will use a loop to check all possible answers from max(arr[]) to sum(arr[]).
        */
        // Do not use Binary search
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        for (int maxSum = low; maxSum <= high; maxSum++)
        {
            if (countPartitions(nums, maxSum) <= k)
            {
                return maxSum;
            }
        }
        return low;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;
    cout << sol.splitArray(nums, k) << endl;
    return 0;
}