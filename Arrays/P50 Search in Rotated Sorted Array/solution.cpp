#include <bits/stdc++.h>
using namespace std;

class SolutionBruteForce {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                return i;
            }
        }
        return -1;
    }
};

class SolutionOptimized {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            // Determine which side is properly sorted
            if (nums[left] <= nums[mid]) { // Left side is sorted
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1; // Target is in the left side
                } else {
                    left = mid + 1; // Target is in the right side
                }
            } else { // Right side is sorted
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1; // Target is in the right side
                } else {
                    right = mid - 1; // Target is in the left side
                }
            }
        }
        return -1;
    }
};

int main() {
    SolutionOptimized solution;
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    int result = solution.search(nums, target);
    cout << "Index of target " << target << ": " << result << endl; // Output: 4
    return 0;
}