#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int profit = 0;
        int n = prices.size();
        for (int i = 1; i < n; i++) {
            if (prices[i] < buy) { // found a new minimum buying price
                buy = prices[i];
            } else if (prices[i] - buy > profit) { // found a better selling price
                profit = prices[i] - buy; // update maximum profit
            }
        }
        return profit;
    }
};
// TC -> O(N)
// SC -> O(1)

int main() {
    Solution sol;
    vector<int> prices = {3,8,1,4,6,2};
    cout << sol.maxProfit(prices) << endl; // Output: 5
    return 0;
}