#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int idx, vector<int> &arr, vector<int> &curr, vector<vector<int>> &ans) {
        ans.push_back(curr); // Store the current subset

        for (int i = idx; i < arr.size(); ++i) {
            // Skip duplicates
            if (i > idx && arr[i] == arr[i - 1]) continue;

            curr.push_back(arr[i]);         // Choose the current element
            solve(i + 1, arr, curr, ans);   // Recursively move to the next element
            curr.pop_back();                // Backtrack
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;

        sort(nums.begin(), nums.end());  // Sort the input array to handle duplicates
        solve(0, nums, curr, res);

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> result = sol.subsetsWithDup(nums);

    // Print the result
    for (const auto& subset : result) {
        cout << "[";
        for (const auto& num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}