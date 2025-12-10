#include <bits/stdc++.h>
using namespace std;

class SolutionBruteForce
{
public:
    int findMedian(vector<vector<int>> &matrix)
    {
        vector<int> elements;

        for (const auto &row : matrix)
        {
            for (const auto &num : row)
            {
                elements.push_back(num);
            }
        }
        sort(elements.begin(), elements.end());
        int n = elements.size();
        return elements[n / 2];
    }
};

class SolutionBinarySearch
{
public:
    int countLessEqual(const vector<vector<int>> &matrix, int mid)
    {
        int count = 0;
        for (const auto &row : matrix)
        {
            count += upper_bound(row.begin(), row.end(), mid) - row.begin();
        }
        return count;
    }

    int findMedian(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int low = INT_MAX;
        int high = INT_MIN;

        for (const auto &row : matrix)
        {
            low = min(low, row[0]);
            high = max(high, row[cols - 1]);
        }

        int desiredCount = (rows * cols + 1) / 2;

        while (low < high)
        {
            int mid = low + (high - low) / 2;
            int count = countLessEqual(matrix, mid);

            if (count < desiredCount)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return low;
    }
};

int main()
{
    SolutionBinarySearch sol;
    vector<vector<int>> matrix = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}};
    cout << "Median: " << sol.findMedian(matrix) << endl;
    return 0;
}