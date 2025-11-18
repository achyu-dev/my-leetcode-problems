#include <bits/stdc++.h>
using namespace std;

// Brute force solution
class Solution
{
public:
    int subarraysWithXorK(vector<int> &nums, int k)
    {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int xorr = 0;
                for (int k = i; k <= j; k++)
                {
                    xorr = xorr ^ nums[k];
                }
                if (xorr == k)
                    cnt++;
            }
        }
        return cnt;
    }
};

// Better solution -
class SolutionBetter
{
public:
    int subarraysWithXorK(vector<int> &nums, int k)
    {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int xorr = 0;
            for (int j = i; j < n; j++)
            {
                xorr ^= nums[j];
                if (xorr == k)
                    cnt++;
            }
        }
        return cnt;
    }
};

// Optimal solution - using hashing
/*
First, we will declare a map to store the prefix XORs and their counts.
Then, we will set the value of 0 as 1 on the map.
Then we will run a loop(say i) from index 0 to n-1(n = size of the array).
For each index i, we will do the following:
    We will XOR the current element i.e. arr[i] to the existing prefix XOR.
    Then we will calculate the prefix XOR i.e. xr^k, for which we need the occurrence.
    We will add the occurrence of the prefix XOR xr^k i.e. mpp[xr^k] to our answer.
    Then we will store the current prefix XOR, xr in the map increasing its occurrence by 1.
*/
class SolutionOptimal
{
public:
    int subarraysWithXorK(vector<int> &nums, int k)
    {
        unordered_map<int, int> mpp; // TC - O(n), but if using map, then TC - O(nlogn)
        int n = nums.size();
        mpp[0] = 1;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            // We will XOR the current element i.e. arr[i] to the existing prefix XOR.
            if (i > 0)
            {
                nums[i] ^= nums[i - 1];
            }
            int xr = nums[i];
            int target = xr ^ k;
            if (mpp.find(target) != mpp.end())
            {
                cnt += mpp[target];
            }
            mpp[xr]++;
        }

        return cnt;
    }
};

int main()
{
    SolutionOptimal sol;
    vector<int> nums = {5, 2, 9};
    int k = 7;
    cout << sol.subarraysWithXorK(nums, k) << endl;
    return 0;
}
