#include <bits/stdc++.h>
using namespace std;

class Solution{
    private:
    bool func(vector<int>&res, int k, int index) {
        if (k == 0) return true;
        if (k < 0 || index == res.size()) return false;

        return func(res, k - res[index], index + 1) || func(res, k, index + 1);
    }
    public:
    bool checkSubsequenceSum(vector<int>& nums, int k) {
        return func(nums, k, 0);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 6, 4, 12, 12, 32, 12, 12};
    int k = 24;
    cout << (sol.checkSubsequenceSum(nums, k) ? "Yes" : "No") << endl;
    return 0;
}