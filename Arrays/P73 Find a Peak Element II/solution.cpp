#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low = 0;
        int high = mat.size() - 1;
        int m = mat.size();
        int cols = mat[0].size();
        int peakRow = -1;
        int peakCol = -1;

        while (low <= high) {
            int midRow = low + (high - low) / 2;

            // Find the column index of the maximum element in the midRow
            int maxColIndex = 0;
            for (int j = 1; j < cols; ++j) {
                if (mat[midRow][j] > mat[midRow][maxColIndex]) {
                    maxColIndex = j;
                }
            }

            bool isPeak = true;
            // Check the upper neighbor
            if (midRow > 0 && mat[midRow - 1][maxColIndex] >= mat[midRow][maxColIndex]) {
                isPeak = false;
                high = midRow - 1; // Move search to upper half
            }
            // Check the lower neighbor
            else if (midRow < m - 1 && mat[midRow + 1][maxColIndex] >= mat[midRow][maxColIndex]) {
                isPeak = false;
                low = midRow + 1; // Move search to lower half
            }

            if (isPeak) {
                peakRow = midRow;
                peakCol = maxColIndex;
                break; // Found a peak
            }
        }
        return {peakRow, peakCol};
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {1, 4},
        {3, 2}
    };
    vector<int> peak = sol.findPeakGrid(mat);
    cout << "Peak element found at: (" << peak[0] << ", " << peak[1] << ")" << endl;
    return 0;
}