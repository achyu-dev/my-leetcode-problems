#include <bits/stdc++.h>
using namespace std;

class Solution{
    private:
    int func(int id, int sum, vector<int>&sums) {
        int p = sums.size();
        // base case
        if (sum == 0) return 1;
        if (sum < 0 || id >= p) return 0;

        return func(id + 1, sum - sums[id], sums) + func(id + 1, sum, sums);

    }

    public:    	
    int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    	return func(0, k, nums);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 6, 4, 12, 12, 32, 12, 12};
    int k = 24;
    cout << sol.countSubsequenceWithTargetSum(nums, k) << endl;
    return 0;
}