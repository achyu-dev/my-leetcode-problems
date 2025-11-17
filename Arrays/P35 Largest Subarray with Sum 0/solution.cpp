#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
class Solution
{
public:
    int maxLen(vector<int> &arr)
    {
        int max = 0;
        int sum = arr[0];
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            sum = arr[i];
            for (int j = i + 1; j < n; j++)
            {
                sum += arr[j];
                if (sum == 0)
                {
                    int len = j - i + 1;
                    if (len > max)
                    {
                        max = len;
                    }
                }
            }
        }
        return max;
    }
};

class SolutionOptimized
{
public:
    int maxLen(vector<int> &arr)
    {
        unordered_map<int, int> prefixSumIndex;
        int maxLength = 0;
        int prefixSum = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++) // Traverse through the array
        {
            prefixSum += arr[i]; // Update the prefix sum

            if (prefixSum == 0)
            {
                maxLength = i + 1; // Update maxLength if prefixSum is 0
            }
            else
            {
                // Check if prefixSum has been seen before
                if (prefixSumIndex.find(prefixSum) != prefixSumIndex.end())
                {
                    maxLength = max(maxLength, i - prefixSumIndex[prefixSum]);
                    // Update maxLength if prefixSum has been seen before
                }
                else // Store the index of the first occurrence of this prefixSum
                {
                    prefixSumIndex[prefixSum] = i;
                }
            }
        }

        return maxLength; // Return the length of the largest subarray with sum 0
    }
};

int main()
{
    SolutionOptimized sol;
    vector<int> arr = {6, -2, 2, -8, 1, 7, 4, -10};
    cout << "Length of the largest subarray with sum 0: " << sol.maxLen(arr) << endl;
    return 0;
}