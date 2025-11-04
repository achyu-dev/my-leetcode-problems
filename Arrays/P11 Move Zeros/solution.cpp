#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0;
        int n = nums.size();
        for(int r = 0 ; r < n ; r++) {
            if (nums[r] != 0) {
                swap(nums[r], nums[l]);
                l++;
            }
        }
    }
};

// Could you minimize the total number of operations done?
// Yes, in a single pass without using swap. TC = O(n), SC = O(1)
class SolutionOptimized {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0;
        int n = nums.size();
        for(int r = 0 ; r < n ; r++) {
            if (nums[r] != 0) {
                nums[l] = nums[r];
                if (l != r) {
                    nums[r] = 0;
                }
                l++;
            }
        }
    }
};

int main() {
    //Solution sol;
    SolutionOptimized sol;
    vector<int> nums = {0,1,0,3,12};
    sol.moveZeroes(nums);
    for (int num : nums) {
        cout << num << " ";
    }
    return 0;
} 