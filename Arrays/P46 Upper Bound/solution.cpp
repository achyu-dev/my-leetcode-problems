#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int upperBound(vector<int> &nums, int x){
        int left = 0, right = nums.size() - 1;
        int ans = nums.size();
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] > x){
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1, 2, 2, 3};
    int x = 2;
    Solution sol;
    cout << sol.upperBound(nums, x) << endl;
}