#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> subNum;
        subNum[0] = 1;
        int total = 0, count = 0;

        for (int n : nums)
        {
            total += n;

            if (subNum.find(total - k) != subNum.end())
            {
                count += subNum[total - k];
            }

            subNum[total]++;
        }

        return count;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    int k = 2;
    cout << sol.subarraySum(nums, k) << endl; // Output: 2
    return 0;
}