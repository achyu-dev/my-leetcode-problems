#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxc = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;
                maxc = max(maxc, count);
            } else {
                count = 0;
            }
        }
        
        return maxc;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {1,1,1,1,1,1,1,0,1,1,1};
    vector<int> nums2 = {1,0,1,1,0,1};
    
    cout << sol.findMaxConsecutiveOnes(nums1) << endl;
    cout << sol.findMaxConsecutiveOnes(nums2) << endl;
    
    return 0;
}