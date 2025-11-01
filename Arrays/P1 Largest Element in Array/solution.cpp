#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int largestElement(vector<int>& nums) {
        int lar = nums[0]; //create a variable to store the maximum element.
        int n = nums.size();
        for (int i = 0 ; i < n ; i++) { //traverse through the array.
            if (nums[i] > lar) { //compare each element with the maximum element.
                lar = nums[i]; // update the maximum element if the current element is greater.
            }
        }

        return lar; //return the maximum element.
    }
};

// Example
int main() {
    Solution sol;
    vector<int> nums = {123, 21215, 122, 99, 12121122};
    cout << "The largest element in the array is: " << sol.largestElement(nums) << endl;
    return 0;
}