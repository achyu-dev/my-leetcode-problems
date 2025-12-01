#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);

        while (left < right) {
            int mid = left + (right - left) / 2;
            int requiredDays = 1;
            int currentLoad = 0;

            for (int weight : weights) {
                if (currentLoad + weight > mid) {
                    requiredDays++;
                    currentLoad = 0;
                }
                currentLoad += weight;
            }

            if (requiredDays > days) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }
};

int main() {
    Solution sol;
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;
    cout << sol.shipWithinDays(weights, days) << endl;
    return 0;
}