#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKRotation(vector<int> &nums)  {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            if (nums[low] <= nums[high]) {
                return low;
            }
            int mid = low + (high - low) / 2;
            int next = (mid + 1) % n;
            int prev = (mid - 1 + n) % n;
            if (nums[mid] <= nums[next] && nums[mid] <= nums[prev]) {
                return mid;
            } else if (nums[mid] <= nums[high]) {
                high = mid - 1;
            } else if (nums[mid] >= nums[low]) {
                low = mid + 1;
            }
        }
        return 0;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {15, 18, 2, 3, 6, 12};
    cout << "The array is rotated " << sol.findKRotation(nums) << " times." << endl;
    return 0;
}