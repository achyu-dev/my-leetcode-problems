#include <bits/stdc++.h>
using namespace std;


// TC: O(N**2) SC: O(N)
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos;
        vector<int> neg;
        
        for (int i = 0 ; i < n ; i++) {
            if (nums[i] >= 0) {
                pos.push_back(nums[i]);
            } else {
                neg.push_back(nums[i]);
            }
        }

        for (int i = 0 ; i < n / 2 ; i++) {
            nums[2 * i] = pos[i];
            nums[2 * i + 1] = neg[i];
        }

        return nums;
    }
};

class Solution2 {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int posIndex = 0;
        int negIndex = 1;

        for (int i = 0 ; i < n ; i++) {
            if (nums[i] >= 0) {
                result[posIndex] = nums[i];
                posIndex += 2;
            } else {
                result[negIndex] = nums[i];
                negIndex += 2;
            }
        }

        return result;
    }
};




int main() {
    Solution2 sol;
    vector<int> nums = {3, -2, 1, -5, 4, -6};
    vector<int> result = sol.rearrangeArray(nums);
    
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}