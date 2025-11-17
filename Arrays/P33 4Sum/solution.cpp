#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach - TC O(N^4) SC O(N)
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        set<vector<int>> res;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    for (int l = k + 1; l < n; l++)
                    {
                        long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                        if (sum == target)
                        {
                            vector<int> quad = {nums[i], nums[j], nums[k], nums[l]};
                            sort(quad.begin(), quad.end());
                            res.insert(quad);
                        }
                    }
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};

// Optimal Appraoch - using hashset
class SolutionOptimal
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int left = j + 1, right = n - 1; // two pointer approach
                while (left < right)
                { // left and right pointer movement
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target)
                    {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        while (left < right && nums[right] == nums[right - 1])
                            right--;
                        left++;
                        right--;
                    }
                    else if (sum < target)
                    {
                        left++;
                    }
                    else
                    {
                        right--;
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> result = sol.fourSum(nums, target);
    for (const auto &quad : result)
    {
        for (int num : quad)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}