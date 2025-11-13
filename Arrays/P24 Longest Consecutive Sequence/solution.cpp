#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int longestStreak = 0;
        int currentStreak = 1;
        int n = nums.size();

        // empty array case
        if (n == 0) return 0;
        
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) {
                if (nums[i] == nums[i - 1] + 1) {
                    currentStreak += 1;
                } else {
                    longestStreak = max(longestStreak, currentStreak);
                    currentStreak = 1;
                }
            }
        }
        return max(longestStreak, currentStreak);
    }
    
};

int main() {
    Solution sol;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << sol.longestConsecutive(nums) << endl;
    return 0;
}