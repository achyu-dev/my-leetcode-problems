#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPlaceCows(const vector<int> &nums, int k, int distance)
    {
        int count = 1; // Place the first cow at the first position
        int lastPosition = nums[0];
        for (size_t i = 1; i < nums.size(); ++i)
        {
            if (nums[i] - lastPosition >= distance)
            {
                count++;
                lastPosition = nums[i];
                if (count == k)
                {
                    return true;
                }
            }
        }
        return false;
    }

    int aggressiveCows(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int left = 1, right = nums.back() - nums.front(), ans = 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (canPlaceCows(nums, k, mid))
            {
                ans = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> stalls = {4, 2, 1, 3, 6};
    int k = 2;
    cout << "Maximum minimum distance: " << solution.aggressiveCows(stalls, k) << endl;
    return 0;
}