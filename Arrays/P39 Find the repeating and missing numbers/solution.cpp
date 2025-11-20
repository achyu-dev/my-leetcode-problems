#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        int n = nums.size();
        for (int i = 0 ; i < n ; i++) {
            // find the XOR of all the array elements and the numbers between 1 to N
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0) {
                // if the number at that index is negative then it is the repeating number
                int repeating = abs(nums[i]);
                int missing = -1;
                // find the missing number
                for (int j = 0 ; j < n ; j++) {
                    if (nums[j] > 0) {
                        missing = j + 1;
                        break;
                    }
                }
                return {repeating, missing};
            } else {
                // mark the number at that index as negative
                nums[index] = -nums[index];
            }
        }
        return {-1, -1};
    }
};




int main() {
    Solution sol;
    vector<int> nums = {3,5,4,1,1};
    vector<int> result = sol.findMissingRepeatingNumbers(nums);
    cout << "Repeating Number: " << result[0] << ", Missing Number: " << result[1] << endl;
    return 0;
}