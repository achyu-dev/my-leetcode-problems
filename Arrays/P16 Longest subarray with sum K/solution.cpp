#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        
        unordered_map<int, int> prefixSumIndex;
        int prefixSum = 0;
        int maxLength = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];

            if (prefixSum == k) {
                maxLength = i + 1;
            }

            if (prefixSumIndex.find(prefixSum) == prefixSumIndex.end()) {
                prefixSumIndex[prefixSum] = i;
            }

            if (prefixSumIndex.find(prefixSum - k) != prefixSumIndex.end()) {
                int length = i - prefixSumIndex[prefixSum - k];
                maxLength = max(maxLength, length);
            }
        }

        return maxLength;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {-1, 1, 1};
    int k = 1;
    cout << sol.longestSubarray(nums, k) << endl; // Output: 4
    return 0;
}