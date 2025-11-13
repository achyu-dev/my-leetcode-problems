#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool zeroinFirstCol = false;
        for (int row = 0; row < matrix.size(); row++) {
            if (matrix[row][0] == 0) zeroinFirstCol = true;
            for (int col = 1; col < matrix[0].size(); col++) {
                if (matrix[row][col] == 0) {
                    matrix[row][0] = 0;
                    matrix[0][col] = 0;
                }
            }
        }

        for (int row = matrix.size() - 1; row >= 0; row--) {
            for (int col = matrix[0].size() - 1; col >= 1; col--) {
                if (matrix[row][0] == 0 || matrix[0][col] == 0) {
                    matrix[row][col] = 0;
                }
            }
            if (zeroinFirstCol) {
                matrix[row][0] = 0;
            }
        }
    }
};


int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    sol.setZeroes(matrix);
    for (const auto& row : matrix) {
        for (const auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}