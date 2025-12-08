#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> &mat)
    {
        int maxcount = 0;
        int rowindex = -1;
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 1)
                {
                    count++;
                }
            }
            if (count > maxcount)
            {
                maxcount = count;
                rowindex = i;
            }
        }
        return rowindex;
    }
};

class SolutionOptimized
{
public:
    int rowWithMax1s(vector<vector<int>> &mat)
    {
        int highestnumbnerof1s = 0;
        int rowindex = -1;
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < n; i++)
        {
            int left = 0;
            int right = m - 1;
            int firstoneindex = -1;
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (mat[i][mid] == 1)
                {
                    firstoneindex = mid;
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            if (firstoneindex != -1)
            {
                int numberof1s = m - firstoneindex;
                if (numberof1s > highestnumbnerof1s)
                {
                    highestnumbnerof1s = numberof1s;
                    rowindex = i;
                }
            }
        }
        return rowindex;
    }
};

int main()
{
    SolutionOptimized sol;
    vector<vector<int>> mat = {
        {0, 0, 0, 1},
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0}};
    int result = sol.rowWithMax1s(mat);
    cout << "Row with maximum 1's: " << result << endl;
    return 0;
}