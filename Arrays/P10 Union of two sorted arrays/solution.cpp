#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        set<int> s; // to store unique elements
        for (int i : nums1) s.insert(i);
        for (int i : nums2) s.insert(i);
        return vector<int>(s.begin(), s.end());
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    vector<int> nums1 = {3, 4, 4, 4};
    vector<int> nums2 = {6, 7, 7};
    vector<int> result = sol.unionArray(nums1, nums2);

    for (int num : result) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}