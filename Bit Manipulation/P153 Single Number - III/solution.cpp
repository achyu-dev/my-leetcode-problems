#include <bits/stdc++.h>
using namespace std;

// using hashmap - TC O(n) and SC O(n)
class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        vector<int> result;
        for (auto it : mp)
        {
            if (it.second == 1)
            {
                result.push_back(it.first);
            }
        }
        return result;
    }
};

class SolutionBitManipulation
{
public:
    vector<int> singleNumber(vector<int>& nums) {
        // Step 1: XOR all numbers to get the XOR of the two unique numbers
        int xorResult = 0;
        for (int num : nums) {
            xorResult ^= num;
        }
        // Step 2: Find a set bit (rightmost set bit) in xorResult
        int setBit = xorResult & -xorResult;
        // Step 3: Divide numbers into two groups based on the set bit and XOR
        // separately
        int num1 = 0, num2 = 0;
        for (int num : nums) {
            if (num & setBit) {
                num1 ^= num; // Group 1
            } else {
                num2 ^= num; // Group 2
            }
        }
        return {num1, num2};
    }
};

int main()
{
    SolutionBitManipulation sol;
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    vector<int> result = sol.singleNumber(nums);
    for (int i : result)
    {
        cout << i << " ";
    }
    return 0;
}