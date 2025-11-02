#include<bits/stdc++.h>
using namespace std;

// not an in-place solution, uses extra space, O(n) time and O(n) space
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> s;
        // we store all unique elements in the set
        int idx = 0;
        for (int num: nums) {
            if (s.find(num) == s.end()) {
                s.insert(num);
                nums[idx++] = num;
            }
        }
        return idx;
    }
};


// using two pointers, in-place solution, O(n) time and O(1) space
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            // if current element is different from the last unique element
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};

int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    Solution sol;
    int k = sol.removeDuplicates(nums);

    cout << "Unique count = " << k << "\n";
    cout << "Array after removing duplicates: ";
    for (int x = 0; x < k; x++) {
        cout << nums[x] << " ";
    }
    cout << endl;
}