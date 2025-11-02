#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return true;

        int drops = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) ++drops;
            if (drops > 1) return false;
        }
        // check the circular boundary
        if (nums[0] < nums[n - 1]) ++drops;
        return drops <= 1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3,4,5,1,2};
    cout << (sol.check(nums) ? "True" : "False") << endl;
    return 0;
}