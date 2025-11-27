#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) // Binary search for peak element
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[mid + 1])
            {
                high = mid; // Peak is in the left half (or at mid)
            }
            else
            {
                low = mid + 1; // Peak is in the right half
            }
        }
        return low; // Peak element index
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    int peakIndex = sol.findPeakElement(nums);
    cout << "Peak element index: " << peakIndex << endl;
    return 0;
}