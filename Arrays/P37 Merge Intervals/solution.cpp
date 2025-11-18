#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        int n = intervals.size();
        for (int i = 0; i < n; ++i)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];

            int j = i + 1;
            while (j < n && intervals[j][0] <= end)
            {
                end = max(end, intervals[j][1]);
                ++j;
            }

            merged.push_back({start, end});
            i = j - 1;
        }
        return merged;
    }
};

class SolutionOptmal
{ // TC - O(nlogn) + O(n) , SC - O(n)
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());

        // Vector to store final merged intervals
        vector<vector<int>> merged;

        // Traverse each interval
        for (auto interval : intervals)
        {
            // If merged is empty or current interval does not overlap
            if (merged.empty() || merged.back()[1] < interval[0])
            {
                // Add current interval as a new non-overlapping block
                merged.push_back(interval);
            }
            else
            {
                // Overlapping: merge by extending the end time
                merged.back()[1] = max(
                    merged.back()[1],
                    interval[1]);
            }
        }

        return merged;
    }
};

int main()
{
    SolutionOptmal sol;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> merged = sol.merge(intervals);
    for (const auto &interval : merged)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
    return 0;
}