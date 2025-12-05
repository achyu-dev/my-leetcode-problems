#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long double minimiseMaxDistance(vector<int> &arr, int k)
    {
        int howmany = arr.size() - 1;
        int n = arr.size();
        // for loop to pick k gas stations one at a time.
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int dist = arr[j] - arr[i];
                int stations = dist / (k + 1);
                int rem = dist % (k + 1);
                if (rem != 0)
                    stations++;
                howmany += stations - 1;
            }
        }
        return (long double)(arr[n - 1] - arr[0]) / howmany;
    }
};


class SolutionOptimal
{
public:
    long double minimiseMaxDistance(vector<int> &arr, int k)
    {
        int n = arr.size();
        int low = 0, high = arr[n - 1] - arr[0];
        long double ans = high;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int requiredStations = 0;
            for (int i = 0; i < n - 1; i++)
            {
                int dist = arr[i + 1] - arr[i];
                requiredStations += dist / mid;
                if (dist % mid == 0)
                    requiredStations--;
            }
            if (requiredStations > k)
            {
                low = mid + 1;
            }
            else
            {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};

int main()
{
    SolutionOptimal sol;
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    cout << sol.minimiseMaxDistance(arr, k) << endl;
    return 0;
}