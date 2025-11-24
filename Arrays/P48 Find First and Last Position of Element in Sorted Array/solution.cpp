#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1;
        int last = -1;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == target) {
                first = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] == target) {
                last = i;
                break;
            }
        }
        return {first, last};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    vector<int> result = sol.searchRange(nums, target);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}