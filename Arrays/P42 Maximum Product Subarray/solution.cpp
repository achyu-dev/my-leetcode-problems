#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int maxProd = nums[0];
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int prod = 1;
                for (int k = i; k <= j; k++)
                {
                    prod *= nums[k];
                }
                maxProd = max(maxProd, prod);
            }
        }
        return maxProd;
    }
};

class SolutionOptimal
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int pre = 1, suf = 1;
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (pre == 0)
                pre = 1;
            if (suf == 0)
                suf = 1;
            pre *= nums[i];         // left to right
            suf *= nums[n - i - 1]; // right to left
            ans = max(ans, max(pre, suf));
        }
        return ans;
    }
};

int main()
{
    SolutionOptimal sol;
    vector<int> nums = {2, 3, -2, 4};
    cout << sol.maxProduct(nums) << endl;
    return 0;
}