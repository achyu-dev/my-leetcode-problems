#include <bits/stdc++.h>
using namespace std;

class SolutionBrute {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        for (int i = 0; i < n; i += 2) {
            if (i == n - 1 || nums[i] != nums[i + 1]) {
                return nums[i];
            }
        }
        return -1;
    }
};

class SolutionOptimal { // TC O(log n), SC O(1)
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mid % 2 == 1) mid--;
            if (nums[mid] == nums[mid + 1]) {
                left = mid + 2;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};

int main() {
    SolutionOptimal sol;
    vector<int> nums = {1,1,2,3,3,4,4,8,8};
    cout << sol.singleNonDuplicate(nums) << endl; 
    return 0;
}