#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0;
        //int r = 0;
        for(int r = 0 ; r < nums.size() ; r++) {
            if (nums[r] != 0) {
                swap(nums[r], nums[l]);
                l++;
            }
        }
    }
};

// Could you minimize the total number of operations done?
// Yes, we can do this in a single pass without using extra space.
class Solution2 {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0;
        for(int r = 0 ; r < nums.size() ; r++) {
            if (nums[r] != 0) {
                if (l != r) {
                    nums[l] = nums[r];
                    nums[r] = 0;
                }
                l++;
            }
        }
    }
};


int main() {
    Solution sol;
    vector<int> nums = {0, 1, 0, 3, 12, 44, 17};
    sol.moveZeroes(nums);
    for (int num : nums) {
        cout << num << " ";
    }
    return 0;
}