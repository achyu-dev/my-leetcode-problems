#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= k)
            {
                k++;
            }
            else
            {
                break;
            }
        }
        return k;
    }
};

class SolutionOptimal
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int left = 0, right = arr.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] - (mid + 1) < k) // missing numbers till arr[mid] is less than k
            {
                left = mid + 1;
            }
            else // missing numbers till arr[mid] is greater than or equal to k
            {
                right = mid - 1;
            }
        }
        return left + k;
    }
};

int main()
{
    SolutionOptimal sol;
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    cout << sol.findKthPositive(arr, k) << endl;
    return 0;
}