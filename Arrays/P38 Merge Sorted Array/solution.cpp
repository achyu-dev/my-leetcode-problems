#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //last index num1
        int last = m + n - 1;

        //merge in reverse order
        while (m > 0 && n > 0){
            if (nums1[m - 1] > nums2[n - 1]){
                nums1[last] = nums1[m - 1]; // place larger ele at the end
                m -= 1; // reduce size of nums1
            }
            else {
                nums1[last] = nums2[n - 1]; // place larger ele at the end
                n -= 1; // reduce size of nums2
            }

            last -= 1;
        }

        //Fill nums1 with leftover nums2 eles
        while (n > 0) {
            nums1[last] = nums2[n - 1];
            n = n - 1;
            last = last - 1;
        }

        //return nums1;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m = 3;
    int n = 3;

    sol.merge(nums1, m, nums2, n);

    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}