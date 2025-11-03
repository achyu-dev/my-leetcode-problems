#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // In case k is greater than n
        vector<int> rotated(n); // Temporary array to hold rotated elements
        
        // Place each element in its new position
        for (int i = 0; i < n; i++) {
            rotated[(i + k) % n] = nums[i]; // Calculate new index and assign
        }

        // Copy the rotated array back to the original array
        for (int i = 0; i < n; i++) {
            nums[i] = rotated[i];
        }        
    }
};

// Could you do it in-place with O(1) extra space?
class SolutionInPlace {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // In case k is greater than n

        // Helper function to reverse a portion of the array
        auto reverse = [&](int start, int end) {
            while (start < end) {
                swap(nums[start], nums[end]);
                start++;
                end--;
            }
        };

        // Reverse the entire array
        reverse(0, n - 1);
        // Reverse the first k elements
        reverse(0, k - 1);
        // Reverse the remaining n-k elements
        reverse(k, n - 1);
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)

int main() {
    Solution sol;
    SolutionInPlace solInPlace;
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    int k = 3;

    sol.rotate(nums, k);
    cout << "Rotated array using extra space: ";

    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    // Test in-place solution
    vector<int> nums2 = {1, 2, 3, 4, 5, 6};
    solInPlace.rotate(nums2, k);
    cout << "Rotated array using in-place method: ";

    for (int num : nums2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}