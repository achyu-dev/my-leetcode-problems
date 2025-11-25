#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countOccurrences(const vector<int>& arr, int target) {
        int cnt = 0;
        for (int num : arr) {
            if (num == target) {
                cnt++;
            }
        }
        return cnt;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {2, 4, 6, 8, 10};
    int target = 3;
    int result = sol.countOccurrences(arr, target);
    cout << "The number " << target << " occurs " << result << " times in the array." << endl;
    return 0;
}