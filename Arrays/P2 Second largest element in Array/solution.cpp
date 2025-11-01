#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
    
    int n = nums.size();
    int largest = -1, secondLargest = -1;

    // finding the second largest element
    for (int i = 0; i < n; i++) {
        if(nums[i] > largest) {
        	secondLargest = largest;
            largest = nums[i];
        }
        // If nums[i] < largest and nums[i] > second largest,
        // update second largest with nums[i]
      	else if(nums[i] < largest && nums[i] > secondLargest) {
        	secondLargest = nums[i];
        }
    }
    return secondLargest;
      
    }
};

int main() {
    Solution sol;
    vector<int> nums = {12, 35, 1, 10, 344, 1};
    int result = sol.secondLargestElement(nums);
    cout << "The second largest element is: " << result << endl;
    return 0;
}