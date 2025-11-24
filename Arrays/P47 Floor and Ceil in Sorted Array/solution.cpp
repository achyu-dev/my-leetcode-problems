#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x)
    {
        int n = nums.size();
        int floor = -1, ceil = -1;
        int left = 0, right = n - 1;

        // Finding floor
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == x)
            {
                floor = nums[mid];
                break;
            }
            else if (nums[mid] < x)
            {
                floor = nums[mid];
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        
        // Finding ceil
        left = 0, right = n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == x)
            {
                ceil = nums[mid];
                break;
            }
            else if (nums[mid] < x)
            {
                left = mid + 1;
            }
            else
            {
                ceil = nums[mid];
                right = mid - 1;
            }
        }
        return {floor, ceil};
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 4, 4, 7, 8, 10};
    int x = 5;
    vector<int> result = sol.getFloorAndCeil(nums, x);
    cout << "Floor: " << result[0] << ", Ceil: " << result[1] << endl;
    return 0;
}